/*
Author: Tosh Miller (prophecycat)
*/

#include <iostream>
#include <SDL.h>

using namespace std;

void createWindow()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow
	("Layered GIF", // window's title
		10, 25, // coordinates on the screen, in pixels, of the window's upper left corner
		640, 480, // window's length and height in pixels  
		SDL_WINDOW_OPENGL);

	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	createWindow();
	return 0;
}
