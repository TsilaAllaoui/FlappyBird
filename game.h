#include "defs.h"
#include "bird.h"

class Game
{
    private:
        SDL_Surface *screen, *bg;
        Bird *flappy;
    public:
        Game();
        void show();
        void play();
        void update();
        ~Game();
};