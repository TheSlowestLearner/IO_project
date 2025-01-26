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

private:

    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::RectangleShape startButton; // Graficzny przycisk "Start", trzeba zamienic xd
    bool isStartClicked;
    
};