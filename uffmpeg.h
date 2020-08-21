#ifndef UFFMPEG_H
#define UFFMPEG_H


#include <QString>
#include <iostream>
#include<WinSock.h>


extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavdevice/avdevice.h"
}

#pragma comment(lib, "ws2_32.lib")


using namespace std;


class Uffmpeg
{

public:
    Uffmpeg();
    ~Uffmpeg();
    bool OpenVideo(QString url);
    bool ReadFrame(AVPacket* pkt);
    bool DecodeVideo(AVPacket* pkt,AVFrame* frame);
    void CloseVideo();

private:
    AVFormatContext* inFormatCtx;  //输入流上下文
    AVInputFormat* inFmt;
    int videoStreamIndex;
    int audioStreamIndex;

    AVCodecContext *deCodecCtx;  //解码器上下文
    AVCodec *deCodec;            //解码器


     int srcWidth ;
      int srcHeight ;
};

#endif // UFFMPEG_H
