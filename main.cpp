#include "game.h"
#include <SDL/SDL.h>

int main(int argc , char *argv[])
{
    Game().play();
    SDL_Delay(500000);
}