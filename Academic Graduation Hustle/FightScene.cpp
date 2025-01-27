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
    attackButton.setTextureRect({ 1500,100,200,80 });
    attackButton.setPosition(200, 800);
    attackButton.setScale(1.f, 1.f);

    itemButton.setTexture(buttonTexture);
    itemButton.setTextureRect({ 1500,1700,200,80 });
    itemButton.setPosition(600, 800);
    itemButton.setScale(1.f, 1.f);

    // przyciski korzystaj¹ z placeholdera
}


void FightScene::Update()
{
    playerAnimator->Update(0.016f);
    enemyAnimator->Update(0.016f);

    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f mouseWorldPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (attackButton.getGlobalBounds().contains(mouseWorldPosition))
        attackButton.setColor({ 100,100,100 });
    else
        attackButton.setColor({ 255,255,255 });

    if (itemButton.getGlobalBounds().contains(mouseWorldPosition))
        itemButton.setColor({ 100,100,100 });
    else
        itemButton.setColor({ 255,255,255 });

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
    window.draw(backgroundSprite);
    window.draw(playerSprite);
    window.draw(enemySprite);
    window.draw(attackButton);
    window.draw(itemButton);
}

void FightScene::HandleMouseClick(int x, int y) {}