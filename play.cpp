#include "play.h"
#include <QThread>

Play:: Play()
{
}
Play:: ~Play()
{
}
Play::Play(void* HWD,QString URL)
{
   this->hwd = HWD;
   this->url = URL;
   ffmpeg =new Uffmpeg();
   display= new SDLDisplay();
}

//解码视频线程
int  DecodeThread(void *param)
{
   Play* play =(Play*) param;
   bool res =false;
   res = play->ffmpeg->OpenVideo(play->url);
   if(!res)
       return -1;
    while(true)
    {
        if( play->frameList.count()>=100)
        {
            QThread::sleep(10);
            continue;
        }
        AVPacket* pkt = av_packet_alloc();
        res = play->ffmpeg->ReadFrame(pkt);
        if(!res)
        {
            av_packet_free(&pkt);
            play->ffmpeg->CloseVideo();
            break;
        }
        AVFrame* frame= av_frame_alloc();
        res =play->ffmpeg->DecodeVideo(pkt,frame);
        if(!res)
        {
            av_frame_free(&frame);
            play->ffmpeg->CloseVideo();
            break;
        }
        play->frameList.push_back(frame);

    }
  return 0;
}

//显示视频
int  ShowThread(void *param)
{
   Play* play =(Play*) param;
   play->display->InitSDLWindow(1024,768,play->hwd);
   while(true)
   {
       if(play->frameList.count()>0)
       {
            AVFrame* yuvFrame = play->frameList.front();
            play->display->UpdateSDLWindowYUV(yuvFrame,1024,768);
       }
       else
       {
           QThread::sleep(10);
       }
   }
   return 0;

}

void Play::Start()
{

//   SDL_Thread* decodeThread = SDL_CreateThread(&DecodeThread,NULL,this);
//    SDL_Thread* playThread = SDL_CreateThread(&ShowThread,NULL,this);
}



