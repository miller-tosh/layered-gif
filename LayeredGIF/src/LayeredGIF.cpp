/*
Author: Tosh Miller (prophecycat)
*/

#include <iostream>
#include <SDL2/SDL.h>		// To run on Mac
//#include "SDL.h"			// To run on Windows

#include "graphics.h"


/*
 * Runs loop which checks for SDL_QUIT event (exit button clicked) and then returns
 */
void check_quit()
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
void create_window()
{
	Graphics graphics;
	check_quit();
}


int main(int argc, char* argv[])
{
	create_window();
	return 0;
}
