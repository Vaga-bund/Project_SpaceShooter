#include "PlayState.h"
#include "Game.h"
#include "GameOverState.h"
#include "BackGround.h"
#include "GameClearState.h"
#include "SoundManager.h"

PlayState* PlayState::s_pInstance = NULL;
const std::string PlayState::s_playID = "PLAY";

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/spaceship-alpha.png", "player", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/spaceshipenemy.png", "enemy", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/BackGround.png", "background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	// 2개의 배경(스크롤링이 목적)
	GameObject* background = new BackGround(new LoaderParams(0, 0, 640, 480, "background"));
	m_gameObjects.push_back(background);
	background = new BackGround(new LoaderParams(640, 0, 640, 480, "background"));
	// 플레이어
	GameObject* player = new Player(new LoaderParams(50, 30, 64, 64, "player"));
	
	m_gameObjects.push_back(background);
	m_gameObjects.push_back(player);
	// 적의 각 위치와 각자의 객체 생성
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			m_gameObjects.push_back(new Enemy(new LoaderParams(450 + 70 * i, 40 + 50 * j, 34, 32, "enemy")));
		}
	}

	SoundManager::Instance()->loadMusic("assets/PlayMusic.mp3");
	
	std::cout << "entering PlayState\n";
	return true;
}

void PlayState::update()
{
	SoundManager::Instance()->playMusic();

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
		for (int j = i + 1; j < m_gameObjects.size(); j++) {
			// 플레이어와 적과의 충돌 -> 충돌이 있으면 게임 오버
			/* 버그로 인해 주석
			if (dynamic_cast<SDLGameObject*>(m_gameObjects[i])->getID() == "player" && dynamic_cast<SDLGameObject*>(m_gameObjects[j])->getID() == "enemy")
			{
				if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[i]), dynamic_cast<SDLGameObject*>(m_gameObjects[j])))
				{
					TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
				}
			}
			*/
			// 총알과 적과의 충돌 -> 충돌시에 2개의 객체 삭제
			if (dynamic_cast<SDLGameObject*>(m_gameObjects[i])->getID() == "enemy" && dynamic_cast<SDLGameObject*>(m_gameObjects[j])->getID() == "bullet")
			{
				if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[i]), dynamic_cast<SDLGameObject*>(m_gameObjects[j])))
				{
					m_gameObjects.erase(m_gameObjects.begin() + i);
					m_gameObjects.erase(m_gameObjects.begin() + j - 1);
				}
			}
		}
		// 모든 적이 없어지면 게임 클리어로 변경
		if (dynamic_cast<SDLGameObject*>(m_gameObjects[i])->getID() == "player" && dynamic_cast<SDLGameObject*>(m_gameObjects[i + 1])->getID() == "bullet")
		{
			TheGame::Instance()->getStateMachine()->changeState(GameClearState::Instance());
			break;
		}
	}
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheTextureManager::Instance()->clearFromTextureMap("player");
	TheTextureManager::Instance()->clearFromTextureMap("enemy");
	TheTextureManager::Instance()->clearFromTextureMap("bullet");

	SoundManager::Instance()->clean();

	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB, rightA, rightB;
	int topA, topB, bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) return false;
	if (topA >= bottomB) return false;
	if (rightA <= leftB) return false;
	if (leftA >= rightB) return false;

	return true;
}