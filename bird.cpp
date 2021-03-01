#include "bird.h"
#include "SDL_rotozoom.h"

Bird::Bird(SDL_Surface * pscreen)
{
    screen = pscreen;
    sprite = IMG_Load("./images/bird.bmp");
    SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 174, 201));
    pos.x = pos.y = 50;
    blitpos.x = blitpos.y = 0;
    blitpos.h = pos.h = 24;
    blitpos.w = pos.w = 34;
    velocity_y = 0;
    anim_state = 0;
    vit = 0;
}

Bird::~Bird()
{
    SDL_FreeSurface(sprite);
}

void Bird::show()
{
    if (anim_state == 0)
        blitpos.y = 0;
    else if (anim_state == 1)
        blitpos.y = 24;
    else
        blitpos.y = 48;
    SDL_Surface *rotation;
    rotation = rotozoomSurface(sprite, 1, 1,1);
    vit++;
    SDL_BlitSurface(sprite, &blitpos, screen, &pos);
}

void Bird::show_start_screen()
{
    if (!anim_timer.get_state())
        anim_timer.start();
	else
	{
		if (anim_timer.get_time() > 75)
		{
			if (anim_state < 2)
				anim_state++;
			else
				anim_state = 0;
			anim_timer.stop();
			if (anim_state == 1 && anim_state != 2)
				pos.y-=5;
			else if (anim_state == 0 && anim_state != 2)
				pos.y+=5;
		}
	}
    if (anim_state == 0)
        blitpos.y = 0;
    else if (anim_state == 1)
        blitpos.y = 24;
    else
        blitpos.y = 48;
    SDL_BlitSurface(sprite, &blitpos, screen, &pos);
}

void Bird::move()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_ESCAPE)
            exit(EXIT_SUCCESS);
        else
        {
            velocity_y -= GRAVITY * 1.75;
            anim_timer.start();
        }
    }
    if (anim_timer.get_time() < 100)
    {
        if (anim_state < 2)
            anim_state++;
        else
            anim_state = 0;
    }
    else
        anim_state = 0;
    pos.y += GRAVITY + velocity_y;
    if (velocity_y < 0)
        velocity_y++;
}

SDL_Rect Bird::get_pos()
{
    return pos;
}

void Bird::set_xy(int x, int y)
{
    pos.x = x;
    pos.y = y;
}
