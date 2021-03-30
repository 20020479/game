#include"MainObject.h"
#include"CommonFunction.h"
#include"stdarg.h"
MainObject::MainObject()
{
    frame_=0;
    x_pos_ = 0;
    y_pos_ = 0;
    x_val_ =0;
    y_val_ =0;
    width_frame_=0;
    height_frame_=0;
}
MainObject::~MainObject()
{

}
bool MainObject::LoadImage(std:: string path,SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImage(path,screen);
    if(ret == true)
    {
        width_frame_ = rect_.w/1;
        height_frame_ = rect_.h;
    }
    return ret;

}

void MainObject:: set_clips()
{
    if(width_frame_>0 and height_frame_>0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;


    }
}

void MainObject:: show(SDL_Renderer* des)
{
    LoadImage("img//plane.png",des);
    rect_.x = x_pos_;
    rect_.y = y_pos_;
    SDL_Rect renderQuad ={rect_.x, rect_.y, width_frame_, height_frame_};
    SDL_Rect* current_clip = &frame_clip_[0];
    SDL_RenderCopy(des, p_object_, current_clip, &renderQuad );
}


