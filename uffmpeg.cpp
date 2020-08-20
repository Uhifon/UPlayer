#include "uffmpeg.h"

Uffmpeg::Uffmpeg()
{
    av_register_all();
    avformat_network_init();
}

Uffmpeg::~Uffmpeg()
{

}

//打开视频
bool Uffmpeg::OpenVideo(QString url)
{
    inFormatCtx = avformat_alloc_context();
    AVDictionary* options = NULL;
    av_dict_set(&options, "rtsp_transport", "tcp", 0);    //采用tcp传输
    av_dict_set(&options, "stimeout", "2000000", 0);  //如果没有设置stimeout，那么把ipc网线拔掉，av_read_frame会阻塞（时间单位是微妙）
    //打开流
    int ret = avformat_open_input(&inFormatCtx,url.toLocal8Bit().data(),inFmt,&options);
    if(ret < 0)
    {
        printf("%s","can't open input video\n");
        return false;
    }
    //获取视频信息
    ret =   avformat_find_stream_info(inFormatCtx,NULL);
    if(ret < 0)
    {
        printf("%s","can't find stream info\n");
        return false;
    }

    //找到流
    videoStreamIndex = av_find_best_stream(inFormatCtx, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    audioStreamIndex = av_find_best_stream(inFormatCtx, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);

    //找到合适的解码器
    deCodecCtx = inFormatCtx->streams[videoStreamIndex]->codec;
    deCodec= avcodec_find_decoder(deCodecCtx->codec_id);
    if (deCodec == NULL)
    {
        printf("%s","can't find decoder");
        return false;
    }

    //打开解码器
    if (avcodec_open2(deCodecCtx,deCodec,NULL)<0)
    {
        printf("%s","can't open decodec\n");
        return false;
    }
    return true;
}

//获取流
bool Uffmpeg::ReadFrame(AVPacket* pkt)
{
    int ret = av_read_frame(inFormatCtx,pkt);
    if(ret==0)
        return true;
    else
    {
        printf("%s","read frame fail\n");
        return false;
    }
}

//解码视频
bool Uffmpeg::DecodeVideo(AVPacket* pkt,AVFrame* frame)
{
    int ret = 0;
    ret = avcodec_send_packet(deCodecCtx,pkt);
    if(ret<0)
    {
        printf("%s","send packet fail\n");
        av_free_packet(pkt);
        return false;
    }
    ret = avcodec_receive_frame(deCodecCtx,frame);
    if(ret<0)
    {
        printf("%s","receive frame fail\n");
    }
    av_free_packet(pkt);
    return true;
}


//关闭视频 释放资源
void Uffmpeg::CloseVideo()
{
    avformat_close_input(&inFormatCtx);
    avcodec_close(deCodecCtx);
    av_free(deCodec);

}

