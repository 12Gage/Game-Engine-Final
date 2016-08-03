#include "drop.h"

//bullet creation method
Drop::Drop(SDL_Renderer *renderer, string filePath, float x, float y)
{
	active = false;

	DROP_VEL = 3.5;

	texture = IMG_LoadTexture(renderer, filePath.c_str());

	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	dropRect.w = w;
	dropRect.h = h;

	dropRect.x = x;
	dropRect.y = y;
}

void Drop::Start(SDL_Rect playerPos, SDL_Rect turretPos) {

	player.x = playerPos.x;
	player.y = playerPos.y;

	turret.x = turretPos.x;
	turret.y = turretPos.y;

	distance = sqrt((player.x - turret.x * (player.x - turret.x) + (player.y - turret.y) * (player.y - turret.y)));
}

void Drop::Reset()
{
	dropRect.x = -1000;

	pVelX = dropRect.x;

	active = false;
}

void Drop::Draw(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &dropRect);
}

void Drop::Update(float deltaTime)
{
	float vX = ((player.x - 32) - turret.x) / distance;
	float vY = ((player.y - 32) - turret.y) / distance;

	pVelX += (vX * DROP_VEL * deltaTime);
	pVelY += (vY * DROP_VEL * deltaTime);

	dropRect.x = (int)(pVelX + 0.5f);
	dropRect.y = (int)(pVelY + 0.5f);

	if ((dropRect.y < (0 - dropRect.h)) || (dropRect.y > 768) || (dropRect.x < (0 - dropRect.w)) || (dropRect.x > 1024)) {
		Reset();
	}
}
