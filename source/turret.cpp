#include "turret.h"

Turrent::Turrent(SDL_Renderer *renderer, string filePath, float x, float y)
{
	active = true;

	string basePath = filePath + "turret.png";

	//load the image into the texture
	tBase = IMG_LoadTexture(renderer, basePath.c_str());


	baseRect.x = x;
	baseRect.y = y;

	int w, h;
	SDL_QueryTexture(tBase, NULL, NULL, &w, &h);
	baseRect.w = 100;
	baseRect.h = 100;

	center.x = 32;
	center.y = 32;

	string bulletPath = filePath + "bee.png";


	for(int i = 0; i < 10; i++)
	{
		TurretBullet tmpBullet(renderer, bulletPath, 1500, 1500);

		bulletList.push_back(tmpBullet);
	}


	srand(time_t(NULL));

	posB_X = baseRect.x;
	posB_Y = baseRect.y;

}

void Turrent::TankMoveX(float tankSpeed, float deltaTime)
{
	posB_X += (tankSpeed) * deltaTime;
	posT_X += (tankSpeed) * deltaTime;

	baseRect.x = (int)(posB_X + 0.5f);
}

void Turrent::TankMoveY(float tankSpeed, float deltaTime)
{
	posB_Y += (tankSpeed) * deltaTime;
	posT_Y += (tankSpeed) * deltaTime;

	baseRect.y = (int)(posB_Y + 0.5f);
}

void Turrent::Draw(SDL_Renderer *renderer)
{

	for(int i = 0; i < bulletList.size(); i++)
	{
		if(bulletList[i].active){

			bulletList[i].Draw(renderer);
		}
	}


	SDL_RenderCopy(renderer, tBase, NULL, &baseRect);
}

void Turrent::Update(float deltaTime, SDL_Rect tankRect)
{
	x = (tankRect.x + (tankRect.w/2)) - (posRect.x + (baseRect.w/2));
	y = (tankRect.y + (tankRect.h/2)) - (posRect.y + (baseRect.h/2));
	turrentangle = atan2(y,x) * 180 / 3.14;


	if(SDL_GetTicks() > fireTime){

		if(baseRect.x > 0 && baseRect.x < 1024 && baseRect.y > 0 && baseRect.y < 768){
			CreateBullet(tankRect);
		}

		fireTime = SDL_GetTicks() + (rand() % 3+ 1) * 1000;
	}



	for(int i =0; i < bulletList.size(); i ++)
	{
		if(bulletList[i].active){

			bulletList[i].Update(deltaTime);
		}
	}


}


void Turrent::CreateBullet(SDL_Rect target)
{

	for(int i = 0; i < bulletList.size(); i++)
	{
		if(bulletList[i].active == false){

			bulletList[i].Start(target, baseRect);

			bulletList[i].active = true;

			bulletList[i].posRect.x = ((baseRect.x + (baseRect.w/2)) - (bulletList[i].posRect.w/2));
			bulletList[i].posRect.y = ((baseRect.y + (baseRect.h/2)) - (bulletList[i].posRect.h/2));

			bulletList[i].pos_X = bulletList[i].posRect.x;
			bulletList[i].pos_Y = bulletList[i].posRect.y;

			break;
		}
	}
}

