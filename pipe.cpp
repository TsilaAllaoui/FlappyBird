#include "pipe.h"

Pipe::Pipe(SDL_Surface * pscreen, int ptype)
{
	type = ptype;
	if (type == UP)
		sprite = IMG_Load("./images/pipe_up.bmp");
	else if (type == DOWN)
		sprite = IMG_Load("./images/pipe_down.bmp");
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 255, 255));
	screen = pscreen;
	pos.x = WIDTH;
	if (type == UP)
		pos.y = -100;
	else if (type == DOWN)
		pos.y = HEIGHT - 180;
	onscreen = true;
	first = true;
	pos.h = 300; pos.w = 36;
}

Pipe::~Pipe()
{
	pos.x = -900;
	pos.y = -900;
	SDL_FreeSurface(sprite);
}

void Pipe::show()
{
	SDL_Rect tmp = pos;
	if (onscreen)
		SDL_BlitSurface(sprite, NULL, screen, &tmp);
}

void Pipe::update()
{
	pos.x--;
	if (pos.x < -40)
		onscreen = false;
}

SDL_Rect Pipe::get_pos()
{
	return pos;
}

void Pipe::set_xy(int x, int y)
{
	pos.x = x; pos.y = y;
}

bool Pipe::get_status()
{
	return onscreen;
}

void Pipe::set_status(bool value)
{
	onscreen = value;
}
