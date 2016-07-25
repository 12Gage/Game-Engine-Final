#include <iostream>
#include <stdio.h>
#include <string>
#include <stdint.h>
#include <sstream>

using namespace std;

#if defined(__APPLE__)
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"

string currentWorkingDirectory(getcwd(NULL, 0));
string images_dir = currentWorkingDirectory + "/Game-Engine-Final/image/";
#endif

#if defined(_WIN32) || (_WIN64)

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <direct.h>
#define getcwd _getcwd

string currentWorkingDirectory(getcwd(NULL, 0));
string images_dir = currentWorkingDirectory + "/Game-Engine-Final/image/";

#endif

#include "player.h"

float deltaTime = 0.0;
int thisTime = 0;
int lastTime = 0;

int main(int argc, char* argv[]) {

	srand(time_t(NULL));

    SDL_Window *window = NULL;                    // Declare a pointer

    SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2

    SDL_Renderer* renderer = NULL;

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1024,                               // width, in pixels
        768,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;

    SDL_Event e;

    Player player1(renderer, 0, images_dir.c_str(), 10.0, 250.0);

    SDL_Texture *bkgd = IMG_LoadTexture(renderer, (images_dir + "Path.png").c_str());

    SDL_Rect bkgdRect;

    bkgdRect.x = 0;

    bkgdRect.y = -700;

    bkgdRect.w = 3072;

    bkgdRect.h = 2304;

    SDL_Texture *bagOpen1 = IMG_LoadTexture(renderer, (images_dir + "bagOpen1.png").c_str());
    SDL_Rect bag1Pos;

    bag1Pos.x = 375;

    bag1Pos.y = 10;

    bag1Pos.w = 90;

    bag1Pos.h = 135;

    SDL_Texture *bagOpen2 = IMG_LoadTexture(renderer, (images_dir + "bagOpen2.png").c_str());
    SDL_Rect bag2Pos;

    bag2Pos.x = 475;

    bag2Pos.y = 10;

    bag2Pos.w = 90;

    bag2Pos.h = 135;

    SDL_Texture *bagOpen3 = IMG_LoadTexture(renderer, (images_dir + "bagOpen3.png").c_str());
    SDL_Rect bag3Pos;

    bag3Pos.x = 575;

    bag3Pos.y = 10;

    bag3Pos.w = 90;

    bag3Pos.h = 135;

    SDL_Texture *Ammo0 = IMG_LoadTexture(renderer, (images_dir + "Ammo0.png").c_str());
    SDL_Rect Ammo0Pos;

    Ammo0Pos.x = 50;

    Ammo0Pos.y = 675;

    Ammo0Pos.w = 45;

    Ammo0Pos.h = 65;



	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Get window surface
	screenSurface = SDL_GetWindowSurface( window );

	while(!quit)
	{
		thisTime = SDL_GetTicks();
		deltaTime = (float)(thisTime - lastTime)/1000;
		lastTime = thisTime;

		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}

			switch(e.type){


			}
		}

		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, bkgd, NULL, &bkgdRect);

		SDL_RenderCopy(renderer, bagOpen1, NULL, &bag1Pos);

		SDL_RenderCopy(renderer, bagOpen2, NULL, &bag2Pos);

		SDL_RenderCopy(renderer, bagOpen3, NULL, &bag3Pos);

		SDL_RenderCopy(renderer, Ammo0, NULL, &Ammo0Pos);

		player1.Draw(renderer);

		SDL_RenderPresent(renderer);
	}


    // The window is open: could enter program loop here (see SDL_PollEvent())

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
