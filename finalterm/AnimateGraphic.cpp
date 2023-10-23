#include "AnimatedGraphic.h"
#include "Game.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 0;
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 16));
}