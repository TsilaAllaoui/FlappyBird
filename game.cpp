#include "game.h"

Game::Game()
{
    srand(time(0));
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    TTF_Init();
    flappy = new Bird(screen);
    pipe_down = new Pipe(screen, DOWN);
    pipe_up = new Pipe(screen, UP);
    blit_pos.x = 0;
    blit_pos.y = 0;
    blit_pos.h = HEIGHT;
    blit_pos.w = WIDTH;
    bg = IMG_Load("./images/bg.bmp");
    score = IMG_Load("./images/score.bmp");
    scoreblit.h = scoreblit.w = 36;
    scoreblit.y = 0;
    scoreblit.x = WIDTH/2 - 18;
    curr_count = 0;
    running = true;
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
        this->menu_display();
        while (running)
        {
            flappy->move();
            this->update();
            this->show();
            flappy->show();
            pipe_down->show();
            pipe_up->show();
            showUI();
            SDL_BlitSurface(score,&scoreblit, screen, NULL);
            SDL_Flip(screen);
            SDL_Delay(30);
        }
    }
}

void Game::update()
{
    SDL_Rect birdpos = flappy->get_pos(), pipeuppos =  pipe_up->get_pos(),
             pipedownpos = pipe_down->get_pos();
    //updating pipes positions
    pipe_up->update();
    pipe_down->update();
    if (!pipe_up->get_status())
    {
        pipe_up->set_status(true);
        pipe_down->set_status(true);
        pipe_up->set_xy(WIDTH, rand()%201 - 200);
        pipe_down->set_xy(WIDTH,pipe_up->get_pos().y + 380);
    }
    //updating bird posiition and score
    if (birdpos.x == pipeuppos.x + 36)
        curr_count++;
    //collision tests
    if (check_collision(birdpos, pipeuppos) || check_collision(birdpos, pipedownpos)
        || (birdpos.y >= HEIGHT - 80))
    {
       running = false;
       pipe_down->~Pipe();
       pipe_up->~Pipe();
       curr_count = 0;
    }
}

bool Game::check_collision(SDL_Rect box1, SDL_Rect box2)
{
    if ((box2.x >= box1.x + box1.w)
            || (box2.x + box2.w <= box1.x)
            || (box2.y >= box1.y + box1.h) || (box2.y + box2.h <= box1.y))
        return false;
    else
        return true;
}

void Game::showUI()
{
    TTF_Font *police = TTF_OpenFont("./fonts/8bitsFont.ttf", 50);
    SDL_Color white = {255,255,255};
    sprintf(counter, "%d",curr_count);
    score = TTF_RenderText_Solid(police,counter,white);
    SDL_BlitSurface(score,NULL,screen,&scoreblit);
}

void Game::menu_display()
{
    flappy = new Bird(screen);
    SDL_Surface *key = IMG_Load("./images/key.bmp"), *title = IMG_Load("./images/title.bmp");
    SDL_SetColorKey(title, SDL_SRCCOLORKEY, SDL_MapRGB(title->format, 255, 174, 201));
    SDL_Rect rect = {66,322,0,0}, blit = {0,0,99,14};
    flappy->set_xy(50, HEIGHT/2 - flappy->get_pos().h / 2);
    Timer timer;
    while (true)
    {
        if (!timer.get_state())
            timer.start();
        if (timer.get_time() > 250)
        {
            if (blit.y < 28)
            blit.y  += 14;
            else blit.y = 0;
            timer.stop();
        }
        this->show();
        flappy->show_start_screen();
        SDL_BlitSurface(title, NULL, screen , NULL);
        SDL_BlitSurface(key, &blit, screen, &rect);
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
                exit(0);
            pipe_down = new Pipe(screen, DOWN);
            pipe_up = new Pipe(screen, UP);
            running = true;
            break;
        }
        SDL_Delay(30);
        SDL_Flip(screen);
    }
}
