#include "drop.h"

//bullet creation method
Drop::Drop(SDL_Renderer *renderer, string filePath, float x, float y)
{
	active = false;

	DROP_VEL = 3.5;

	texture = IMG_LoadTexture(renderer, filePath.c_str());

	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	posRect.w = w;
	posRect.h = h;

	posRect.x = x;
	posRect.y = y;
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
	posRect.x = -1000;

	pVelX = posRect.x;

	active = false;
}

void Drop::Draw(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &posRect);
}

void Drop::Update(float deltaTime)
{
	float vX = ((player.x - 32) - turret.x) / distance;
	float vY = ((player.y - 32) - turret.y) / distance;

	pVelX += (vX * DROP_VEL * deltaTime);
	pVelY += (vY * DROP_VEL * deltaTime);

	posRect.x = (int)(pVelX + 0.5f);
	posRect.y = (int)(pVelY + 0.5f);

	if ((posRect.y < (0 - posRect.h)) || (posRect.y > 768) || (posRect.x < (0 - posRect.w)) || (posRect.x > 1024)) {
		Reset();
	}
}
