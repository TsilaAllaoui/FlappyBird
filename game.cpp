#include "game.h"

Game::Game()
{
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    flappy = new Bird(screen);
    pipe = new Pipe(screen);
    blit_pos.x = 0; blit_pos.y = 0;
    blit_pos.h = HEIGHT; blit_pos.w = WIDTH;
    bg = IMG_Load("./images/bg.png");
}

Game::~Game()
{
    SDL_FreeSurface(screen);
}

void Game::show()
{
    blit_pos.x++;
    if (blit_pos.x >= WIDTH*2)
        blit_pos.x = 0;
    SDL_BlitSurface(bg,&blit_pos,screen,NULL);
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
