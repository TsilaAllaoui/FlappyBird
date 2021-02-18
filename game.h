#pragma once
#include "defs.h"
#include "bird.h"
#include "pipe.h"

class Game
{
    private:
        SDL_Surface *screen, *bg;
        Bird *flappy;
        Pipe *pipe;
    public:
        Game();
        void show();
        void play();
        void update();
        ~Game();
};