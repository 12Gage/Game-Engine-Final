#include <string>
#include <iostream>
#include "math.h"
using namespace std;

#if defined(__APPLE__)
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#endif

#if defined(_WIN32) || (_WIN64)
#include "SDL.h"
#include "SDL_image.h"
#endif


class Drop{

public:

	bool active;

	SDL_Texture *texture;

	SDL_Rect dropRect;

	float DROP_VEL;

	int pVelX, pVelY;

	SDL_Point turret, player;

	float distance;

	float tankangle;

	Drop(SDL_Renderer *renderer, string filePath, float x, float y);

	void Update(float deltaTime);

	void Draw(SDL_Renderer *renderer);

	void Reset();

	void Start(SDL_Rect playerPos, SDL_Rect turretPos);

};
