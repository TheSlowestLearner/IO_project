#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"
#include "GameScene.h"
#include "Player.h"
#include "Inventory.h"
#include <vector>

class ShopScene : public Scene {
public:
    ShopScene(std::shared_ptr<WindowHandler> handler);

    void Render(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;

    void SetPlayer(Player* player);

private:

    sf::Font font;
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Sprite exitButtonSprite;
    sf::Texture exitButtonTexture;
    sf::RectangleShape offerPlace; //Do zamiany na sprite
    sf::RectangleShape itemFrame; //Do zamiany na sprite
    sf::Sprite buttonSprite;             // Sprite przycisku
    sf::Texture buttonTexture;

    std::shared_ptr<WindowHandler> windowHandler;

    std::vector<std::unique_ptr<sf::Texture>> itemTextures;
    std::vector<std::unique_ptr<sf::Sprite>> itemSprites;
  
    //std::shared_ptr<Inventory> inventory;
    Player* player;

    // Opisy przedmiotów
    std::vector<sf::Text> itemDescriptions;                // Teksty opisów
    std::vector<std::string> itemDescriptionStrings = {    // Tre?ci opisów
        "Piwo: +15 sanity,-10 zdrowia",
        "Kawa: +5 energii",
        "Sa?atka: +10 zdrowia",
        "Papier toaletowy: +10 energii"
    };
    bool isClicked = false;
    int itemId = 0;
    int LocationIndex;
};

