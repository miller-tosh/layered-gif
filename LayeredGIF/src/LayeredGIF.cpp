/*
Author: Tosh Miller (prophecycat)
*/

#include <iostream>
#include <SDL2/SDL.h>		// To run on Mac
#include <SDL2/SDL_image.h>
//#include "SDL.h"			// To run on Windows

#include "graphics.h"


/*
 * Runs loop which checks for SDL_QUIT event (exit button clicked) and then returns
 */
void checkQuit()
{
	SDL_Event e;
	bool quit = false;
	while (!quit){
	    while (SDL_PollEvent(&e)){
	        if (e.type == SDL_QUIT){
	            quit = true;
	        }
	    }
	}
}


/*
 * Create general window using from graphics class and waits for event to destruct
 */
void createWindow()
{
	Graphics graphics;
	const char* b = "sample-base.png";

	SDL_Surface* a = graphics.loadImage(b);
	SDL_Texture* c = graphics.loadTexture(a);

	graphics.changeWinSize(a);

	graphics.renderCopy(c);
	graphics.flip();

	checkQuit();
	SDL_FreeSurface(a);
	SDL_DestroyTexture(c);
}


int main(int argc, char* argv[])
{
	createWindow();
	return 0;
}
