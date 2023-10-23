#pragma once
#include "SDLGameObject.h"
#define XSPD 4
#define YSPD 1

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
};