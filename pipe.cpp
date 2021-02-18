#include "pipe.h"

Pipe::Pipe(SDL_Surface *pscreen)
{
	sprite = IMG_Load("./images/pipe.bmp");
	screen = pscreen;
	pos.h = 20; pos.w = 40;
	pos.x = WIDTH; pos.y = 0;
	blit_pos.h = 20; blit_pos.w = 40;
	onscreen = true;
}

Pipe::~Pipe()
{
	SDL_FreeSurface(sprite);
}

void Pipe::show()
{
	if (onscreen)
	SDL_BlitSurface(sprite, &blit_pos, screen, &pos);
}

void Pipe::update()
{
	if (pos.x + pos.w < 0)
	    onscreen = false;
	pos.x --;
}
