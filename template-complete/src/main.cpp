// Using SDL and standard IO
#include <SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_keycode.h>
#include <SDL_pixels.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <cstddef>
#include <stdio.h>
#include <iostream>

// Inicia SDL e cria a Janela'
bool init();
// Carrega a midia
bool loadMedia();
// Free na midia e desliga o SDL
void close();
// Carrega imagem individual
SDL_Surface* loadSurface(std::string path);


// Global Variables
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gStretchedSurface = NULL;

// Screen dimensions constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{	
	if(!init())
	{
		printf("Failed to initialize!\n");
	}
	else {
		if(!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else {
			
			bool quit = false;
			SDL_Event e;

			while(!quit)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					// Caso o usuário saia do programa
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled(gStretchedSurface, NULL, gScreenSurface, &stretchRect);

				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	close();
    return 	0;
}

bool init()
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s: ", SDL_GetError());
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("SDL Tutorial - 04",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN); 
		if(gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s", SDL_GetError());
			success = false;
		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}	
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	gStretchedSurface = loadSurface("assets/stretch.bmp");
	if(gStretchedSurface == NULL)
	{
		printf("Failed to load stretched image!\n");
		success = false;
	}

	return success;
}

void close()
{
	SDL_FreeSurface(gStretchedSurface);
	gStretchedSurface = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	
	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if(optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL_Error: %s", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}
