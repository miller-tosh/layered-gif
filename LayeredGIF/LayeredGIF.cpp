/*
Author: Tosh Miller (prophecycat)
*/

#include <iostream>
#include <SDL2/SDL.h>


/*
 * Runs loop which checks for SDL_QUIT event (exit button clicked) and then returns
 */
void check_quit(){
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
 * Create general window using
 */
void createWindow()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow
	("Layered GIF", // window's title
		10, 25, // coordinates on the screen, in pixels, of the window's upper left corner
		640, 480, // window's length and height in pixels
		SDL_WINDOW_OPENGL);

	// loops until exit button is clicked and destroys window
	check_quit();

	SDL_DestroyWindow(window);
	SDL_Quit();
}



int main(int argc, char* argv[])
{
	createWindow();
	return 0;
}
