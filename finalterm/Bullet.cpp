#include "Bullet.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Bullet::update()
{
	m_velocity.setX(5);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));

	SDLGameObject::update();
}