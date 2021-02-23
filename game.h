#pragma once
#include "defs.h"
#include "bird.h"
#include "pipe.h"

class Game
{
    private:
        SDL_Surface *screen, *bg, *score;
        SDL_Rect blit_pos, scoreblit;
        Bird *flappy;
        Pipe *pipe_down, *pipe_up;
        char counter[100] = "";
        int curr_count;
        bool running;
    public:
        Game();
        void show();
        void showUI();
        void play();
        void update();
        bool check_collision(SDL_Rect box1, SDL_Rect box2);
        void menu_display();
        ~Game();
};
