#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"


class GameScene : public Scene {
public:
    //GameScene();
    GameScene(std::shared_ptr<WindowHandler> handler);

    void Render(sf::RenderWindow& window) override;
    void Update() override;
    void HandleMouseClick(int x, int y) override;


private:

    //Wyœwietlanie gracza:
    sf::Sprite playerSprite; 
    sf::Texture playerTexture;
    Animator* playerAnimator;

    //Wyœwietlanie Lokacji:
    sf::Sprite locationSprite;
    sf::Texture locationTexture;
    sf::Sprite academicSprite;
    sf::Sprite biedronkaSprite;
    sf::Sprite studenciakSprite;
    sf::Sprite halaSprite;
    sf::Sprite wimiipSprite;
    sf::Sprite miasteczkoSprite;
    sf::Sprite librarySprite;
    
    //T³o
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    //Ekwipunek
    sf::Sprite equipmentSprite;
    sf::Texture equipmentTexture;

    std::shared_ptr<WindowHandler> windowHandler;

}; 
