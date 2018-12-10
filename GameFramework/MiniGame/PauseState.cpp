#include "PauseState.h"
#include "States.h"
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuButton.h"
#include <iostream>

PauseState* PauseState::pInstance = nullptr;
const std::string PauseState::pauseID = "PAUSE";

bool PauseState::OnEnter()
{
    if (!TextureManager::Instance()->Load("../assets/resume.png", "resumebutton"))
    {
        return false;
    }
    if (!TextureManager::Instance()->Load("../assets/main.png", "mainbutton"))
    {
        return false;
    }
    GameObject* button1 = new MenuButton(new LoaderParams(864 / 2 - 100, 150, 200, 80, "mainbutton"), PauseToMain);
    GameObject* button2 = new MenuButton(new LoaderParams(864 / 2 - 100, 300, 200, 80, "resumebutton"), ResumePlay);
    gameObjects.push_back(button1);
    gameObjects.push_back(button2);
    std::cout << "entering PauseState\n";

    return true;
}

bool PauseState::OnExit()
{
    for (std::vector<GameObject*>::size_type i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Clean();
    }
    gameObjects.clear();
    TextureManager::Instance()->ClearFromTextureMap("resumebutton");
    TextureManager::Instance()->ClearFromTextureMap("mainbutton");
    InputHandler::Instance()->Reset();
    std::cout << "exiting PauseState\n";

    return true;
}

void PauseState::PauseToMain()
{
    Game::Instance()->GetStateMachine()->ChangeState(MenuState::Instance());
}

void PauseState::ResumePlay()
{
    Game::Instance()->GetStateMachine()->PopState();
}