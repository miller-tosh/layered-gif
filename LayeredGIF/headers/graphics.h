#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;


/*
 * Deals with creating windows, rendering images, and anything graphics-related
 */

class Graphics
{
public:
	Graphics();

	~Graphics();

	// Loads PNG image using path provided
	SDL_Surface* loadImage(const char* path);

	// Loads texture using SDL_Surface provided
	SDL_Texture* loadTexture(SDL_Surface* surface);

	// Renders copy of the loaded texture
	void renderCopy(SDL_Texture* tex);

	// Renders presently loaded image
	void flip();

	// Clears presently loaded image
	void clear();

	// Return private SDL_Renderer pointer
	SDL_Renderer* getRenderer();

	// Return private SDL_Window pointer
	SDL_Window* getWindow();

	// Updates size of window based on dimensions of passed SDL_Surface
	void changeWinSize(SDL_Surface* surface);

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif
