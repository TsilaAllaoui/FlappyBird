#pragma once
#include "defs.h"

class Pipe
{
	private:
	   SDL_Surface *sprite, *screen;
	   SDL_Rect pos;
	   bool onscreen;
	   int type;
	public:
	   Pipe(SDL_Surface *pscreen,int type);
	   ~Pipe();
	   void show();
	   void update();
	   SDL_Rect get_pos();
};
