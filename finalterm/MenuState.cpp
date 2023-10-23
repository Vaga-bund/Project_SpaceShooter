#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "BackGround.h"

MenuState* MenuState::s_pInstance = NULL;
const std::string MenuState::s_menuID = "MENU";

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png", "playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/MainBackGround.png", "background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	// 배경설정인데 스크롤링이 할 목적이 아니고 가만히 있는 이미지만 필요해서 SDLGameObject로 구현
	GameObject* background = new SDLGameObject(new LoaderParams(0, 0, 640, 480, "background"));
	// 버튼
	GameObject* button1 = new MenuButton(new LoaderParams(120, 100, 400, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(120, 300, 400, 100, "exitbutton"), s_exitFromMenu);

	m_gameObjects.push_back(background);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	std::cout << "Play button clicked\n";

	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());

}

void MenuState::s_exitFromMenu()
{
	std::cout << "Exit button clicked\n";

	TheGame::Instance()->quit();
}