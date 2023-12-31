#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 16));
	m_velocity.setX(0);
	if (m_currentFrame == 0 || m_currentFrame == 8)
	{
		m_velocity.setX(-XSPD);
	}
	else if(m_currentFrame < 8)
	{
		m_velocity.setY(YSPD);
	}
	else
	{
		m_velocity.setY(-YSPD);
	}

	SDLGameObject::update();
}