#include "bird.h"
#include "SDL_rotozoom.h"

Bird::Bird(SDL_Surface * pscreen)
{
	screen = pscreen;
	sprite = IMG_Load("./images/bird.bmp");
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 174, 201));
	pos.x = 50;
	pos.y = 50;
	blitpos.x = 0;
	blitpos.y = 0;
	blitpos.h = 24;
	blitpos.w = 34;
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
	else
		blitpos.y = 24;
	SDL_Surface *rotation;
	rotation = rotozoomSurface(sprite, 1, 1,1);
	vit++;
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
			anim_state = 1;
			anim_timer.start();
		}
	}
	if (anim_timer.get_time() > 10)
		anim_state = 0;
	pos.y += GRAVITY + velocity_y;
	if (velocity_y < 0)
		velocity_y++;
}

SDL_Rect Bird::get_pos()
{
	return pos;
}
