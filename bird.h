#include "defs.h"

class Bird
{
    private:
        SDL_Surface *sprite, *screen;
        SDL_Rect pos, blitpos;
        float velocity_y;
        int anim_state;
        Timer flap_timer, anim_timer;
    public:
        Bird(SDL_Surface *pscreen);
        void show();
        void move();
        ~Bird();
};
