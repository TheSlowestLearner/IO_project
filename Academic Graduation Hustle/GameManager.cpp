#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "MainMenu.h"
#include "GameScene.h"
//#include "Scene.h"

Player GameManager::player;

GameManager::GameManager() {
    windowHandler = std::make_shared<WindowHandler>();
}

void GameManager::Run() {
    std::shared_ptr<MainMenu> mainMenu = std::make_shared<MainMenu>();
    windowHandler->SetScene(mainMenu);

    while (windowHandler->IsRunning()) {
        windowHandler->ProcessEvents();
        windowHandler->Update();

        if (auto currentScene = std::dynamic_pointer_cast<MainMenu>(windowHandler->GetCurrentScene())) 
        {
            if (currentScene->IsStartClicked()) 
            {
                std::shared_ptr<GameScene> gameScene = std::make_shared<GameScene>(windowHandler);
                windowHandler->SetScene(gameScene);
            }
            if (currentScene->IsExitClicked())
            {
                windowHandler->CloseScene();
            }
        }

        windowHandler->Render();
    }
}