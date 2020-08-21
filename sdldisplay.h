#ifndef SDLDISPLAY_H
#define SDLDISPLAY_H

#include <SDL.h>
#include "stdio.h"
extern "C"
{
#include <libavutil/frame.h>
}

using namespace std;

class SDLDisplay
{
public:
    SDLDisplay();
    ~SDLDisplay();
    int InitSDLWindow(int width, int height, const void* data);
    int ResizeWindow(const void* data);
    int UpdateSDLWindowYUV(AVFrame* frame,int width, int height);
    int UpdateSDLWindowRGB(AVFrame* frame, int width, int height);
    void CloseSDL();
private:
    int widthTemp;
    int HeightTemp;
    const void* hwndTemp;

    SDL_Window* screen;
    SDL_Renderer* sdlRenderer ;
    SDL_Texture* sdlTexture ;
    SDL_mutex* mux ;
};
#endif // SDLDISPLAY_H
