#pragma once
#include "SDLGameObject.h"

class LoaderParams;

enum button_state
{
	MOUSE_OUT,
	MOUSE_OVER,
	CLICKED
};

class MenuButton : public SDLGameObject
{
private:
	bool m_bReleased;
	void(*m_callback)();
public:
	MenuButton(const LoaderParams* pParams, void (*callback)());
	virtual void update();
};