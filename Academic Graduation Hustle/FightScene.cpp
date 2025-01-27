#include "FightScene.h"
#include "WindowHandler.h"
#include "GameScene.h"
#include "Scene.h"
#include <iostream>

FightScene::FightScene(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    if (!backgroundTexture.loadFromFile("graphics/background.png"))
        throw std::runtime_error("Background texture not found!");
    if (!enemyTexture.loadFromFile("graphics/enemy_sprite_sheet.png"))
        throw std::runtime_error("Enemy texture not found!");
    if (!playerTexture.loadFromFile("graphics/player_sprite_sheet.png"))
        throw std::runtime_error("Player texture not found!");
    if (!buttonTexture.loadFromFile("graphics/spritesheet_placeholder.png"))
        throw std::runtime_error("Button texture not found!");

    // t³o
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);

    // przeciwnik
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(1005, 480);
    enemySprite.setScale(-4.5f,4.5f);

    enemySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    enemyAnimator = new Animator(enemySprite, { 32, 32 }, 7, 0, 2);

    // gracz
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(385, 480);    
    playerSprite.setScale(4.5f, 4.5f);

    playerSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
    playerAnimator = new Animator(playerSprite, { 32, 32 }, 7, 1, 2);

    // przyciski
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
    // zmienna tymczasowa (do usuniêcia)
    static unsigned int buttons_pressed = 0;

    // opuszczanie sceny
    if (buttons_pressed > 5)
    {
        buttons_pressed = 0; // do usuniêcia
        this->HandleExit();
    }
    // aktualizacja sceny
    else
    {
        playerAnimator->Update(0.016f);
        enemyAnimator->Update(0.016f);

        // pobranie pozycji kursora
        sf::Vector2i mousePosition = sf::Mouse::getPosition();
        sf::Vector2f mouseWorldPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

        // podœwietlanie przycisków
        if (attackButton.getGlobalBounds().contains(mouseWorldPosition))
            attackButton.setColor({ 100,100,100 });
        else
            attackButton.setColor({ 255,255,255 });

        if (itemButton.getGlobalBounds().contains(mouseWorldPosition))
            itemButton.setColor({ 100,100,100 });
        else
            itemButton.setColor({ 255,255,255 });

        // ogarniêcie funkcjonalnoœci przycisków
        static bool held = false; // czy przycisk myszy jest przytrzymywany?
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !held)
        {
            if (attackButton.getGlobalBounds().contains(mouseWorldPosition))
            {
                this->HandleAttack();
                buttons_pressed++;
            }
            else if (itemButton.getGlobalBounds().contains(mouseWorldPosition))
            {
                this->HandleItem();
                buttons_pressed++;
            }

            held = true;
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            held = false;
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

void FightScene::HandleAttack()
{
    std::cout << "FIGHT SCENE: attack pressed" << std::endl;
}
void FightScene::HandleItem()
{
    std::cout << "FIGHT SCENE: item pressed" << std::endl;
}
void FightScene::HandleExit()
{
    this->windowHandler->SetScene(std::make_shared<GameScene>(windowHandler));
    std::cout << "FIGHT SCENE: over 5 buttons pushed, returning to game scene" << std::endl;
}