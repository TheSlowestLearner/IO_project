#pragma once
#include "Tasks.h"
#include "WindowHandler.h"
#include "MainMenu.h"
#include "GameScene.h"
#include "ShopScene.h"
#include "FightScene.h"
#include <memory>

class GameManager {
public:
    GameManager();
    void Run(); 

    Player player;

private:
    std::shared_ptr<WindowHandler> windowHandler; 
};