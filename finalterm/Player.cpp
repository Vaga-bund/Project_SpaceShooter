#include "Player.h"
#include "InputHandler.h"
#include "Bullet.h"
#include "PlayState.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;
}

void Player::update()
{
	// 아무것도 안 누를 때 움직이지 않기
	m_velocity.setX(0);
	m_velocity.setY(0);
	// idle상태
	m_currentFrame = 1;
	handleInput();
	SDLGameObject::update();
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		// 위로 이동 및 최대 이동 값
		m_currentFrame = 3;
		if (m_position.getY() <= 0)
			m_velocity.setY(0);
		else
			m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		// 아래로 이동 및 최대 이동 값
		m_currentFrame = 2;
		if (m_position.getY() >= 420)
			m_velocity.setY(0);
		else
			m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyOneDown(SDL_SCANCODE_SPACE))
	{
		// SPACE를 누를 때 마다 총알 객체 생성
		PlayState::Instance()->pushObject(new Bullet(new LoaderParams(getPosition().getX() + getWidth() - 10, getPosition().getY() + getHeight()/2 + 10, 14, 15, "bullet")));
	}
}