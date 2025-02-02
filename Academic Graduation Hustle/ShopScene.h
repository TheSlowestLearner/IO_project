#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"
#include "GameScene.h"
#include <vector>

class ShopScene : public Scene {
public:
    ShopScene(std::shared_ptr<WindowHandler> handler);

    void Render(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;


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

    int LocationIndex;

    std::shared_ptr<WindowHandler> windowHandler;

    std::vector<std::unique_ptr<sf::Texture>> itemTextures;
    std::vector<std::unique_ptr<sf::Sprite>> itemSprites;

    // Opisy przedmiotów
    std::vector<sf::Text> itemDescriptions;                // Teksty opisów
    std::vector<std::string> itemDescriptionStrings = {    // Treœci opisów
        "Piwo: +15 sanity,-10 zdrowia",
        "Kawa: +5 energii",
        "Sa³atka: +10 zdrowia",
        "Papier toaletowy: +10 energii"
    };

};
