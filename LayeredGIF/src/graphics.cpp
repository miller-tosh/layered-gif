#include <SDL2/SDL.h>		// To run on Mac
//#include "SDL.h"			// To run on Windows
#include "graphics.h"

/*
 * Deals with creating windows, rendering images, and anything graphics-related
 */

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Layered GIF");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
}

