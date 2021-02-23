#pragma once
#include "defs.h"

class Bird
{
    private:
        SDL_Surface *sprite, *screen;
        SDL_Rect pos, blitpos;
        float velocity_y, vit;
        int anim_state;
        Timer flap_timer, anim_timer;
    public:
        Bird(SDL_Surface *pscreen);
        void show();
        void show_start_screen();
        void move();
        SDL_Rect get_pos();
        void set_xy(int x, int y);
        ~Bird();
};
