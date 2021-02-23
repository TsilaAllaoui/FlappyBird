#pragma once
#include "defs.h"

class Pipe
{
	private:
	   SDL_Surface *sprite, *screen;
	   SDL_Rect pos;
	   bool onscreen, first;
	   int type, xpos, ypos;
	public:
	   Pipe(SDL_Surface *pscreen,int type);
	   ~Pipe();
	   void show();
	   void update();
	   SDL_Rect get_pos();
	   void set_status(bool value);
	   void set_xy(int x, int y);
	   bool get_status();
};
