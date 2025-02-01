#pragma once
#include "Scene.h"
//#include "WindowHandler.h"
#include <SFML/Graphics.hpp>

class MainMenu : public Scene 
{
public:

    MainMenu();

    void Render(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;

    bool IsStartClicked() const;
    bool IsExitClicked() const;

private:

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Texture startButtonTexture;
    sf::Sprite startButton;
    sf::Texture exitButtonTexture;
    sf::Sprite exitButton;
    sf::Texture logoTexture;
    sf::Sprite logoSprite;

    bool isStartClicked;
    bool isExitClicked;
    
};