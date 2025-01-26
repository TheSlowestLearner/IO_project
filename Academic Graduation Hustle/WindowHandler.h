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

private:
    sf::RenderWindow window;                    
    std::shared_ptr<Scene> currentScene;       
};