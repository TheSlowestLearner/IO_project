#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"


class GameScene : public Scene {
public:
    GameScene();

    void Render(sf::RenderWindow& window) override;
    //void Update(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;

private:

    //Wy�wietlanie gracza:
    sf::Sprite playerSprite; 
    sf::Texture playerTexture;
    Animator* playerAnimator;

    //Wy�wietlanie Lokacji:
    sf::Sprite locationSprite;
    sf::Texture locationTexture;
    sf::Sprite academicSprite;
    sf::Sprite biedronkaSprite;
    sf::Sprite studenciakSprite;
    sf::Sprite halaSprite;
    sf::Sprite wimiipSprite;
    sf::Sprite miasteczkoSprite;
    sf::Sprite librarySprite;
    
    //T�o
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
}; 
