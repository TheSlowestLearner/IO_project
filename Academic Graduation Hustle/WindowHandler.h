#pragma once
#include <memory>
#include "Scene.h"
#include "TopBar.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include <string>


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

    // Losowanie semestru
    void RandomizeSemester();

private:
    sf::RenderWindow window;                    
    std::shared_ptr<Scene> currentScene;  

    //Dane przechodz¹ce miêdzy scenami
    sf::Vector2f lastPlayerPosition = sf::Vector2f(0, 0);
    int LocationIndex = -1;

    //ob³uga TopBar
    TopBar topBar;

    //// Dane dynamiczne dla TopBar
    std::string currentTime = "00:00";  // Przyk³adowy czas
    int currentSemester = 1;            // Aktualny semestr
};