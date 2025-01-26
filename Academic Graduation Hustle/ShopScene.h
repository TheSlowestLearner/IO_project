#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"
#include "GameScene.h"

class ShopScene : public Scene {
public:
    ShopScene(std::shared_ptr<WindowHandler> handler);

    void Render(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;


private:

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::RectangleShape exitButton; 
    sf::RectangleShape offerPlace; //Do zamiany na sprite
    sf::RectangleShape itemFrame; //Do zamiany na sprite
    sf::RectangleShape exchangeButton; //Do zamiany na sprite
    sf::RectangleShape exchangeButton2;

    int LocationIndex;

    std::shared_ptr<WindowHandler> windowHandler;

};
