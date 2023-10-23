#include "Game.h"
#include "PauseState.h"
#include "MenuState.h"
#include "MenuButton.h"

PauseState* PauseState::s_pInstance = NULL;
const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->load("Assets/resume.png", "resumebutton", TheGame::Instance()->getRenderer()))
		return false;
	if (!TheTextureManager::Instance()->load("Assets/main.png", "mainbutton", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"), s_resumePlay);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering PauseState\n";

	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

	std::cout << "exiting PauseState\n";

	return true;
}