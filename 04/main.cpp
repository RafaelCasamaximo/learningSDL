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

// Key Press Surface 
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

// Global Variables
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;

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
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

			while(!quit)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					// Caso o usuário saia do programa
					if(e.type == SDL_QUIT)
					{
						quit = true;
					}

					// Caso o usuário aperte uma tecla
					switch (e.key.keysym.sym) {
						case SDLK_UP:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
						break;
						case SDLK_DOWN:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
						break;
						case SDLK_LEFT:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
						break;
						case SDLK_RIGHT:	
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
						break;
						default:
						gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
						break;
					}

					SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
					SDL_UpdateWindowSurface(gWindow);
				}
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

	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("../assets/press.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("../assets/up.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("../assets/down.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	
	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("../assets/left.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	
	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("../assets/right.bmp");
	if(gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load default image!\n");
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

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	
	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
	}

	return loadedSurface;
}
