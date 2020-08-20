#ifndef PLAY_H
#define PLAY_H
#include "stdio.h"
#include <uffmpeg.h>
#include <sdldisplay.h>
#include <QList>
#include <QString>

using namespace std;

class Play
{
public:
    Play();
     ~Play();
     Play(void* HWD,QString URL);
     void Start();
//    static int DecodeThread(void *param);
//    static int ShowThread(void *param);

public:
    Uffmpeg* ffmpeg;
    SDLDisplay* display;
    QList<AVFrame*> frameList;
    void* hwd;
    QString url;

};

#endif // PLAY_H
