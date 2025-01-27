#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"
#include "GameScene.h"

class FightScene : public Scene
{
public:

    FightScene(std::shared_ptr<WindowHandler> handler);

    void Render(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;

private:

    //Wyœwietlanie gracza:
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    Animator* playerAnimator;

    //T³o
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    //Enemy
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    Animator* enemyAnimator;

    std::shared_ptr<WindowHandler> windowHandler;

    sf::Sprite attackButton;
    sf::Sprite itemButton;
    sf::Texture buttonTexture;
};
