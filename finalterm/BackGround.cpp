#include "BackGround.h"

BackGround::BackGround(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void BackGround::update()
{
	//스크롤링 실수로 작동 X
	m_velocity.setX(-10);

	if (m_position.getX() <= -640)
	{
		m_position.setX(640);
	}
}