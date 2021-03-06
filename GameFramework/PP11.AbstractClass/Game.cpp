#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "LoaderParams.h"
#include <iostream>

Game* Game::pInstance = 0;

bool Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        if (fullscreen)
        {
            pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
        else
        {
            pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
        }

        if (pWindow != 0)
        {
            pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
        }

        isRunning = true;

        if (!TextureManager::Instance()->Load("../assets/animate-alpha.png", "animate", pRenderer))
        {
            return false;
        }

        gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
        gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

        SDL_SetRenderDrawColor(pRenderer, 0, 40, 60, 255);

    }
    else
    {
        return false;
    }
    return true;
}

void Game::Render()
{
    SDL_RenderClear(pRenderer);
    for (std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->Draw();
    }
    SDL_RenderPresent(pRenderer);
}

void Game::Update()
{
    for (std::vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
    {
        gameObjects[i]->Update();
    }
}

void Game::Clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    SDL_Quit();
}

void Game::HandleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
        }
    }
}