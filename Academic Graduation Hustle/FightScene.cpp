#include "FightScene.h"
#include "WindowHandler.h"
#include "GameScene.h"
#include "Scene.h"
#include <iostream>

FightScene::FightScene(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    if (!backgroundTexture.loadFromFile("graphics/background.png")) //Bedzie trzeba zamieniæ na inny
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);

    if (!enemyTexture.loadFromFile("graphics/enemy_sprite_sheet.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(1005, 480);
    enemySprite.setScale(-4.5f,4.5f);

    enemySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    enemyAnimator = new Animator(enemySprite, { 32, 32 }, 7, 0, 2);

    if (!playerTexture.loadFromFile("graphics/player_sprite_sheet.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(385, 480);    
    playerSprite.setScale(4.5f, 4.5f);

    playerSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
    playerAnimator = new Animator(playerSprite, { 32, 32 }, 7, 1, 2);
}


void FightScene::Update()
{
    playerAnimator->Update(0.016f);
    enemyAnimator->Update(0.016f);

    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f mouseWorldPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    for (int i = 0; i < 7; i++)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            //if (BUTTON->getGlobalBounds().contains(mouseWorldPosition))
        }
    }
}

void FightScene::Render(sf::RenderWindow& window)
{
    //T³o
    window.draw(backgroundSprite);
    //Gracz
    window.draw(playerSprite);
    //Przeciwnik
    window.draw(enemySprite);
}

void FightScene::HandleMouseClick(int x, int y) {}
