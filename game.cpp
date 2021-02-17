#include "game.h"

Game::Game()
{
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    flappy = new Bird(screen);
    bg = IMG_Load("bg.png");
}

Game::~Game()
{
    SDL_FreeSurface(screen);
}

void Game::show()
{
    SDL_BlitSurface(bg,NULL,screen,NULL);
    SDL_Flip(screen);
}

void Game::play()
{
    SDL_Event event;
    while (true)
    {
         flappy->move();
         flappy->show();
         this->show();
         SDL_Delay(30);
    }
}