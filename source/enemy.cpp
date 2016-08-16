#include "enemy.h"

EnemyTank::EnemyTank(SDL_Renderer *Renderer, string filepath, float x, float y, int enemyNumber)
{
	active = false;

	string basePath = filepath + "enemy.png";

	eTank = IMG_LoadTexture(Renderer, basePath.c_str());

	eTankRect.x = x;
	eTankRect.y = y;

	int w,h;
	SDL_QueryTexture(eTank,NULL,NULL,&w,&h);
	eTankRect.w = 48;
	eTankRect.h = 36;

	posT_X = eTankRect.x;
	posT_Y = eTankRect.y;

	speed = 100;

	center.x = 24;
	center.y = 18;

	health = 4;
}

void EnemyTank::RemoveHealth()
{
	health -= 1;

	if(health <= 0){
		Reset();
	}
}

void EnemyTank::Reset()
{
	eTankRect.x = -1000;

	posT_X = eTankRect.x;

	health = 10;

	active = false;
}

void EnemyTank::Reset2()
{
	eTankRect.x = x;
	eTankRect.y = y;
}

void EnemyTank::eTankMoveX(float tankSpeed, float deltaTime)
{
	posT_X += (tankSpeed) *deltaTime;

	eTankRect.x = (int)(posT_X + 0.5f);
}

void EnemyTank::eTankMoveY(float tankSpeed, float deltaTime)
{
	posT_Y += (tankSpeed) *deltaTime;

	eTankRect.y = (int)(posT_Y + 0.5f);

}

void EnemyTank::Draw(SDL_Renderer *renderer)
{
	SDL_RenderCopyEx(renderer,eTank,NULL,&eTankRect,tankangle,&center,SDL_FLIP_NONE);
}

void EnemyTank::Update(float deltaTime, SDL_Rect tankRect)
{

	double distancex = (eTankRect.x - tankRect.x) * (eTankRect.x - tankRect.x);
	double distancey = (eTankRect.y - tankRect.y) * (eTankRect.y - tankRect.y);

	double calcdistance = sqrt(distancex + distancey);

	if(calcdistance <= 250){
		active = true;
	}else{
		active = false;
	}

	if(active){
		x = (tankRect.x + (tankRect.w/2)) - (eTankRect.x + (eTankRect.w/2));
		y = (tankRect.y + (tankRect.h/2)) - (eTankRect.y + (eTankRect.h/2));
		tankangle = atan2(y,x) * 180/3.14;

		float radians = (tankangle * 3.14)/180;


		float move_x = speed * cos(radians);
		float move_y = speed * sin(radians);

		posT_X += (move_x) * deltaTime;
		posT_Y += (move_y) * deltaTime;

		eTankRect.x = (int)(posT_X + 0.5f);
		eTankRect.y = (int)(posT_Y + 0.5f);
	}

}
