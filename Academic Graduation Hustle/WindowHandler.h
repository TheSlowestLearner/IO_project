#pragma once
#include <memory>
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"

class WindowHandler 
{
public:
    WindowHandler();

    void SetScene(std::shared_ptr<Scene> scene); 
    void ProcessEvents();                        
    void Update();                             
    void Render();                              

    bool IsRunning() const;                     
    std::shared_ptr<Scene> GetCurrentScene() const;

    void SetPlayerPosition(const sf::Vector2f& position);
    sf::Vector2f GetPlayerPosition() const;

    void SetShopIndex(const int index);
    int GetShopIndex() const;

private:
    sf::RenderWindow window;                    
    std::shared_ptr<Scene> currentScene;  

    //Dane przechodz¹ce miêdzy scenami
    sf::Vector2f lastPlayerPosition = sf::Vector2f(0, 0);
    int LocationIndex = -1;
};