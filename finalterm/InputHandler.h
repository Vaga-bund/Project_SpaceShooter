#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE,
	RIGHT
};

class InputHandler
{
private :
	InputHandler();
	static InputHandler* s_pInstance;
	const Uint8* m_keystates = SDL_GetKeyboardState(NULL);
	bool m_keyisDown = false;

	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
public :
	~InputHandler() {}
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	bool isKeyDown(SDL_Scancode key);
	void update();

	bool isKeyOneDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();
	void onMouseMove(SDL_Event event);
	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();
};
typedef InputHandler TheInputHandler;