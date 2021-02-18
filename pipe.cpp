#include "pipe.h"

Pipe::Pipe(SDL_Surface *pscreen,int ptype)
{
	sprite = IMG_Load("./images/pipe.png");
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 255, 255));
	screen = pscreen;
	pos.h = 200; pos.w = 40;
	pos.x = WIDTH;
	if (type == UP)
		pos.y = 0;
	if (type == DOWN)
		pos.y = HEIGHT - 200;
	type = ptype;
	blit_pos.h = 200; blit_pos.w = 40;
	onscreen = true;
}

Pipe::~Pipe()
{
	SDL_FreeSurface(sprite);
}

void Pipe::show()
{
	if (onscreen)
	{
		if (type == DOWN)
		{
			blit_pos.x = 0;
			pos.y = HEIGHT - 200;
		}
		if (type == UP)
		{
			blit_pos.x = blit_pos.w;
			pos.y = 0;
		}
	}
	SDL_BlitSurface(sprite, &blit_pos, screen, &pos);
}

void Pipe::update()
{
	if (pos.x + pos.w < 0)
		onscreen = false;
	pos.x--;
}

SDL_Rect Pipe::get_pos()
{
	return pos;
}