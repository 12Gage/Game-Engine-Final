
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

	const float PLAYER_VEL = 30;

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


    SDL_Texture *Pen = IMG_LoadTexture(renderer, (images_dir + "PenP.png").c_str());
    SDL_Rect PenPos;

    PenPos.x = 100;

    PenPos.y = 225;

    PenPos.w = 20;

    PenPos.h = 45;

    SDL_Texture *Will = IMG_LoadTexture(renderer, (images_dir + "WillP.png").c_str());
    SDL_Rect WillPos;

    WillPos.x = 100;

    WillPos.y = 275;

    WillPos.w = 20;

    WillPos.h = 45;

    SDL_Texture *Gun = IMG_LoadTexture(renderer, (images_dir + "GunP.png").c_str());
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

    SDL_Texture *Pickup = IMG_LoadTexture(renderer, (images_dir + "AmmoP.png").c_str());
    SDL_Rect PickupPos;

    PickupPos.x = 50;

    PickupPos.y = 500;

    PickupPos.w = 10;

    PickupPos.h = 25;

    SDL_Texture *HealthPickup = IMG_LoadTexture(renderer, (images_dir + "HealthP.png").c_str());
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

    SDL_Texture *Tree = IMG_LoadTexture(renderer, (images_dir + "Tree.png").c_str());
    SDL_Rect TreePos;
    TreePos.x = 250;
    TreePos.y = 650;
    TreePos.w = 68;
    TreePos.h = 60;

    SDL_Rect TreePos2;
    TreePos2.x = 400;
    TreePos2.y = 650;
    TreePos2.w = 68;
    TreePos2.h = 60;

    SDL_Rect TreePos3;
    TreePos3.x = 525;
    TreePos3.y = 625;
    TreePos3.w = 68;
    TreePos3.h = 60;

    SDL_Rect TreePos4;
    TreePos4.x = 525;
    TreePos4.y = 725;
    TreePos4.w = 68;
    TreePos4.h = 60;

    SDL_Rect TreePos5;
    TreePos5.x = 575;
    TreePos5.y = 800;
    TreePos5.w = 68;
    TreePos5.h = 60;

    SDL_Rect TreePos6;
    TreePos6.x = 550;
    TreePos6.y = 925;
    TreePos6.w = 68;
    TreePos6.h = 60;

    SDL_Rect TreePos7;
    TreePos7.x = 465;
    TreePos7.y = 875;
    TreePos7.w = 68;
    TreePos7.h = 60;

    SDL_Rect TreePos8;
    TreePos8.x = 400;
    TreePos8.y = 785;
    TreePos8.w = 68;
    TreePos8.h = 60;

    SDL_Rect TreePos9;
    TreePos9.x = 300;
    TreePos9.y = 725;
    TreePos9.w = 68;
    TreePos9.h = 60;

    SDL_Rect TreePos10;
    TreePos10.x = 235;
    TreePos10.y = 800;
    TreePos10.w = 68;
    TreePos10.h = 60;

    SDL_Rect TreePos11;
    TreePos11.x = 235;
    TreePos11.y = 925;
    TreePos11.w = 68;
    TreePos11.h = 60;

    SDL_Rect TreePos12;
    TreePos12.x = 335;
    TreePos12.y = 875;
    TreePos12.w = 68;
    TreePos12.h = 60;

    SDL_Rect TreePos13;
    TreePos13.x = 400;
    TreePos13.y = 975;
    TreePos13.w = 68;
    TreePos13.h = 60;

    SDL_Rect TreePos14;
    TreePos14.x = 2750;
    TreePos14.y = 850;
    TreePos14.w = 68;
    TreePos14.h = 60;

    SDL_Rect TreePos15;
    TreePos15.x = 2600;
    TreePos15.y = 835;
    TreePos15.w = 68;
    TreePos15.h = 60;

    SDL_Rect TreePos16;
    TreePos16.x = 2585;
    TreePos16.y = 755;
    TreePos16.w = 68;
    TreePos16.h = 60;

    SDL_Rect TreePos17;
    TreePos17.x = 2675;
    TreePos17.y = 765;
    TreePos17.w = 68;
    TreePos17.h = 60;

    SDL_Rect TreePos18;
    TreePos18.x = 2780;
    TreePos18.y = 750;
    TreePos18.w = 68;
    TreePos18.h = 60;

    SDL_Rect TreePos19;
    TreePos19.x = 2400;
    TreePos19.y = -250;
    TreePos19.w = 68;
    TreePos19.h = 60;

    SDL_Rect TreePos20;
    TreePos20.x = 1435;
    TreePos20.y = -655;
    TreePos20.w = 68;
    TreePos20.h = 60;

    SDL_Rect TreePos21;
    TreePos21.x = 1000;
    TreePos21.y = -660;
    TreePos21.w = 68;
    TreePos21.h = 60;

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

			TreePos.x -=pVelX;
			TreePos2.x -=pVelX;
			TreePos3.x -=pVelX;
			TreePos4.x -=pVelX;
			TreePos5.x -=pVelX;
			TreePos6.x -=pVelX;
			TreePos7.x -=pVelX;
			TreePos8.x -=pVelX;
			TreePos9.x -=pVelX;
			TreePos10.x -=pVelX;
			TreePos11.x -=pVelX;
			TreePos12.x -=pVelX;
			TreePos13.x -=pVelX;
			TreePos14.x -=pVelX;
			TreePos15.x -=pVelX;
			TreePos16.x -=pVelX;
			TreePos17.x -=pVelX;
			TreePos18.x -=pVelX;
			TreePos19.x -=pVelX;
			TreePos20.x -=pVelX;
			TreePos21.x -=pVelX;
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

			TreePos.x -=pVelX;
			TreePos2.x -=pVelX;
			TreePos3.x -=pVelX;
			TreePos4.x -=pVelX;
			TreePos5.x -=pVelX;
			TreePos6.x -=pVelX;
			TreePos7.x -=pVelX;
			TreePos8.x -=pVelX;
			TreePos9.x -=pVelX;
			TreePos10.x -=pVelX;
			TreePos11.x -=pVelX;
			TreePos12.x -=pVelX;
			TreePos13.x -=pVelX;
			TreePos14.x -=pVelX;
			TreePos15.x -=pVelX;
			TreePos16.x -=pVelX;
			TreePos17.x -=pVelX;
			TreePos18.x -=pVelX;
			TreePos19.x -=pVelX;
			TreePos20.x -=pVelX;
			TreePos21.x -=pVelX;
		}

		if( SDL_HasIntersection(&PlayerPos, &Wall) || SDL_HasIntersection(&PlayerPos, &Wall2) ||
				SDL_HasIntersection(&PlayerPos, &Wall3) || SDL_HasIntersection(&PlayerPos, &Wall4)||
				 SDL_HasIntersection(&PlayerPos, &TreePos)|| SDL_HasIntersection(&PlayerPos, &TreePos2)||
				 SDL_HasIntersection(&PlayerPos, &TreePos3)|| SDL_HasIntersection(&PlayerPos, &TreePos4)||
				 SDL_HasIntersection(&PlayerPos, &TreePos5)|| SDL_HasIntersection(&PlayerPos, &TreePos6)||
				 SDL_HasIntersection(&PlayerPos, &TreePos7)|| SDL_HasIntersection(&PlayerPos, &TreePos8)||
				 SDL_HasIntersection(&PlayerPos, &TreePos9)|| SDL_HasIntersection(&PlayerPos, &TreePos10)||
				 SDL_HasIntersection(&PlayerPos, &TreePos11)|| SDL_HasIntersection(&PlayerPos, &TreePos12)||
				 SDL_HasIntersection(&PlayerPos, &TreePos13)|| SDL_HasIntersection(&PlayerPos, &TreePos14)||
				 SDL_HasIntersection(&PlayerPos, &TreePos15)|| SDL_HasIntersection(&PlayerPos, &TreePos16)||
				 SDL_HasIntersection(&PlayerPos, &TreePos17)|| SDL_HasIntersection(&PlayerPos, &TreePos18)||
				 SDL_HasIntersection(&PlayerPos, &TreePos19)|| SDL_HasIntersection(&PlayerPos, &TreePos20)||
				 SDL_HasIntersection(&PlayerPos, &TreePos21)){

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

			TreePos.y -=pVelY;
			TreePos2.y -=pVelY;
			TreePos3.y -=pVelY;
			TreePos4.y -=pVelY;
			TreePos5.y -=pVelY;
			TreePos6.y -=pVelY;
			TreePos7.y -=pVelY;
			TreePos8.y -=pVelY;
			TreePos9.y -=pVelY;
			TreePos10.y -=pVelY;
			TreePos11.y -=pVelY;
			TreePos12.y -=pVelY;
			TreePos13.y -=pVelY;
			TreePos14.y -=pVelY;
			TreePos15.y -=pVelY;
			TreePos16.y -=pVelY;
			TreePos17.y -=pVelY;
			TreePos18.y -=pVelY;
			TreePos19.y -=pVelY;
			TreePos20.y -=pVelY;
			TreePos21.y -=pVelY;
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

			TreePos.y -=pVelY;
			TreePos2.y -=pVelY;
			TreePos3.y -=pVelY;
			TreePos4.y -=pVelY;
			TreePos5.y -=pVelY;
			TreePos6.y -=pVelY;
			TreePos7.y -=pVelY;
			TreePos8.y -=pVelY;
			TreePos9.y -=pVelY;
			TreePos10.y -=pVelY;
			TreePos11.y -=pVelY;
			TreePos12.y -=pVelY;
			TreePos13.y -=pVelY;
			TreePos14.y -=pVelY;
			TreePos15.y -=pVelY;
			TreePos16.y -=pVelY;
			TreePos17.y -=pVelY;
			TreePos18.y -=pVelY;
			TreePos19.y -=pVelY;
			TreePos20.y -=pVelY;
			TreePos21.y -=pVelY;
		}

		if( SDL_HasIntersection(&PlayerPos, &Wall) || SDL_HasIntersection(&PlayerPos, &Wall2) ||
				SDL_HasIntersection(&PlayerPos, &Wall3) || SDL_HasIntersection(&PlayerPos, &Wall4)||
				SDL_HasIntersection(&PlayerPos, &TreePos)|| SDL_HasIntersection(&PlayerPos, &TreePos2)||
				 SDL_HasIntersection(&PlayerPos, &TreePos3)|| SDL_HasIntersection(&PlayerPos, &TreePos4)||
				 SDL_HasIntersection(&PlayerPos, &TreePos5)|| SDL_HasIntersection(&PlayerPos, &TreePos6)||
				 SDL_HasIntersection(&PlayerPos, &TreePos7)|| SDL_HasIntersection(&PlayerPos, &TreePos8)||
				 SDL_HasIntersection(&PlayerPos, &TreePos9)|| SDL_HasIntersection(&PlayerPos, &TreePos10)||
				 SDL_HasIntersection(&PlayerPos, &TreePos11)|| SDL_HasIntersection(&PlayerPos, &TreePos12)||
				 SDL_HasIntersection(&PlayerPos, &TreePos13)|| SDL_HasIntersection(&PlayerPos, &TreePos14)||
				 SDL_HasIntersection(&PlayerPos, &TreePos15)|| SDL_HasIntersection(&PlayerPos, &TreePos16)||
				 SDL_HasIntersection(&PlayerPos, &TreePos17)|| SDL_HasIntersection(&PlayerPos, &TreePos18)||
				 SDL_HasIntersection(&PlayerPos, &TreePos19)|| SDL_HasIntersection(&PlayerPos, &TreePos20)||
				 SDL_HasIntersection(&PlayerPos, &TreePos21)){

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

			FullPos.w -=.025;

			if(FullPos.w == 0)
			{
				FullPos.w = 0;
			}
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


		SDL_RenderCopy(renderer, Tree, NULL, &TreePos);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos2);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos3);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos4);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos5);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos6);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos7);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos8);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos9);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos10);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos11);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos12);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos13);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos14);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos15);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos16);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos17);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos18);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos19);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos20);
		SDL_RenderCopy(renderer, Tree, NULL, &TreePos21);


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

