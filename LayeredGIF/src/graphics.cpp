
#include <iostream>
#include <SDL2/SDL.h>		// To run on Mac
#include <SDL2/SDL_image.h>
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
	IMG_Quit();
}

SDL_Surface* Graphics::loadImage(const char* path)
{
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* surface = IMG_Load(path);
	return surface;
}

SDL_Texture* Graphics::loadTexture(SDL_Surface* surface)
{
	SDL_Texture* t = SDL_CreateTextureFromSurface(this->_renderer, surface);
	return t;
}

void Graphics::renderCopy(SDL_Texture* tex)
{
	SDL_RenderCopy(this->_renderer, tex, NULL, NULL);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer()
{
	return this->_renderer;
}

SDL_Window* Graphics::getWindow()
{
	return this->_window;
}

void  Graphics::changeWinSize(SDL_Surface* surface, int multi)
{
	int w = surface->w;
	int h = surface->h;
	SDL_Window* win = this->_window;

	SDL_SetWindowSize(win, (w * multi), (h * multi));
}

