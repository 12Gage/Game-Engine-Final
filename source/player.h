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

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include <vector>
#include "drop.h"

class Player{

public:

    SDL_Texture *Empty, *Full;
    SDL_Rect EmptyPos, FullPos;

	bool active;

	vector<Drop> bulletList;

	string playerPath;

	int playerNum;

	SDL_Texture *texture;

	SDL_Rect posRect;

	float PLAYER_VEL;

	int pVelX;
	int pVelY;

	SDL_Point center;

	float oldAngle, tankangle;

	Sint16 Xvalue, Yvalue;

	Player (SDL_Renderer *renderer, int pNum, string filePath, float x, float y);

	void Update(float deltaTime);

	void Draw(SDL_Renderer * renderer);

	void CreateBullet();

	void Reset();

private:


};
