#include "bird.h"

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
}

Bird::~Bird()
{
	SDL_FreeSurface(sprite);
}

void Bird::show()
{
	if (anim_state == 0)
		blitpos.y = 0;
	else blitpos.y = 24;
	SDL_BlitSurface(sprite, &blitpos, screen, &pos);
}

void Bird::move()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (flap_timer.get_state() && flap_timer.get_time() >= 200)
	flap_timer.stop();
	if (event.type == SDL_KEYDOWN)
	{
		if(!flap_timer.get_state())
			flap_timer.start();
		if (flap_timer.get_state() && flap_timer.get_time() < 200)
			{
				velocity_y -= GRAVITY*1.75;
				anim_state = 1;
				anim_timer.start();
			}
	}
	if (anim_timer.get_time() > 300)
		anim_state = 0;
	pos.y += GRAVITY + velocity_y;
	if (velocity_y < 0)
	velocity_y++;
}
