#include "player.h"

Player::Player(SDL_Renderer *renderer, int pNum, string filePath, float x, float y)
{
	back = IMG_LoadTexture(renderer, (filePath + "HealthEmpty.png").c_str());
	front = IMG_LoadTexture(renderer, (filePath + "HealthFull.png").c_str());

	backR.x = frontR.x = 10;
	backR.y = frontR.y = 50;
	backR.w = frontR.w = 239;
	backR.h = frontR.h = 32;

	playerHealth = 100.f;
	maxHealth = 100.0f;

	active = true;

	playerNum = pNum;

	speed = 200.0f;

	if(playerNum == 0){

		playerPath = filePath + "Player.png";
	}

	texture = IMG_LoadTexture(renderer, playerPath.c_str());

	posRect.x = x;
	posRect.y = y;
	posRect.w = 26;
	posRect.h = 58;

	pos_X = x;
	pos_Y = y;

	center.x = posRect.w/2;
	center.y = posRect.h/2;

	string bulletPath;

	//see if this is player 1 or player 2, and create the correct file path
	/*if(playerNum == 0){
		//create the bullet 1 texture
		bulletPath = filePath + "redBullet.png";
	}*/

}


void Player::Update(float deltaTime)
{
	if(Xvalue != 0 || Yvalue != 0){

		tankangle = atan2(Yvalue,Xvalue) * 180/3.14;

		oldAngle = tankangle;

		float radians = (tankangle * 3.14)/180;

		float move_x = speed *cos(radians);
		float move_y = speed *sin(radians);

		pos_X += (move_x) * deltaTime;
		pos_Y += (move_y) * deltaTime;

		posRect.x = (int)(pos_X + 0.5f);
		posRect.y = (int)(pos_Y + 0.5f);

	}else {
		tankangle = oldAngle;
	}

	if(posRect.x < 0){
		posRect.x = 0;
		pos_X = posRect.x;
	}

	if(posRect.x > 1024 - posRect.w){
		posRect.x = 1024 - posRect.w;
		pos_X = posRect.x;
	}

	if(posRect.y < 0){
		posRect.y = 0;
		pos_Y = posRect.y;
	}

	if(posRect.y > 768 - posRect.h){
		posRect.y = 768 - posRect.h;
		pos_Y = posRect.y;
	}

	/*
	//update the tank's bullets
	  for(int i = 0; i< bulletList.size(); i++)
	  {
		  //check to see if the bullet is active
		  if(bulletList[i].active){

			  //update bullet
			  bulletList[i].Update(deltaTime);
		  }
	  }
	  */
}


void Player::Draw(SDL_Renderer *renderer)
{
	/*
	//draw the player's bullets
	for(int i = 0; i < bulletList.size(); i++)
	{
		//check to see if the bullet is active
		if(bulletList[i].active){

			//draw bullet
			bulletList[i].Draw(renderer);
		}
	}
	*/

	SDL_RenderCopyEx(renderer, texture, NULL, &posRect, tankangle, &center, SDL_FLIP_NONE);

	SDL_RenderCopy(renderer, back, NULL, &backR);
	SDL_RenderCopy(renderer, front, NULL, &frontR);

}
