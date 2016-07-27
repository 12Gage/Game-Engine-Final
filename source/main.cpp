
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

bool penGot = false, willGot = false, gunGot = false;

bool Pfront = true, Pback = false, Pright = false, Pleft = false;

int ammo = 11;

int main(int argc, char* argv[]) {

    SDL_Window *window = NULL;                    // Declare a pointer

    SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2

    SDL_Renderer* renderer = NULL;

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_CENTERED,           // initial x position
		SDL_WINDOWPOS_CENTERED,           // initial y position
        1024,                               // width, in pixels
        768,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = true;

    SDL_Event e;

    SDL_Texture *Player = IMG_LoadTexture(renderer, (images_dir + "Player.png").c_str());
    SDL_Texture *PlayerB = IMG_LoadTexture(renderer, (images_dir + "PlayerB.png").c_str());
    SDL_Texture *PlayerR = IMG_LoadTexture(renderer, (images_dir + "PlayerR.png").c_str());
    SDL_Texture *PlayerL = IMG_LoadTexture(renderer, (images_dir + "PlayerL.png").c_str());

    SDL_Rect PlayerPos;

    PlayerPos.x = 0;

    PlayerPos.y = 250;

    PlayerPos.w = 28;

    PlayerPos.h = 56;

	const int PLAYER_VEL = 5;

	int pVelX = 0;
	int pVelY = 0;

    SDL_Texture *bkgd = IMG_LoadTexture(renderer, (images_dir + "Path.png").c_str());

    SDL_Rect bkgdRect;

    bkgdRect.x = 0;

    bkgdRect.y = -700;

    int w, h;
    SDL_QueryTexture(bkgd, NULL, NULL, &w, &h);
    bkgdRect.w = w;
    bkgdRect.h = h;


    SDL_Rect Wall;

    Wall.x = 0;
    Wall.y = -700;
    Wall.w = 3072;
    Wall.h = 10;

    SDL_Rect Wall2;

	Wall2.x = 0;
	Wall2.y = -700;
	Wall2.w = 10;
	Wall2.h = 2304;

    SDL_Rect Wall3;

	Wall3.x = 0;
	Wall3.y = 1600;
	Wall3.w = 3072;
	Wall3.h = 10;

    SDL_Rect Wall4;

	Wall4.x = 3072;
	Wall4.y = -700;
	Wall4.w = 10;
	Wall4.h = 2304;

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

    SDL_Texture *bagClosed1 = IMG_LoadTexture(renderer, (images_dir + "bagClosed1.png").c_str());

    SDL_Texture *bagClosed2 = IMG_LoadTexture(renderer, (images_dir + "bagClosed2.png").c_str());

    SDL_Texture *bagClosed3 = IMG_LoadTexture(renderer, (images_dir + "bagClosed3.png").c_str());


    SDL_Texture *Pen = IMG_LoadTexture(renderer, (images_dir + "Pen.png").c_str());
    SDL_Rect PenPos;

    PenPos.x = 100;

    PenPos.y = 225;

    PenPos.w = 20;

    PenPos.h = 45;

    SDL_Texture *Will = IMG_LoadTexture(renderer, (images_dir + "Will.png").c_str());
    SDL_Rect WillPos;

    WillPos.x = 100;

    WillPos.y = 275;

    WillPos.w = 20;

    WillPos.h = 45;

    SDL_Texture *Gun = IMG_LoadTexture(renderer, (images_dir + "Gun.png").c_str());
    SDL_Rect GunPos;

    GunPos.x = 100;

    GunPos.y = 325;

    GunPos.w = 35;

    GunPos.h = 45;


    SDL_Texture *Ammo0 = IMG_LoadTexture(renderer, (images_dir + "Ammo0.png").c_str());
    SDL_Texture *Ammo1 = IMG_LoadTexture(renderer, (images_dir + "Ammo1.png").c_str());
    SDL_Texture *Ammo2 = IMG_LoadTexture(renderer, (images_dir + "Ammo2.png").c_str());
    SDL_Texture *Ammo3 = IMG_LoadTexture(renderer, (images_dir + "Ammo3.png").c_str());
    SDL_Texture *Ammo4 = IMG_LoadTexture(renderer, (images_dir + "Ammo4.png").c_str());
    SDL_Texture *Ammo5 = IMG_LoadTexture(renderer, (images_dir + "Ammo5.png").c_str());
    SDL_Texture *Ammo6 = IMG_LoadTexture(renderer, (images_dir + "Ammo6.png").c_str());
    SDL_Texture *Ammo7 = IMG_LoadTexture(renderer, (images_dir + "Ammo7.png").c_str());
    SDL_Texture *Ammo8 = IMG_LoadTexture(renderer, (images_dir + "Ammo8.png").c_str());
    SDL_Texture *Ammo9 = IMG_LoadTexture(renderer, (images_dir + "Ammo9.png").c_str());
    SDL_Texture *Ammo10 = IMG_LoadTexture(renderer, (images_dir + "Ammo10.png").c_str());
    SDL_Texture *Ammo11 = IMG_LoadTexture(renderer, (images_dir + "Ammo11.png").c_str());
    SDL_Rect Ammo0Pos;

    Ammo0Pos.x = 50;

    Ammo0Pos.y = 675;

    Ammo0Pos.w = 45;

    Ammo0Pos.h = 65;


    SDL_Texture *Empty, *Full;
    SDL_Rect EmptyPos, FullPos;

    Empty = IMG_LoadTexture(renderer, (images_dir + "HealthEmpty.png").c_str());
    Full = IMG_LoadTexture(renderer, (images_dir + "HealthFull.png").c_str());

    EmptyPos.x = FullPos.x = 10;
    EmptyPos.y = FullPos.y = 50;
    EmptyPos.w = FullPos.w = 239;
    EmptyPos.h = FullPos.h = 32;

    SDL_Texture *Pickup = IMG_LoadTexture(renderer, (images_dir + "Ammo0.png").c_str());
    SDL_Rect PickupPos;

    PickupPos.x = 50;

    PickupPos.y = 500;

    PickupPos.w = 10;

    PickupPos.h = 25;

    SDL_Texture *HealthPickup = IMG_LoadTexture(renderer, (images_dir + "HealthPickup.png").c_str());
    SDL_Rect HealthPickupPos;

    HealthPickupPos.x = 125;

    HealthPickupPos.y = 500;

    HealthPickupPos.w = 10;

    HealthPickupPos.h = 25;

    SDL_Texture *Enemy = IMG_LoadTexture(renderer, (images_dir + "Enemy.png").c_str());
    SDL_Rect EnemyPos;

    EnemyPos.x = 200;

    EnemyPos.y = 300;

    EnemyPos.w = 46;

    EnemyPos.h = 38;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Get window surface
	screenSurface = SDL_GetWindowSurface( window );

	while(quit)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = false;
			}
			else
			{
				if(e.type == SDL_KEYDOWN && e.key.repeat == 0){

					switch(e.key.keysym.sym){

					case SDLK_w:
					pVelY -= PLAYER_VEL;
					Pfront = false;
					Pback = true;
					Pright = false;
					Pleft = false;
					break;
					case SDLK_s:
					pVelY += PLAYER_VEL;
					Pfront = true;
					Pback = false;
					Pright = false;
					Pleft = false;
					break;
					case SDLK_a:
					pVelX -= PLAYER_VEL;
					Pfront = false;
					Pback = false;
					Pright = false;
					Pleft = true;
					break;
					case SDLK_d:
					pVelX += PLAYER_VEL;
					Pfront = false;
					Pback = false;
					Pright = true;
					Pleft = false;
					break;
					case SDLK_SPACE:
					ammo--;
					break;
					}
				}

				else if(e.type == SDL_KEYUP && e.key.repeat == 0)
				{
					switch(e.key.keysym.sym){

					case SDLK_w:
					pVelY += PLAYER_VEL;
					break;
					case SDLK_s:
					pVelY -= PLAYER_VEL;
					break;
					case SDLK_a:
					pVelX += PLAYER_VEL;
					break;
					case SDLK_d:
					pVelX -= PLAYER_VEL;
					break;

					}
				}
			}
		}

		PlayerPos.x += pVelX;


		if(PlayerPos.x > (1024 - (PlayerPos.w * 2))){

			PlayerPos.x = (1024 - (PlayerPos.w * 2));

			bkgdRect.x -= pVelX;

			Wall.x -= pVelX;
			Wall2.x -= pVelX;
			Wall3.x -= pVelX;
			Wall4.x -= pVelX;

			PenPos.x -=pVelX;
			WillPos.x -=pVelX;
			GunPos.x -=pVelX;

			PickupPos.x -=pVelX;
			HealthPickupPos.x -=pVelX;

			EnemyPos.x -=pVelX;
		}

		if(PlayerPos.x < (0 + (PlayerPos.w * 2))){

			PlayerPos.x = (0 + (PlayerPos.w * 2));

			bkgdRect.x -= pVelX;

			Wall.x -= pVelX;
			Wall2.x -= pVelX;
			Wall3.x -= pVelX;
			Wall4.x -= pVelX;

			PenPos.x -=pVelX;
			WillPos.x -=pVelX;
			GunPos.x -=pVelX;

			PickupPos.x -=pVelX;
			HealthPickupPos.x -=pVelX;

			EnemyPos.x -=pVelX;
		}

		if( SDL_HasIntersection(&PlayerPos, &Wall) || SDL_HasIntersection(&PlayerPos, &Wall2) ||
				SDL_HasIntersection(&PlayerPos, &Wall3) || SDL_HasIntersection(&PlayerPos, &Wall4)){

			PlayerPos.x -= pVelX;
		}


		PlayerPos.y += pVelY;

		if(PlayerPos.y < (0 + (PlayerPos.h * 2))){

			PlayerPos.y = (0 + (PlayerPos.h * 2));

			bkgdRect.y -= pVelY;

			Wall.y -= pVelY;
			Wall2.y -= pVelY;
			Wall3.y -= pVelY;
			Wall4.y -= pVelY;

			PenPos.y -=pVelY;
			WillPos.y -=pVelY;
			GunPos.y -=pVelY;

			PickupPos.y -=pVelY;
			HealthPickupPos.y -=pVelY;

			EnemyPos.y -=pVelY;
		}

		if(PlayerPos.y > (768 - (PlayerPos.h * 2))){

			PlayerPos.y = 768 - (PlayerPos.h * 2);

			bkgdRect.y -= pVelY;

			Wall.y -= pVelY;
			Wall2.y -= pVelY;
			Wall3.y -= pVelY;
			Wall4.y -= pVelY;

			PenPos.y -=pVelY;
			WillPos.y -=pVelY;
			GunPos.y -=pVelY;

			PickupPos.y -=pVelY;
			HealthPickupPos.y -=pVelY;

			EnemyPos.y -=pVelY;
		}

		if( SDL_HasIntersection(&PlayerPos, &Wall) || SDL_HasIntersection(&PlayerPos, &Wall2)  ||
				SDL_HasIntersection(&PlayerPos, &Wall3) || SDL_HasIntersection(&PlayerPos, &Wall4)) {

			PlayerPos.y -= pVelY;
		}

		if( SDL_HasIntersection(&PlayerPos, &PenPos)) {

			PenPos.x = -1000;
			penGot = true;
		}

		if( SDL_HasIntersection(&PlayerPos, &WillPos)) {

			WillPos.x = -1000;
			willGot = true;
		}

		if( SDL_HasIntersection(&PlayerPos, &GunPos)) {

			GunPos.x = -1000;
			gunGot = true;
		}

		if(ammo <= 5)
		{
			if( SDL_HasIntersection(&PlayerPos, &PickupPos)) {

				PickupPos.x = -1000;
				ammo += 6;
			}
		}

		if(FullPos.w <= 120)
		{
			if( SDL_HasIntersection(&PlayerPos, &HealthPickupPos)) {

				HealthPickupPos.x = -1000;
				FullPos.w += 60;
			}
		}

		if( SDL_HasIntersection(&PlayerPos, &EnemyPos)) {

			FullPos.w -=5;
		}



		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, bkgd, NULL, &bkgdRect);


		SDL_RenderCopy(renderer, HealthPickup, NULL, &HealthPickupPos);

		SDL_RenderCopy(renderer, Pickup, NULL, &PickupPos);


		SDL_RenderCopy(renderer, Pen, NULL, &PenPos);

		SDL_RenderCopy(renderer, Will, NULL, &WillPos);

		SDL_RenderCopy(renderer, Gun, NULL, &GunPos);


		if(Pfront == true)
		{
		SDL_RenderCopy(renderer, Player, NULL, &PlayerPos);
		}
		if(Pback == true)
		{
		SDL_RenderCopy(renderer, PlayerB, NULL, &PlayerPos);
		}
		if(Pright == true)
		{
		SDL_RenderCopy(renderer, PlayerR, NULL, &PlayerPos);
		}
		if(Pleft == true)
		{
		SDL_RenderCopy(renderer, PlayerL, NULL, &PlayerPos);
		}


		if(penGot == false)
		{
		SDL_RenderCopy(renderer, bagOpen1, NULL, &bag1Pos);
		}

		if(willGot == false)
		{
		SDL_RenderCopy(renderer, bagOpen2, NULL, &bag2Pos);
		}

		if(gunGot == false)
		{
		SDL_RenderCopy(renderer, bagOpen3, NULL, &bag3Pos);
		}


		if(penGot == true)
		{
		SDL_RenderCopy(renderer, bagClosed1, NULL, &bag1Pos);
		}

		if(willGot == true)
		{
		SDL_RenderCopy(renderer, bagClosed2, NULL, &bag2Pos);
		}

		if(gunGot == true)
		{
		SDL_RenderCopy(renderer, bagClosed3, NULL, &bag3Pos);
		}


		if(ammo == 11)
		{
		SDL_RenderCopy(renderer, Ammo0, NULL, &Ammo0Pos);
		}
		if(ammo == 10)
		{
		SDL_RenderCopy(renderer, Ammo1, NULL, &Ammo0Pos);
		}
		if(ammo == 9)
		{
		SDL_RenderCopy(renderer, Ammo2, NULL, &Ammo0Pos);
		}
		if(ammo == 8)
		{
		SDL_RenderCopy(renderer, Ammo3, NULL, &Ammo0Pos);
		}
		if(ammo == 7)
		{
		SDL_RenderCopy(renderer, Ammo4, NULL, &Ammo0Pos);
		}
		if(ammo == 6)
		{
		SDL_RenderCopy(renderer, Ammo5, NULL, &Ammo0Pos);
		}
		if(ammo == 5)
		{
		SDL_RenderCopy(renderer, Ammo6, NULL, &Ammo0Pos);
		}
		if(ammo == 4)
		{
		SDL_RenderCopy(renderer, Ammo7, NULL, &Ammo0Pos);
		}
		if(ammo == 3)
		{
		SDL_RenderCopy(renderer, Ammo8, NULL, &Ammo0Pos);
		}
		if(ammo == 2)
		{
		SDL_RenderCopy(renderer, Ammo9, NULL, &Ammo0Pos);
		}
		if(ammo == 1)
		{
		SDL_RenderCopy(renderer, Ammo10, NULL, &Ammo0Pos);
		}
		if(ammo <= 0)
		{
		SDL_RenderCopy(renderer, Ammo11, NULL, &Ammo0Pos);
		}

		SDL_RenderCopy(renderer, Enemy, NULL, &EnemyPos);

		SDL_RenderCopy(renderer, Empty, NULL, &EmptyPos);

		SDL_RenderCopy(renderer, Full, NULL, &FullPos);

		SDL_RenderPresent(renderer);

		SDL_Delay(16);
	}


    // The window is open: could enter program loop here (see SDL_PollEvent())

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}

