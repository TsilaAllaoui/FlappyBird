#pragma once

#include <SDL/SDL.h>

class Timer
{
	private:
	    float start_time, stop_time;
	    bool state;
	public:
	    Timer();
	    void start();
	    void stop();
	    void reset(float t);
	    float get_time();
	    bool get_state();
};

