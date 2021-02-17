#include "bird.h"

Bird::Bird(SDL_Surface * pscreen)
{
	screen = pscreen;
	sprite = IMG_Load("./images/bird.bmp");
	if (!sprite)
		exit(16);
	pos.x = 50;
	pos.y = 50;
	velocity_y = 0;
}

Bird::~Bird()
{
	SDL_FreeSurface(sprite);
}

void Bird::show()
{
	SDL_BlitSurface(sprite, NULL, screen, &pos);
}

void Bird::move()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
	    velocity_y -= 2*GRAVITY;
	pos.y += GRAVITY + velocity_y;
	if (velocity_y < 0)
	velocity_y++;
}
