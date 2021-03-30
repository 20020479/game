


#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_


#include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<string>
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;
const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 255;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_even;

namespace SDL_CF
{

    SDL_Surface* LoadImage(std::string file_path);
void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
void CleanUp();
}

typedef struct input
{
    int left_;
    int right_;
    int up_;
    int down_;

};


#endif
