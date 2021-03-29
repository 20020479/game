
#include"stdarg.h"
#include"CommonFunction.h"
#include"BaseObject.h"
BaseObject g_background;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if(ret < 0)
        return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    g_window = SDL_CreateWindow("game SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window ,-1, SDL_RENDERER_ACCELERATED);
        if(g_screen == NULL)
        {
            success = false;
        }
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlat = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlat) and imgFlat))
            success = false;

        }
    }
    return success;

}
bool loadBgr()
{
    bool ret = g_background.LoadImage ("img//bg2.png", g_screen);
    if(ret == false)
        return false;
    return true;
}
void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    IMG_Quit();
    SDL_Quit();

}
int main(int argc, char* argv[])

{
     if(InitData() == false)
       return -1;
    if(loadBgr() == false)
        return -1;
    bool is_quit = false;
    while(!is_quit )
    {
       while (SDL_PollEvent(&g_even)!=0)
       {
           if(g_even.type == SDL_QUIT)
           {
               is_quit = true;
           }
       }
       SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
       SDL_RenderClear(g_screen);
       g_background.Render(g_screen, NULL);
       SDL_RenderPresent(g_screen);
    }
    return 0;
}
