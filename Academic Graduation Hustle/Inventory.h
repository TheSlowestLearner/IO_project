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
    void UploadPlayer(Player* player);

private:
    bool isClicked = false;
    int itemId = 0;
    Player* player1;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Sprite ItemsSprite[12];
    sf::Texture ItemsTexture[12];
    sf::Sprite exitButtonSprite;
    sf::Texture exitButtonTexture;
    sf::Sprite rightButtonSprite;
    sf::Texture rightButtonTexture;
    sf::Sprite leftButtonSprite;
    sf::Texture leftButtonTexture;
    sf::Sprite useButtonSprite;
    sf::Texture useButtonTexture;
    sf::Font randomFont;
    sf::Text itemsValue;
    std::shared_ptr<WindowHandler> windowHandler;

};
