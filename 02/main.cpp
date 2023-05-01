// Using SDL and standard IO
#include <SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_pixels.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <cstddef>
#include <stdio.h>

// Inicia SDL e cria a Janela'
bool init();
// Carrega a midia
bool loadMedia();
// Free na midia e desliga o SDL
void close();

// Global Variables
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

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
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
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
		gWindow = SDL_CreateWindow("SDL Tutorial - 02",
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

	gHelloWorld = SDL_LoadBMP("../assets/hello_world.bmp");
	if(gHelloWorld == NULL)
	{
		printf("Unable to load image \"../assets/hello_world.bmp\"! SDL_Error: %s", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	SDL_FreeSurface(gHelloWorld);
	SDL_DestroyWindow(gWindow);
	SDL_Quit();
}
