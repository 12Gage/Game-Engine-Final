//when you fire make sure you are facing the right way


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

#include <unistd.h>
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

bool penGot = false, willGot = false, gunGot = false;

bool Pfront = true, Pback = false, Pright = false, Pleft = false;

bool fireRight = false, fireLeft = false, fireUp = false, fireDown = false;

bool fire = true;

int ammo = 11;

int enemyHealth = 5, playerHealth = 10;

int turretHealth = 5;
int turretHealth2 = 4;
int turretHealth3 = 5;
int turretHealth4 = 4;
int turretHealth5 = 5;
int turretHealth6 = 6;
int turretHealth7 = 5;
int turretHealth8 = 5;
int turretHealth9 = 3;
int turretHealth10 = 5;
int turretHealth11 = 6;
int turretHealth12 = 5;
int turretHealth13 = 4;
int turretHealth14 = 5;
int turretHealth15 = 6;
int turretHealth16 = 5;

bool turretActive = false;
bool turretActive2 = false;
bool turretActive3 = false;
bool turretActive4 = false;
bool turretActive5 = false;
bool turretActive6 = false;
bool turretActive7 = false;
bool turretActive8 = false;
bool turretActive9 = false;
bool turretActive10 = false;
bool turretActive11 = false;
bool turretActive12 = false;
bool turretActive13 = false;
bool turretActive14 = false;
bool turretActive15 = false;
bool turretActive16 = false;

bool eBulletActive = true;
bool eBulletActive2 = true;
bool eBulletActive3 = true;
bool eBulletActive4 = true;
bool eBulletActive5 = true;
bool eBulletActive6 = true;
bool eBulletActive7 = true;
bool eBulletActive8 = true;
bool eBulletActive9 = true;
bool eBulletActive10 = true;
bool eBulletActive11 = true;
bool eBulletActive12 = true;
bool eBulletActive13 = true;
bool eBulletActive14 = true;
bool eBulletActive15 = true;
bool eBulletActive16 = true;

int eBulletDir = 0;
int eBulletDir2 = 0;
int eBulletDir3 = 0;
int eBulletDir4= 0;
int eBulletDir5 = 0;
int eBulletDir6 = 0;
int eBulletDir7 = 0;
int eBulletDir8 = 0;
int eBulletDir9 = 0;
int eBulletDir10 = 0;
int eBulletDir11 = 0;
int eBulletDir12 = 0;
int eBulletDir13 = 0;
int eBulletDir14 = 0;
int eBulletDir15 = 0;
int eBulletDir16 = 0;

bool pBulletActive = true;

bool enemyActive = true;

int EnemyDir = 0;

int pBulletDir = 0;

bool Right, Left;

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

    SDL_Texture *title = IMG_LoadTexture(renderer, (images_dir + "Title.png").c_str());
    SDL_Texture *Win = IMG_LoadTexture(renderer, (images_dir + "Win.png").c_str());
    SDL_Texture *Lose = IMG_LoadTexture(renderer, (images_dir + "Lose.png").c_str());
    SDL_Rect titlePos;
    titlePos.x = 0;
    titlePos.y = 0;
    titlePos.w = 1024;
    titlePos.h = 768;

    Player player1 = Player(renderer, 0, images_dir.c_str(), 100.0, 250.0);

    SDL_Texture *Player = IMG_LoadTexture(renderer, (images_dir + "Player.png").c_str());
    SDL_Texture *PlayerB = IMG_LoadTexture(renderer, (images_dir + "PlayerB.png").c_str());
    SDL_Texture *PlayerR = IMG_LoadTexture(renderer, (images_dir + "PlayerR.png").c_str());
    SDL_Texture *PlayerL = IMG_LoadTexture(renderer, (images_dir + "PlayerL.png").c_str());

    SDL_Rect PlayerPos;
    PlayerPos.x = 0;
    PlayerPos.y = 250;
    PlayerPos.w = 28;
    PlayerPos.h = 56;

	const float PLAYER_VEL = 1;

	int pVelX = 0;
	int pVelY = 0;

    SDL_Texture *drop = IMG_LoadTexture(renderer, (images_dir + "drop3.png").c_str());
    SDL_Rect dropPos;
    dropPos.x = -100;
    dropPos.y = -100;
    dropPos.w = 28;
    dropPos.h = 56;

    SDL_Texture *turret = IMG_LoadTexture(renderer, (images_dir + "turret.png").c_str());
    SDL_Rect turretPos;
    turretPos.x = 275;
    turretPos.y = 525;
    turretPos.w = 100;
    turretPos.h = 100;

    SDL_Rect turretPos2;
    turretPos2.x = 165;
    turretPos2.y = 715;
    turretPos2.w = 100;
    turretPos2.h = 100;

    SDL_Rect turretPos3;
    turretPos3.x = 475;
    turretPos3.y = 765;
    turretPos3.w = 100;
    turretPos3.h = 100;

    SDL_Rect turretPos4;
    turretPos4.x = 275;
    turretPos4.y = 975;
    turretPos4.w = 100;
    turretPos4.h = 100;

    SDL_Rect turretPos5;
    turretPos5.x = 475;
    turretPos5.y = 975;
    turretPos5.w = 100;
    turretPos5.h = 100;

    SDL_Rect turretPos6;
    turretPos6.x = 915;
    turretPos6.y = 450;
    turretPos6.w = 100;
    turretPos6.h = 100;

    SDL_Rect turretPos7;
    turretPos7.x = 1065;
    turretPos7.y = 450;
    turretPos7.w = 100;
    turretPos7.h = 100;

    SDL_Rect turretPos8;
    turretPos8.x = 1375;
    turretPos8.y = 450;
    turretPos8.w = 100;
    turretPos8.h = 100;

    SDL_Rect turretPos9;
    turretPos9.x = 1525;
    turretPos9.y = 450;
    turretPos9.w = 100;
    turretPos9.h = 100;

    SDL_Rect turretPos10;
    turretPos10.x = 915;
    turretPos10.y = -25;
    turretPos10.w = 100;
    turretPos10.h = 100;

    SDL_Rect turretPos11;
    turretPos11.x = 1065;
    turretPos11.y = -25;
    turretPos11.w = 100;
    turretPos11.h = 100;

    SDL_Rect turretPos12;
    turretPos12.x = 1375;
    turretPos12.y = -25;
    turretPos12.w = 100;
    turretPos12.h = 100;

    SDL_Rect turretPos13;
    turretPos13.x = 1525;
    turretPos13.y = -25;
    turretPos13.w = 100;
    turretPos13.h = 100;

    SDL_Rect turretPos14;
    turretPos14.x = 2700;
    turretPos14.y = 625;
    turretPos14.w = 100;
    turretPos14.h = 100;

    SDL_Rect turretPos15;
    turretPos15.x = 2500;
    turretPos15.y = 800;
    turretPos15.w = 100;
    turretPos15.h = 100;

    SDL_Rect turretPos16;
    turretPos16.x = 2765;
    turretPos16.y = 850;
    turretPos16.w = 100;
    turretPos16.h = 100;

    SDL_Texture *bee = IMG_LoadTexture(renderer, (images_dir + "bee.png").c_str());
    SDL_Rect beePos;
    beePos.x = -200;
    beePos.y = -200;
    beePos.w = 16;
    beePos.h = 16;

    SDL_Rect beePos2;
    beePos2.x = -200;
    beePos2.y = -200;
    beePos2.w = 16;
    beePos2.h = 16;

    SDL_Rect beePos3;
    beePos3.x = -200;
    beePos3.y = -200;
    beePos3.w = 16;
    beePos3.h = 16;

    SDL_Rect beePos4;
    beePos4.x = -200;
    beePos4.y = -200;
    beePos4.w = 16;
    beePos4.h = 16;

    SDL_Rect beePos5;
    beePos5.x = -200;
    beePos5.y = -200;
    beePos5.w = 16;
    beePos5.h = 16;

    SDL_Rect beePos6;
    beePos6.x = -200;
    beePos6.y = -200;
    beePos6.w = 16;
    beePos6.h = 16;

    SDL_Rect beePos7;
    beePos7.x = -200;
    beePos7.y = -200;
    beePos7.w = 16;
    beePos7.h = 16;

    SDL_Rect beePos8;
    beePos8.x = -200;
    beePos8.y = -200;
    beePos8.w = 16;
    beePos8.h = 16;

    SDL_Rect beePos9;
    beePos9.x = -200;
    beePos9.y = -200;
    beePos9.w = 16;
    beePos9.h = 16;

    SDL_Rect beePos10;
    beePos10.x = -200;
    beePos10.y = -200;
    beePos10.w = 16;
    beePos10.h = 16;

    SDL_Rect beePos11;
    beePos11.x = -200;
    beePos11.y = -200;
    beePos11.w = 16;
    beePos11.h = 16;

    SDL_Rect beePos12;
    beePos12.x = -200;
    beePos12.y = -200;
    beePos12.w = 16;
    beePos12.h = 16;

    SDL_Rect beePos13;
    beePos13.x = -200;
    beePos13.y = -200;
    beePos13.w = 16;
    beePos13.h = 16;

    SDL_Rect beePos14;
    beePos14.x = -200;
    beePos14.y = -200;
    beePos14.w = 16;
    beePos14.h = 16;

    SDL_Rect beePos15;
    beePos15.x = -200;
    beePos15.y = -200;
    beePos15.w = 16;
    beePos15.h = 16;

    SDL_Rect beePos16;
    beePos16.x = -200;
    beePos16.y = -200;
    beePos16.w = 16;
    beePos16.h = 16;

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
    SDL_Texture *Enemy2 = IMG_LoadTexture(renderer, (images_dir + "Enemy2.png").c_str());
    SDL_Rect EnemyPos;

    EnemyPos.x = 200;

    EnemyPos.y = 300;

    EnemyPos.w = 46;

    EnemyPos.h = 38;

    SDL_Texture *Lake = IMG_LoadTexture(renderer, (images_dir + "Lake.png").c_str());
    SDL_Rect LakePos;
    LakePos.x = 185;
    LakePos.y = -525;
    LakePos.w = 430;
    LakePos.h = 333;

    SDL_Texture *Dock = IMG_LoadTexture(renderer, (images_dir + "Dock.png").c_str());
    SDL_Rect DockPos;
    DockPos.x = 85;
    DockPos.y = -485;
    DockPos.w = 119;
    DockPos.h = 96;

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

	enum GameState{MENU, GAME, WIN,LOSE};

	GameState gameState = MENU;

	bool menu, game, win, lose;

	while(quit)
	{
		switch(gameState)
		{
		case MENU:
			menu = true;

			while(menu)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = false;
						menu = false;
						break;
					}
					else
					{
						if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

							switch (e.key.keysym.sym) {

							case SDLK_p:
								menu = false;
								gameState = GAME;
								break;
							}
						}
					}
				}

				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, title, NULL, &titlePos);

				SDL_RenderPresent(renderer);
			}
			break;

		case GAME:
			Pfront = true, Pback = false, Pright = false, Pleft = false;

			PlayerPos.x = 0;
			PlayerPos.y = 250;

			penGot = false;
			PenPos.x = 100;
			PenPos.y = 225;

			willGot = false;
			WillPos.x = 100;
			WillPos.y = 275;

			gunGot = false;
			GunPos.x = 100;
			GunPos.y = 325;

		    turretPos.x = 275;
		    turretPos.y = 525;

		    turretPos2.x = 165;
		    turretPos2.y = 715;

		    turretPos3.x = 475;
		    turretPos3.y = 765;

		    turretPos4.x = 275;
		    turretPos4.y = 975;

		    turretPos5.x = 475;
		    turretPos5.y = 975;

		    turretPos6.x = 915;
		    turretPos6.y = 450;

		    turretPos7.x = 1065;
		    turretPos7.y = 450;

		    turretPos8.x = 1375;
		    turretPos8.y = 450;

		    turretPos9.x = 1525;
		    turretPos9.y = 450;

		    turretPos10.x = 915;
		    turretPos10.y = -25;

		    turretPos11.x = 1065;
		    turretPos11.y = -25;

		    turretPos12.x = 1375;
		    turretPos12.y = -25;

		    turretPos13.x = 1525;
		    turretPos13.y = -25;

		    turretPos14.x = 2700;
		    turretPos14.y = 625;

		    turretPos15.x = 2500;
		    turretPos15.y = 800;

		    turretPos16.x = 2765;
		    turretPos16.y = 850;

		    bkgdRect.x = 0;
		    bkgdRect.y = -700;

		    PickupPos.x = 50;
		    PickupPos.y = 500;

		    HealthPickupPos.x = 125;
		    HealthPickupPos.y = 500;

		    EnemyPos.x = 200;
		    EnemyPos.y = 300;

		    LakePos.x = 185;
		    LakePos.y = -525;

		    DockPos.x = 85;
		    DockPos.y = -485;

		    SDL_Rect TreePos;
		    TreePos.x = 250;
		    TreePos.y = 650;

		    TreePos2.x = 400;
		    TreePos2.y = 650;

		    TreePos3.x = 525;
		    TreePos3.y = 625;

		    TreePos4.x = 525;
		    TreePos4.y = 725;

		    TreePos5.x = 575;
		    TreePos5.y = 800;

		    TreePos6.x = 550;
		    TreePos6.y = 925;

		    TreePos7.x = 465;
		    TreePos7.y = 875;

		    TreePos8.x = 400;
		    TreePos8.y = 785;

		    TreePos9.x = 300;
		    TreePos9.y = 725;

		    TreePos10.x = 235;
		    TreePos10.y = 800;

		    TreePos11.x = 235;
		    TreePos11.y = 925;

		    TreePos12.x = 335;
		    TreePos12.y = 875;

		    TreePos13.x = 400;
		    TreePos13.y = 975;

		    TreePos14.x = 2750;
		    TreePos14.y = 850;

		    TreePos15.x = 2600;
		    TreePos15.y = 835;

		    TreePos16.x = 2585;
		    TreePos16.y = 755;

		    TreePos17.x = 2675;
		    TreePos17.y = 765;

		    TreePos18.x = 2780;
		    TreePos18.y = 750;

		    TreePos19.x = 2400;
		    TreePos19.y = -250;

		    TreePos20.x = 1435;
		    TreePos20.y = -655;

		    TreePos21.x = 1000;
		    TreePos21.y = -660;

			player1.FullPos.w = 239;

			game = true;

			while(game)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = false;
						game = false;
						break;
					}
					else
					{
						if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

							switch (e.key.keysym.sym) {

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
								if (fire == true)
								{
									fire = false;
								if (pBulletActive == false) {
									if (ammo >= 0)
									{
										ammo--;
									}
									dropPos.x = PlayerPos.x;
									dropPos.y = (-10 + PlayerPos.y + (PlayerPos.h / 2));

									if (PlayerPos.x < turretPos.x) {
										pBulletDir = 5;
									}
									else {
										pBulletDir = 5;
									}
									if (ammo >= 0)
									{
										pBulletActive = true;
									}
								}
								if (Pfront == true)
								{
									fireDown = true;
									fireUp = false;
									fireRight = false;
									fireLeft = false;
								}
								if (Pback == true)
								{
									fireDown = false;
									fireUp = true;
									fireRight = false;
									fireLeft = false;
								}
								if (Pright == true)
								{
									fireDown = false;
									fireUp = false;
									fireRight = true;
									fireLeft = false;
								}
								if (Pleft == true)
								{
									fireDown = false;
									fireUp = false;
									fireRight = false;
									fireLeft = true;
								}

								break;
								}
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

					LakePos.x -=pVelX;

					DockPos.x -=pVelX;

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

					turretPos.x -= pVelX;
					turretPos2.x -= pVelX;
					turretPos3.x -= pVelX;
					turretPos4.x -= pVelX;
					turretPos5.x -= pVelX;
					turretPos6.x -= pVelX;
					turretPos7.x -= pVelX;
					turretPos8.x -= pVelX;
					turretPos9.x -= pVelX;
					turretPos10.x -= pVelX;
					turretPos11.x -= pVelX;
					turretPos12.x -= pVelX;
					turretPos13.x -= pVelX;
					turretPos14.x -= pVelX;
					turretPos15.x -= pVelX;
					turretPos16.x -= pVelX;
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

					LakePos.x -=pVelX;

					DockPos.x -=pVelX;

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

					turretPos.x -= pVelX;
					turretPos2.x -= pVelX;
					turretPos3.x -= pVelX;
					turretPos4.x -= pVelX;
					turretPos5.x -= pVelX;
					turretPos6.x -= pVelX;
					turretPos7.x -= pVelX;
					turretPos8.x -= pVelX;
					turretPos9.x -= pVelX;
					turretPos10.x -= pVelX;
					turretPos11.x -= pVelX;
					turretPos12.x -= pVelX;
					turretPos13.x -= pVelX;
					turretPos14.x -= pVelX;
					turretPos15.x -= pVelX;
					turretPos16.x -= pVelX;
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
						 SDL_HasIntersection(&PlayerPos, &TreePos21)|| SDL_HasIntersection(&PlayerPos, &LakePos)){

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

					LakePos.y -=pVelY;

					DockPos.y -=pVelY;

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

					turretPos.y -= pVelY;
					turretPos2.y -= pVelY;
					turretPos3.y -= pVelY;
					turretPos4.y -= pVelY;
					turretPos5.y -= pVelY;
					turretPos6.y -= pVelY;
					turretPos7.y -= pVelY;
					turretPos8.y -= pVelY;
					turretPos9.y -= pVelY;
					turretPos10.y -= pVelY;
					turretPos11.y -= pVelY;
					turretPos12.y -= pVelY;
					turretPos13.y -= pVelY;
					turretPos14.y -= pVelY;
					turretPos15.y -= pVelY;
					turretPos16.y -= pVelY;
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

					LakePos.y -=pVelY;

					DockPos.y -=pVelY;

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

					turretPos.y -= pVelY;
					turretPos2.y -= pVelY;
					turretPos3.y -= pVelY;
					turretPos4.y -= pVelY;
					turretPos5.y -= pVelY;
					turretPos6.y -= pVelY;
					turretPos7.y -= pVelY;
					turretPos8.y -= pVelY;
					turretPos9.y -= pVelY;
					turretPos10.y -= pVelY;
					turretPos11.y -= pVelY;
					turretPos12.y -= pVelY;
					turretPos13.y -= pVelY;
					turretPos14.y -= pVelY;
					turretPos15.y -= pVelY;
					turretPos16.y -= pVelY;
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
						 SDL_HasIntersection(&PlayerPos, &TreePos21) || SDL_HasIntersection(&PlayerPos, &LakePos)||
						 SDL_HasIntersection(&PlayerPos, &DockPos)){

					PlayerPos.y -= pVelY;
				}

				////////////////////////////////////////////Turrets - Start/////////////////////////////////

				///////////////////////////////////Turret1- Start//////////////////////////////////////////
				double distancex = ((turretPos.x + (turretPos.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos.x + (turretPos.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey = ((turretPos.y + (turretPos.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos.y + (turretPos.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance = sqrt(distancex + distancey);

				if( calcdistance <= 255){

					turretActive = true;

					int random_number = std::rand()%100;

					if((eBulletActive) == false && (random_number == 5)){

						beePos.x = turretPos.x;
						beePos.y = (turretPos.y + (turretPos.h/2));

						if(PlayerPos.x < turretPos.x){
							eBulletDir = -1;
						}else{
							eBulletDir = 1;
						}

						eBulletActive = true;
					}
				} else{

					turretActive = false;
				}

				if(eBulletActive){
					beePos.x += eBulletDir;
				}

				if(beePos.x > 1024 || beePos.x < 0){
					eBulletActive = false;
					beePos.x = -200;
					beePos.y = -200;
					eBulletDir = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos)){

					eBulletActive = false;
					beePos.x = -200;
					beePos.y = -200;
					eBulletDir = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos, &dropPos) && turretActive == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth -=1;

					if(turretHealth == 0)
					{
						turretPos.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos, &dropPos) && turretActive == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}
				///////////////////////////////////Turret1- End//////////////////////////////////////////

				///////////////////////////////////Turret2- Start//////////////////////////////////////////
				double distancex2 = ((turretPos2.x + (turretPos2.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos2.x + (turretPos2.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey2 = ((turretPos2.y + (turretPos2.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos2.y + (turretPos2.h / 2))
										- (turretPos4.y + (turretPos4.h / 2)));

				double calcdistance2 = sqrt(distancex2 + distancey2);

				if( calcdistance2 <= 255){

					turretActive2 = true;

					int random_number2 = std::rand()%100;

					if((eBulletActive2) == false && (random_number2 == 5)){

						beePos2.x = turretPos2.x;
						beePos2.y = (turretPos2.y + (turretPos2.h/2));

						if(PlayerPos.x < turretPos2.x){
							eBulletDir2 = -1;
						}else{
							eBulletDir2 = 1;
						}

						eBulletActive2 = true;
					}
				} else{

					turretActive2 = false;
				}

				if(eBulletActive2){
					beePos2.x += eBulletDir2;
				}

				if(beePos2.x > 1024 || beePos2.x < 0){
					eBulletActive2 = false;
					beePos2.x = -200;
					beePos2.y = -200;
					eBulletDir2 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos2)){

					eBulletActive2 = false;
					beePos2.x = -200;
					beePos2.y = -200;
					eBulletDir2 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos2, &dropPos) && turretActive2 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth2 -=1;

					if(turretHealth2 == 0)
					{
						turretPos2.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos2, &dropPos) && turretActive2 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret2 - End//////////////////////////////////////////

				///////////////////////////////////Turret3 - Start//////////////////////////////////////////
				double distancex3 = ((turretPos3.x + (turretPos3.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos3.x + (turretPos3.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey3 = ((turretPos3.y + (turretPos3.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos3.y + (turretPos3.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance3 = sqrt(distancex3 + distancey3);

				if( calcdistance3 <= 255){

					turretActive3 = true;

					int random_number3 = std::rand()%100;

					if((eBulletActive3) == false && (random_number3 == 5)){

						beePos3.x = turretPos3.x;
						beePos3.y = (turretPos3.y + (turretPos3.h/2));

						if(PlayerPos.x < turretPos3.x){
							eBulletDir3 = -1;
						}else{
							eBulletDir3 = 1;
						}

						eBulletActive3 = true;
					}
				} else{

					turretActive3 = false;
				}

				if(eBulletActive3){
					beePos3.x += eBulletDir3;
				}

				if(beePos3.x > 1024 || beePos3.x < 0){
					eBulletActive3 = false;
					beePos3.x = -200;
					beePos3.y = -200;
					eBulletDir3 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos3)){

					eBulletActive3 = false;
					beePos3.x = -200;
					beePos3.y = -200;
					eBulletDir3 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos3, &dropPos) && turretActive3 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth3 -=1;

					if(turretHealth3 == 0)
					{
						turretPos3.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos3, &dropPos) && turretActive3 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret3 - End//////////////////////////////////////////

				///////////////////////////////////Turret4 - Start//////////////////////////////////////////
				double distancex4 = ((turretPos4.x + (turretPos4.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos4.x + (turretPos4.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey4 = ((turretPos4.y + (turretPos4.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos4.y + (turretPos4.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance4 = sqrt(distancex4 + distancey4);

				if( calcdistance4 <= 255){

					turretActive4 = true;

					int random_number4 = std::rand()%100;

					if((eBulletActive4) == false && (random_number4 == 5)){

						beePos4.x = turretPos4.x;
						beePos4.y = (turretPos4.y + (turretPos4.h/2));

						if(PlayerPos.x < turretPos4.x){
							eBulletDir4 = -1;
						}else{
							eBulletDir4 = 1;
						}

						eBulletActive4 = true;
					}
				} else{

					turretActive4 = false;
				}

				if(eBulletActive4){
					beePos4.x += eBulletDir4;
				}

				if(beePos4.x > 1024 || beePos4.x < 0){
					eBulletActive4 = false;
					beePos4.x = -200;
					beePos4.y = -200;
					eBulletDir4 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos4)){

					eBulletActive4 = false;
					beePos4.x = -200;
					beePos4.y = -200;
					eBulletDir4 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos4, &dropPos) && turretActive4 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth4 -=1;

					if(turretHealth4 == 0)
					{
						turretPos4.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos4, &dropPos) && turretActive4 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}
				///////////////////////////////////Turret4 - End//////////////////////////////////////////

				///////////////////////////////////Turret5 - Start//////////////////////////////////////////
				double distancex5 = ((turretPos5.x + (turretPos5.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos5.x + (turretPos5.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey5 = ((turretPos5.y + (turretPos5.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos5.y + (turretPos5.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance5 = sqrt(distancex5 + distancey5);

				if( calcdistance5 <= 255){

					turretActive5 = true;

					int random_number5 = std::rand()%100;

					if((eBulletActive5) == false && (random_number5 == 5)){

						beePos5.x = turretPos5.x;
						beePos5.y = (turretPos5.y + (turretPos5.h/2));

						if(PlayerPos.x < turretPos5.x){
							eBulletDir5 = -1;
						}else{
							eBulletDir5 = 1;
						}

						eBulletActive5 = true;
					}
				} else{

					turretActive5 = false;
				}

				if(eBulletActive5){
					beePos5.x += eBulletDir5;
				}

				if(beePos5.x > 1024 || beePos5.x < 0){
					eBulletActive5 = false;
					beePos5.x = -200;
					beePos5.y = -200;
					eBulletDir5 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos5)){

					eBulletActive5 = false;
					beePos5.x = -200;
					beePos5.y = -200;
					eBulletDir5 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos5, &dropPos) && turretActive5 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth5 -=1;

					if(turretHealth5 == 0)
					{
						turretPos5.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos5, &dropPos) && turretActive5 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret5 - End//////////////////////////////////////////

				///////////////////////////////////Turret6 - Start//////////////////////////////////////////
				double distancex6 = ((turretPos6.x + (turretPos6.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos6.x + (turretPos6.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey6 = ((turretPos6.y + (turretPos6.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos6.y + (turretPos6.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance6 = sqrt(distancex6 + distancey6);

				if( calcdistance6 <= 255){

					turretActive6 = true;

					int random_number6 = std::rand()%100;

					if((eBulletActive6) == false && (random_number6 == 5)){

						beePos6.x = turretPos6.x;
						beePos6.y = (turretPos6.y + (turretPos6.h/2));

						if(PlayerPos.y < turretPos6.y){
							eBulletDir6 = -1;
						}else{
							eBulletDir6 = 1;
						}

						eBulletActive6 = true;
					}
				} else{

					turretActive6 = false;
				}

				if(eBulletActive6){
					beePos6.y += eBulletDir6;
				}

				if(beePos6.y > 768 || beePos6.y < 0){
					eBulletActive6 = false;
					beePos6.x = -200;
					beePos6.y = -200;
					eBulletDir6 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos6)){

					eBulletActive6 = false;
					beePos6.x = -200;
					beePos6.y = -200;
					eBulletDir6 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos6, &dropPos) && turretActive6 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth6 -=1;

					if(turretHealth6 == 0)
					{
						turretPos6.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos6, &dropPos) && turretActive6 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}
				///////////////////////////////////Turret6 - End//////////////////////////////////////////

				///////////////////////////////////Turret7 - Start//////////////////////////////////////////
				double distancex7 = ((turretPos7.x + (turretPos7.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos7.x + (turretPos7.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey7 = ((turretPos7.y + (turretPos7.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos7.y + (turretPos7.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance7 = sqrt(distancex7 + distancey7);

				if( calcdistance7 <= 255){

					turretActive7 = true;

					int random_number7 = std::rand()%100;

					if((eBulletActive7) == false && (random_number7 == 5)){

						beePos7.x = turretPos7.x;
						beePos7.y = (turretPos7.y + (turretPos7.h/2));

						if(PlayerPos.y < turretPos7.y){
							eBulletDir7 = -1;
						}else{
							eBulletDir7 = 1;
						}

						eBulletActive7 = true;
					}
				} else{

					turretActive7 = false;
				}

				if(eBulletActive7){
					beePos7.y += eBulletDir7;
				}

				if(beePos7.y > 768 || beePos7.y < 0){
					eBulletActive7 = false;
					beePos7.x = -200;
					beePos7.y = -200;
					eBulletDir7 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos7)){

					eBulletActive7 = false;
					beePos7.x = -200;
					beePos7.y = -200;
					eBulletDir7 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos7, &dropPos) && turretActive7 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth7 -=1;

					if(turretHealth7 == 0)
					{
						turretPos7.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos7, &dropPos) && turretActive7 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret7 - End//////////////////////////////////////////

				///////////////////////////////////Turret8 - Start//////////////////////////////////////////
				double distancex8 = ((turretPos8.x + (turretPos8.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos8.x + (turretPos8.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey8 = ((turretPos8.y + (turretPos8.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos8.y + (turretPos8.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance8 = sqrt(distancex8 + distancey8);

				if( calcdistance8 <= 255){

					turretActive8 = true;

					int random_number8 = std::rand()%100;

					if((eBulletActive8) == false && (random_number8 == 5)){

						beePos8.x = turretPos8.x;
						beePos8.y = (turretPos8.y + (turretPos8.h/2));

						if(PlayerPos.y < turretPos8.y){
							eBulletDir8 = -1;
						}else{
							eBulletDir8 = 1;
						}

						eBulletActive8 = true;
					}
				} else{

					turretActive8 = false;
				}

				if(eBulletActive8){
					beePos8.y += eBulletDir8;
				}

				if(beePos8.y > 768 || beePos8.y < 0){
					eBulletActive8 = false;
					beePos8.x = -200;
					beePos8.y = -200;
					eBulletDir8 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos8)){

					eBulletActive8 = false;
					beePos8.x = -200;
					beePos8.y = -200;
					eBulletDir8 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos8, &dropPos) && turretActive8 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth8 -=1;

					if(turretHealth8 == 0)
					{
						turretPos8.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos8, &dropPos) && turretActive8 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret8 - End//////////////////////////////////////////

				///////////////////////////////////Turret9 - Start//////////////////////////////////////////
				double distancex9 = ((turretPos9.x + (turretPos9.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos9.x + (turretPos9.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey9 = ((turretPos9.y + (turretPos9.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos9.y + (turretPos9.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance9 = sqrt(distancex9 + distancey9);

				if( calcdistance9 <= 255){

					turretActive9 = true;

					int random_number9 = std::rand()%100;

					if((eBulletActive9) == false && (random_number9 == 5)){

						beePos9.x = turretPos9.x;
						beePos9.y = (turretPos9.y + (turretPos9.h/2));

						if(PlayerPos.y < turretPos9.y){
							eBulletDir9 = -1;
						}else{
							eBulletDir9 = 1;
						}

						eBulletActive9 = true;
					}
				} else{

					turretActive9 = false;
				}

				if(eBulletActive9){
					beePos9.y += eBulletDir9;
				}

				if(beePos9.y > 768 || beePos9.y < 0){
					eBulletActive9 = false;
					beePos9.x = -200;
					beePos9.y = -200;
					eBulletDir9 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos9)){

					eBulletActive9 = false;
					beePos9.x = -200;
					beePos9.y = -200;
					eBulletDir9 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos9, &dropPos) && turretActive9 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth9 -=1;

					if(turretHealth9 == 0)
					{
						turretPos9.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos9, &dropPos) && turretActive9 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret9 - End//////////////////////////////////////////

				///////////////////////////////////Turret10 - Start//////////////////////////////////////////
				double distancex10 = ((turretPos10.x + (turretPos10.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos10.x + (turretPos10.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey10 = ((turretPos10.y + (turretPos10.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos10.y + (turretPos10.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance10 = sqrt(distancex10 + distancey10);

				if( calcdistance10 <= 255){

					turretActive10 = true;

					int random_number10 = std::rand()%100;

					if((eBulletActive10) == false && (random_number10 == 5)){

						beePos10.x = turretPos10.x;
						beePos10.y = (turretPos10.y + (turretPos10.h/2));

						if(PlayerPos.y < turretPos10.y){
							eBulletDir10 = -1;
						}else{
							eBulletDir10 = 1;
						}

						eBulletActive10 = true;
					}
				} else{

					turretActive10 = false;
				}

				if(eBulletActive10){
						beePos10.y += eBulletDir10;
				}

				if(beePos10.y > 768 || beePos10.y < 0){
					eBulletActive10 = false;
					beePos10.x = -200;
					beePos10.y = -200;
					eBulletDir10 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos10)){

					eBulletActive10 = false;
					beePos10.x = -200;
					beePos10.y = -200;
					eBulletDir10 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos10, &dropPos) && turretActive10 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth10 -=1;

					if(turretHealth10 == 0)
					{
						turretPos10.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos10, &dropPos) && turretActive10 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret10 - End//////////////////////////////////////////

				///////////////////////////////////Turret11 - Start//////////////////////////////////////////
				double distancex11 = ((turretPos11.x + (turretPos11.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos11.x + (turretPos11.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey11 = ((turretPos11.y + (turretPos11.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos11.y + (turretPos11.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance11 = sqrt(distancex11 + distancey11);

				if( calcdistance11 <= 255){

					turretActive11 = true;

					int random_number11 = std::rand()%100;

					if((eBulletActive11) == false && (random_number11 == 5)){

						beePos11.x = turretPos11.x;
						beePos11.y = (turretPos11.y + (turretPos11.h/2));

						if(PlayerPos.y < turretPos11.y){
							eBulletDir11 = -1;
						}else{
							eBulletDir11 = 1;
						}

						eBulletActive11 = true;
					}
				} else{

					turretActive11 = false;
				}

				if(eBulletActive11){
					beePos11.y += eBulletDir11;
				}

				if(beePos11.y > 768 || beePos11.y < 0){
					eBulletActive11 = false;
					beePos11.x = -200;
					beePos11.y = -200;
					eBulletDir11 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos11)){

					eBulletActive11 = false;
					beePos11.x = -200;
					beePos11.y = -200;
					eBulletDir11 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos11, &dropPos) && turretActive11 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth11 -=1;

					if(turretHealth11 == 0)
					{
						turretPos11.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos11, &dropPos) && turretActive11 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}
				///////////////////////////////////Turret11 - End//////////////////////////////////////////

				///////////////////////////////////Turret12 - Start//////////////////////////////////////////
				double distancex12 = ((turretPos12.x + (turretPos12.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos12.x + (turretPos12.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey12 = ((turretPos12.y + (turretPos12.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos12.y + (turretPos12.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance12 = sqrt(distancex12 + distancey12);

				if( calcdistance12 <= 255){

					turretActive12 = true;

					int random_number12 = std::rand()%100;

					if((eBulletActive12) == false && (random_number12 == 5)){

						beePos12.x = turretPos12.x;
						beePos12.y = (turretPos12.y + (turretPos12.h/2));

						if(PlayerPos.y < turretPos12.y){
							eBulletDir12 = -1;
						}else{
							eBulletDir12 = 1;
						}

						eBulletActive12 = true;
					}
				} else{

					turretActive12 = false;
				}

				if(eBulletActive12){
					beePos12.y += eBulletDir12;
				}

				if(beePos12.y > 768 || beePos12.y < 0){
					eBulletActive12 = false;
					beePos12.x = -200;
					beePos12.y = -200;
					eBulletDir12 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos12)){

					eBulletActive12 = false;
					beePos12.x = -200;
					beePos12.y = -200;
					eBulletDir12 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos12, &dropPos) && turretActive12 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth12 -=1;

					if(turretHealth12 == 0)
					{
						turretPos12.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos12, &dropPos) && turretActive12 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret12 - End//////////////////////////////////////////

				///////////////////////////////////Turret13 - Start//////////////////////////////////////////
				double distancex13 = ((turretPos13.x + (turretPos13.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos13.x + (turretPos13.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey13 = ((turretPos13.y + (turretPos13.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos13.y + (turretPos13.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance13 = sqrt(distancex13 + distancey13);

				if( calcdistance13 <= 255){

					turretActive13 = true;

					int random_number13 = std::rand()%100;

					if((eBulletActive13) == false && (random_number13 == 5)){

						beePos13.x = turretPos13.x;
						beePos13.y = (turretPos13.y + (turretPos13.h/2));

						if(PlayerPos.x < turretPos13.x){
							eBulletDir13 = -1;
						}else{
							eBulletDir13 = 1;
						}

						eBulletActive13 = true;
					}
				} else{

					turretActive13 = false;
				}

				if(eBulletActive13){
					beePos13.y += eBulletDir13;
				}

				if(beePos13.y > 768 || beePos13.y < 0){
					eBulletActive13 = false;
					beePos13.x = -200;
					beePos13.y = -200;
					eBulletDir13 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos13)){

					eBulletActive13 = false;
					beePos13.x = -200;
					beePos13.y = -200;
					eBulletDir13 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos13, &dropPos) && turretActive13 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth -=1;

					if(turretHealth13 == 0)
					{
						turretPos13.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos13, &dropPos) && turretActive13 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret13 - End//////////////////////////////////////////

				///////////////////////////////////Turret14 - Start//////////////////////////////////////////
				double distancex14 = ((turretPos14.x + (turretPos14.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos14.x + (turretPos14.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey14 = ((turretPos14.y + (turretPos14.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos14.y + (turretPos14.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance14 = sqrt(distancex14 + distancey14);

				if( calcdistance14 <= 255){

					turretActive14 = true;

					int random_number14 = std::rand()%100;

					if((eBulletActive14) == false && (random_number14 == 5)){

						beePos14.x = turretPos14.x;
						beePos14.y = (turretPos14.y + (turretPos14.h/2));

						if(PlayerPos.x < turretPos14.x){
							eBulletDir14 = -1;
						}else{
							eBulletDir14 = 1;
						}

						eBulletActive14 = true;
					}
				} else{

					turretActive14 = false;
				}

				if(eBulletActive14){
					beePos14.y += eBulletDir14;
				}

				if(beePos14.y > 768 || beePos14.y < 0){
					eBulletActive14 = false;
					beePos14.x = -200;
					beePos14.y = -200;
					eBulletDir14 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos14)){

					eBulletActive14 = false;
					beePos14.x = -200;
					beePos14.y = -200;
					eBulletDir14 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos14, &dropPos) && turretActive14 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth14 -=1;

					if(turretHealth14 == 0)
					{
						turretPos14.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos14, &dropPos) && turretActive14 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}
				///////////////////////////////////Turret14 - End//////////////////////////////////////////

				///////////////////////////////////Turret15 - Start//////////////////////////////////////////
				double distancex15 = ((turretPos15.x + (turretPos15.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos15.x + (turretPos15.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey15 = ((turretPos15.y + (turretPos15.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos15.y + (turretPos15.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance15 = sqrt(distancex15 + distancey15);

				if( calcdistance15 <= 255){

					turretActive15 = true;

					int random_number15 = std::rand()%100;

					if((eBulletActive15) == false && (random_number15 == 5)){

						beePos15.x = turretPos15.x;
						beePos15.y = (turretPos15.y + (turretPos15.h/2));

						if(PlayerPos.x < turretPos15.x){
							eBulletDir15 = -1;
						}else{
							eBulletDir15 = 1;
						}

						eBulletActive15 = true;
					}
				} else{

					turretActive15 = false;
				}

				if(eBulletActive15){
					beePos15.x += eBulletDir15;
				}

				if(beePos15.x > 1024 || beePos15.x < 0){
					eBulletActive15 = false;
					beePos15.x = -200;
					beePos15.y = -200;
					eBulletDir15 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos15)){

					eBulletActive15 = false;
					beePos15.x = -200;
					beePos15.y = -200;
					eBulletDir15 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos15, &dropPos) && turretActive15 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth15 -=1;

					if(turretHealth15 == 0)
					{
						turretPos15.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos15, &dropPos) && turretActive15 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}

				///////////////////////////////////Turret15 - End//////////////////////////////////////////

				///////////////////////////////////Turret16 - Start//////////////////////////////////////////
				double distancex16 = ((turretPos16.x + (turretPos16.w /2))
						- (PlayerPos.x + (PlayerPos.w / 2)))
								*((turretPos16.x + (turretPos16.w / 2))
										- (PlayerPos.x + (PlayerPos.w / 2)));

				double distancey16 = ((turretPos16.y + (turretPos16.h /2))
						- (PlayerPos.y + (PlayerPos.h / 2)))
								*((turretPos16.y + (turretPos16.h / 2))
										- (PlayerPos.y + (PlayerPos.h / 2)));

				double calcdistance16 = sqrt(distancex16 + distancey16);

				if( calcdistance16 <= 255){

					turretActive16 = true;

					int random_number16 = std::rand()%100;

					if((eBulletActive16) == false && (random_number16 == 5)){

						beePos16.x = turretPos16.x;
						beePos16.y = (turretPos16.y + (turretPos16.h/2));

						if(PlayerPos.x < turretPos16.x){
							eBulletDir16 = -1;
						}else{
							eBulletDir16 = 1;
						}

						eBulletActive16 = true;
					}
				} else{

					turretActive16 = false;
				}

				if(eBulletActive16){
					beePos16.y += eBulletDir16;
				}

				if(beePos16.y > 768 || beePos16.y < 0){
					eBulletActive16 = false;
					beePos16.x = -200;
					beePos16.y = -200;
					eBulletDir16 = 0;
				}

				if(SDL_HasIntersection(&PlayerPos, &beePos16)){

					eBulletActive16 = false;
					beePos16.x = -200;
					beePos16.y = -200;
					eBulletDir16 = 0;

					player1.FullPos.w -= 11.95;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}

				if(SDL_HasIntersection(&turretPos16, &dropPos) && turretActive16 == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					turretHealth16 -=1;

					if(turretHealth16 == 0)
					{
						turretPos16.x = -200;
					}
				}

				if(SDL_HasIntersection(&turretPos16, &dropPos) && turretActive16 == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}
				///////////////////////////////////Turret16 - End//////////////////////////////////////////

				////////////////////////////////////////////Turrets - End/////////////////////////////////


				////////////////////////////////////////////Enemy - Start/////////////////////////////////

				////////////////////////////////////////////Enemy1 - Start/////////////////////////////////
				double Enemydistancex = (EnemyPos.x - PlayerPos.x) * (EnemyPos.x - PlayerPos.x);
				double Enemydistancey = (EnemyPos.y - PlayerPos.y) * (EnemyPos.y - PlayerPos.y);

				double Enemycalcdistance = sqrt(Enemydistancex + Enemydistancey);

				if(Enemycalcdistance <= 255){
					enemyActive = true;

					if(PlayerPos.x < EnemyPos.x)
					{
						Left = true;
						Right = false;
					}
					else
					{
						Left = false;
						Right = true;
					}
				}else{
					enemyActive = false;
				}

				if(enemyActive)
				{

				}

				if(SDL_HasIntersection(&EnemyPos, &dropPos) && enemyActive == true){
					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;

					enemyHealth -=1;

					if(enemyHealth == 0)
					{
						EnemyPos.x = -200;
					}
				}

				if(SDL_HasIntersection(&EnemyPos, &dropPos) && enemyActive == false){

					pBulletActive = false;
					dropPos.x = -200;
					dropPos.y = -200;
					pBulletDir = 0;
				}
				////////////////////////////////////////////Enemy1 - End/////////////////////////////////

				////////////////////////////////////////////Enemy - End/////////////////////////////////

				if(fireRight == true)
				{
					if (pBulletActive) {
						dropPos.x += pBulletDir;
					}
				}

				if (fireLeft == true)
				{
					if (pBulletActive) {
						dropPos.x -= pBulletDir;
					}
				}

				if (fireUp == true)
				{
					if (pBulletActive) {
						dropPos.y -= pBulletDir;
					}
				}

				if (fireDown == true)
				{
					if (pBulletActive) {
						dropPos.y += pBulletDir;
					}
				}

				if(dropPos.x > 1024 || dropPos.x < 0){
					pBulletActive = false;
					fire = true;
					dropPos.x = -100;
					dropPos.y = -100;
					pBulletDir = 0;
				}

				if (dropPos.y > 768 || dropPos.y < 0) {
					pBulletActive = false;
					fire = true;
					dropPos.x = -100;
					dropPos.y = -100;
					pBulletDir = 0;
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

				if(player1.FullPos.w <= 120)
				{
					if( SDL_HasIntersection(&PlayerPos, &HealthPickupPos)) {

						HealthPickupPos.x = -1000;
						player1.FullPos.w += 60;
					}
				}

				if( SDL_HasIntersection(&PlayerPos, &EnemyPos)) {

					player1.FullPos.w -=.025;

					if(player1.FullPos.w <= 0)
					{
						player1.FullPos.w = 0;
						game = false;
						gameState = LOSE;
						break;
					}
				}



				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, bkgd, NULL, &bkgdRect);


				SDL_RenderCopy(renderer, HealthPickup, NULL, &HealthPickupPos);

				SDL_RenderCopy(renderer, Pickup, NULL, &PickupPos);


				SDL_RenderCopy(renderer, Pen, NULL, &PenPos);

				SDL_RenderCopy(renderer, Will, NULL, &WillPos);

				SDL_RenderCopy(renderer, Gun, NULL, &GunPos);

				SDL_RenderCopy(renderer, Lake, NULL, &LakePos);

				SDL_RenderCopy(renderer, Dock, NULL, &DockPos);

				if(eBulletActive){
					SDL_RenderCopy(renderer, bee, NULL, &beePos);
				}

				if(eBulletActive2){
					SDL_RenderCopy(renderer, bee, NULL, &beePos2);
				}

				if(eBulletActive3){
					SDL_RenderCopy(renderer, bee, NULL, &beePos3);
				}

				if(eBulletActive4){
					SDL_RenderCopy(renderer, bee, NULL, &beePos4);
				}

				if(eBulletActive5){
					SDL_RenderCopy(renderer, bee, NULL, &beePos5);
				}

				if(eBulletActive6){
					SDL_RenderCopy(renderer, bee, NULL, &beePos6);
				}

				if(eBulletActive7){
					SDL_RenderCopy(renderer, bee, NULL, &beePos7);
				}

				if(eBulletActive8){
					SDL_RenderCopy(renderer, bee, NULL, &beePos8);
				}

				if(eBulletActive9){
					SDL_RenderCopy(renderer, bee, NULL, &beePos9);
				}

				if(eBulletActive10){
					SDL_RenderCopy(renderer, bee, NULL, &beePos10);
				}

				if(eBulletActive11){
					SDL_RenderCopy(renderer, bee, NULL, &beePos11);
				}

				if(eBulletActive12){
					SDL_RenderCopy(renderer, bee, NULL, &beePos12);
				}

				if(eBulletActive13){
					SDL_RenderCopy(renderer, bee, NULL, &beePos13);
				}

				if(eBulletActive14){
					SDL_RenderCopy(renderer, bee, NULL, &beePos14);
				}

				if(eBulletActive15){
					SDL_RenderCopy(renderer, bee, NULL, &beePos15);
				}

				if(eBulletActive16){
					SDL_RenderCopy(renderer, bee, NULL, &beePos16);
				}

				if(pBulletActive){
					SDL_RenderCopy(renderer, drop, NULL, &dropPos);
				}

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

				SDL_RenderCopy(renderer, turret, NULL, &turretPos);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos2);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos3);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos4);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos5);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos6);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos7);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos8);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos9);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos10);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos11);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos12);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos13);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos14);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos15);
				SDL_RenderCopy(renderer, turret, NULL, &turretPos16);


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

				player1.Draw(renderer);

				if(Right == true)
				{
					SDL_RenderCopy(renderer, Enemy, NULL, &EnemyPos);
				}
				if(Left == true)
				{
					SDL_RenderCopy(renderer, Enemy2, NULL, &EnemyPos);
				}
				SDL_RenderPresent(renderer);
				}
			break;

		case WIN:
			win = true;

			while(win)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = false;
						win = false;
						break;
					}

					{
						if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

							switch (e.key.keysym.sym) {

							case SDLK_p:
								win = false;
								gameState = GAME;
								break;

							case SDLK_q:
								quit = false;
								win = false;
								break;
							}
						}
					}
				}

				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, Win, NULL, &titlePos);

				SDL_RenderPresent(renderer);
			}
			break;

		case LOSE:
			lose = true;

			while(lose)
			{
				while(SDL_PollEvent(&e) != 0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = false;
						lose = false;
						break;
					}

					else
					{
						if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {

							switch (e.key.keysym.sym) {

							case SDLK_p:
								lose = false;
								gameState = GAME;
								break;

							case SDLK_q:
								quit = false;
								lose = false;
								break;
							}
						}
					}
				}

				SDL_RenderClear(renderer);

				SDL_RenderCopy(renderer, Lose, NULL, &titlePos);

				SDL_RenderPresent(renderer);
			}
			break;

		SDL_Delay(16);
		break;
		}
	}


    // The window is open: could enter program loop here (see SDL_PollEvent())

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}

