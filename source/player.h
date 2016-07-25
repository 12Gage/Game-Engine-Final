#if defined(__APPLE__)
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"

#endif

#if defined(_WIN32) || (_WIN64)
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#endif

//needed includes
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Player{

public:
	SDL_Texture *back, *front;

	SDL_Rect backR, frontR;

	float playerHealth, maxHealth;

	bool active;

	string playerPath;

	int playerNum;

	SDL_Texture *texture;

	SDL_Rect posRect;

	float speed;

	float pos_X, pos_Y;

	float x, y, tankangle;

	SDL_Point center;

	float oldAngle;

	Sint16 Xvalue, Yvalue;

	Player (SDL_Renderer *renderer, int pNum, string filePath, float x, float y);

	void Update(float deltaTime);

	void Draw(SDL_Renderer * renderer);

	void Reset();

private:


};
