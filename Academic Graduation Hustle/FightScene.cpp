#include "FightScene.h"
#include "WindowHandler.h"
#include "GameScene.h"
#include "Scene.h"
#include <iostream>

FightScene::FightScene(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    if (!backgroundTexture.loadFromFile("graphics/background.png")) //Bedzie trzeba zamieniæ na inny
        throw std::runtime_error("Background texture not found!");
    if (!enemyTexture.loadFromFile("graphics/enemy_sprite_sheet.png"))
        throw std::runtime_error("Enemy texture not found!");
    if (!playerTexture.loadFromFile("graphics/player_sprite_sheet.png"))
        throw std::runtime_error("Player texture not found!");
    if (!buttonTexture.loadFromFile("graphics/spritesheet_placeholder.png"))
        throw std::runtime_error("Button texture not found!");

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);


    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(1005, 480);
    enemySprite.setScale(-4.5f,4.5f);

    enemySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    enemyAnimator = new Animator(enemySprite, { 32, 32 }, 7, 0, 2);

    
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(385, 480);    
    playerSprite.setScale(4.5f, 4.5f);

    playerSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
    playerAnimator = new Animator(playerSprite, { 32, 32 }, 7, 1, 2);

    
    attackButton.setTexture(buttonTexture);
    attackButton.setPosition(200, 800);
    attackButton.setScale(4.f, 4.f);

    itemButton.setTexture(buttonTexture);
    itemButton.setPosition(600, 800);
    itemButton.setScale(4.f, 4.f);

    // tymczasowe rozwi¹zanie dopóki nie bdzie sprite'ów przycisków
    {
        attackButton.setTextureRect({ 1500,100,24,8 });
        itemButton.setTextureRect({ 1500,1700,24,8 });
    }
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