#include "game.h"

Game::Game()
{
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    flappy = new Bird(screen);
    pipe_down = new Pipe(screen, DOWN);
    pipe_up = new Pipe(screen, UP);
    blit_pos.x = 0; blit_pos.y = 0;
    blit_pos.h = HEIGHT; blit_pos.w = WIDTH;
    bg = IMG_Load("./images/bg.bmp");
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
         pipe_down->update();
         pipe_up->update();
         this->show();
         flappy->show();
         pipe_down->show();
         pipe_up->show();
         SDL_Flip(screen);
         SDL_Delay(30);
    }
}

void Game::update()
{
    SDL_Rect flappy_pos = flappy->get_pos(),
             piped_pos = pipe_down->get_pos(),
             pipeu_pos = pipe_up->get_pos();
//    if (flappy_pos.x + flappy_pos.w > piped_pos.x &&
//        flappy_pos.x < piped_pos.x + piped_pos.w &&
//        flappy_pos.y < piped_pos. y + piped_pos.h &&
//        flappy_pos.y > piped_pos.y)
//        SDL_Delay(10000);
}
