#include "BackGround.h"

BackGround::BackGround(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void BackGround::update()
{
	//��ũ�Ѹ� �Ǽ��� �۵� X
	m_velocity.setX(-10);

	if (m_position.getX() <= -640)
	{
		m_position.setX(640);
	}
}