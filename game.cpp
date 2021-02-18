#include "game.h"

Game::Game()
{
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    flappy = new Bird(screen);
    pipe = new Pipe(screen);
    bg = IMG_Load("./images/bg.bmp");
}

Game::~Game()
{
    SDL_FreeSurface(screen);
}

void Game::show()
{
    SDL_BlitSurface(bg,NULL,screen,NULL);
}

void Game::play()
{
    while (true)
    {
         flappy->move();
         pipe->update();
         this->show();
         flappy->show();
         pipe->show();
         SDL_Flip(screen);
         SDL_Delay(30);
    }
}
