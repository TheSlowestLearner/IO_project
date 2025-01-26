#include "WindowHandler.h"
#include <iostream>

WindowHandler::WindowHandler()
    : window(sf::VideoMode(1920, 1080), "Academic Graduation Hustle") {
}

void WindowHandler::SetScene(std::shared_ptr<Scene> scene) 
{
    currentScene = scene;
}

void WindowHandler::ProcessEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed && currentScene) 
        {
            currentScene->HandleMouseClick(event.mouseButton.x, event.mouseButton.y);
        }
    }
}

void WindowHandler::Render() 
{
    window.clear();

    if (currentScene) 
    { 
       currentScene->Render(window); 
    }

    window.display();
}

void WindowHandler::Update()
{
    if (currentScene)
    {
        currentScene->Update();
    }
}

bool WindowHandler::IsRunning() const 
{
    return window.isOpen();
}

std::shared_ptr<Scene> WindowHandler::GetCurrentScene() const 
{
    return currentScene;
}