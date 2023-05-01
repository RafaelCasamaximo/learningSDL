// Using SDL and standard IO
#include <SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <stdio.h>

// Screen dimensions constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{	
	// Janela
	SDL_Window* window = NULL;

	// Surface que vai ser contida pela Janela
	SDL_Surface* screenSurface = NULL;

	// Inic a o SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_ERROR: %s", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial - 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == NULL){
			printf("Window could not be created! SDL_Error: %s", SDL_GetError());
		}
		else {
			// Pega superficie da Janela
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Event e;
			bool quit = false;
			while(quit == false){
				while(SDL_PollEvent(&e)){
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
			}
		}

		// Destroi a Janela e fecha o SDL 
		SDL_DestroyWindow(window);
		SDL_Quit();

	}
    return 	0;
}
