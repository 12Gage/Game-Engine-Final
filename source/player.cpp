#include "player.h"

//tank creation
Player::Player(SDL_Renderer *renderer, int pNum, string filePath, float x, float y)
{
	active = true;

    Empty = IMG_LoadTexture(renderer, (filePath + "HealthEmpty.png").c_str());
    Full = IMG_LoadTexture(renderer, (filePath + "HealthFull.png").c_str());

    EmptyPos.x = FullPos.x = 10;
    EmptyPos.y = FullPos.y = 50;
    EmptyPos.w = FullPos.w = 239;
    EmptyPos.h = FullPos.h = 32;

	playerNum = pNum;

	PLAYER_VEL = 3.5;

	pVelX = 0;
	pVelY = 0;

	if(playerNum == 0){
		playerPath = filePath + "Player.png";
	}
	if(playerNum == 1)
	{
		playerPath = filePath + "PlayerR.png";
	}
	if(playerNum == 2)
	{
		playerPath = filePath + "PlayerL.png";
	}
	if(playerNum == 3)
	{
		playerPath = filePath + "PlayerB.png";
	}

	texture = IMG_LoadTexture(renderer, playerPath.c_str());

	posRect.x = x;
	posRect.y = y;
	posRect.w = 28;
	posRect.h = 56;

	center.x = posRect.w/2;
	center.y = posRect.h/2;

	string bulletPath;

	if(playerNum == 0){
		bulletPath = filePath + "drop3.png";
	}
	if(playerNum == 1)
	{
		bulletPath = filePath + "drop.png";
	}
	if(playerNum == 2)
	{
		bulletPath = filePath + "drop2.png";
	}
	if(playerNum == 3)
	{
		bulletPath = filePath + "drop3.png";
	}

}

void Player::Update(float deltaTime)
{
	if(playerNum == 0){
		tankangle = atan2(Yvalue,Xvalue) * 180/3.14;

		oldAngle = tankangle;

		float radians = (tankangle * 3.14)/180;

		float move_x = PLAYER_VEL *cos(radians);
		float move_y = PLAYER_VEL *sin(radians);

		pVelX += (move_x) * deltaTime;
		pVelY += (move_y) * deltaTime;

		posRect.x = (int)(pVelX + 0.5f);
		posRect.y = (int)(pVelY + 0.5f);

	}else {
		tankangle = oldAngle;
	}

	if(posRect.x < 0){
		posRect.x = 0;
		pVelX = posRect.x;
	}

	if(posRect.x > 1024 - posRect.w){
		posRect.x = 1024 - posRect.w;
		pVelX = posRect.x;
	}

	if(posRect.y < 0){
		posRect.y = 0;
		pVelY = posRect.y;
	}

	if(posRect.y > 768 - posRect.h){
		posRect.y = 768 - posRect.h;
		pVelY = posRect.y;
	}
}

void Player::Draw(SDL_Renderer *renderer)
{

	//SDL_RenderCopy(renderer, texture, NULL, &posRect);

	SDL_RenderCopy(renderer, Empty, NULL, &EmptyPos);
	SDL_RenderCopy(renderer, Full, NULL, &FullPos);

}
