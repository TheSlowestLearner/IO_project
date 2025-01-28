#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"
#include "GameScene.h"
#include "Player.h"

class Inventory : public Scene {
public:
    Inventory(std::shared_ptr<WindowHandler> handler);

    void Render(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;
    void UploadPlayer(Player *player);

private:
    bool isClicked = false;
    int itemId=0;
    Player *player1;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Sprite ItemsSprite[12];
    sf::Texture ItemsTexture[12];
    sf::RectangleShape exitButton;  //Do zamiany na sprite
    sf::RectangleShape rightButton; //Do zamiany na sprite
    sf::RectangleShape leftButton;  //Do zamiany na sprite
    sf::RectangleShape useButton;   //Do zamiany na sprite
    sf::Font randomFont;
    sf::Text itemsValue;
    std::shared_ptr<WindowHandler> windowHandler;

};
