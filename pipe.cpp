#include "pipe.h"

Pipe::Pipe(SDL_Surface *pscreen,int ptype)
{
	type = ptype;
	if (type == UP)
		sprite = IMG_Load("./images/pipe_up.bmp");
	else if (type == DOWN)
		sprite = IMG_Load("./images/pipe_down.bmp");
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 255, 255));
	screen = pscreen;
	pos.h = 200; pos.w = 40;
	pos.x = WIDTH;
	if (type == UP)
		pos.y = 0;
	else if (type == DOWN)
		pos.y = HEIGHT - 200;
	onscreen = true;
}

Pipe::~Pipe()
{
	pos.x = -900; pos.y = -900;
	SDL_FreeSurface(sprite);
}

void Pipe::show()
{
	if (onscreen)
		SDL_BlitSurface(sprite, NULL, screen, &pos);
}

void Pipe::update()
{
	pos.x--;
	if (pos.x < -1)
		pos.x -= 50;

}

SDL_Rect Pipe::get_pos()
{
	return pos;
}
