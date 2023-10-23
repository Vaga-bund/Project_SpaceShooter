#include "Game.h"
#include "GameStateMachine.h"
#include "MenuState.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

        if (m_pWindow != 0)
        {
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (!TheTextureManager::Instance()->load("Assets/bullet.png", "bullet", m_pRenderer))
            {
                return false;
            }
            m_pGameStateMachine = new GameStateMachine();
            m_pGameStateMachine->changeState(MenuState::Instance());
        }
        else
        {
            return false;
        }
    }
    else {
        return false;
    }
    m_bRunning = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::update()
{
    m_pGameStateMachine->update();
}