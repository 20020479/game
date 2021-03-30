#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_
#include"CommonFunction.h"
#include"BaseObject.h"
class MainObject: public BaseObject
{
public:
    MainObject();
    ~MainObject();

bool LoadImage (std:: string path,SDL_Renderer* screen);
void show(SDL_Renderer* des);
void HandleInputAction(SDL_Event events, SDL_Renderer* g_screen);//xu li su kien
void set_clips();       //hieu ung animation
private:
    float x_val_;//an phai trai tang bao nhieu
    float y_val_;//an len xuong tang bn

    float x_pos_;//vi tri hien tai
    float y_pos_;// vi tri hien tai

    int width_frame_;//kich thuoc
    int height_frame_;//kich thuoc

    SDL_Rect frame_clip_[8];

    input input_type;//bien luu trang thai
    int frame_;

    SDL_Rect frame_clip[0];



};

#endif // MAIN_OBJECT_
