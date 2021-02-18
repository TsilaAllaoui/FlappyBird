#pragma once
#include "defs.h"

class Pipe
{
	private:
	   SDL_Surface *sprite, *screen;
	   SDL_Rect pos, blit_pos;
	   bool onscreen;
	public:
	   Pipe(SDL_Surface *pscreen);
	   ~Pipe();
	   void show();
	   void update();
};