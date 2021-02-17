#include "timer.h"

Timer::Timer()
{
	start_time = 0;
	stop_time = 0;
}

void Timer::start()
{
	start_time = SDL_GetTicks();
	state = true;
}

void Timer::reset(float t)
{
	start_time = 0;
	stop_time = 0;
	state = true;
}

void Timer::stop()
{
	state = false;
	start_time = 0;
}

float Timer::get_time()
{
	return SDL_GetTicks() - start_time;
}

bool Timer::get_state()
{
	return state;
}
