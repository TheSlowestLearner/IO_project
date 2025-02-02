#include "WindowHandler.h"
#include "MainMenu.h"
#include <iostream>
#include <random>

WindowHandler::WindowHandler()
    : window(sf::VideoMode(1920, 1080), "Academic Graduation Hustle") {
    // Losowanie semestru przy uruchomieniu
    RandomizeSemester();
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

    // Renderowanie górnego paska tylko poza MainMenu
    if (std::dynamic_pointer_cast<MainMenu>(currentScene) == nullptr)
    {
        topBar.Render(window);
    }

    window.display();
}

void WindowHandler::Update()
{
    if (currentScene)
    {
        currentScene->Update();
    }

    // Aktualizacja dynamicznych elementów paska
    topBar.UpdateTime(currentTime);  // Przekazanie aktualnego czasu
    topBar.UpdateSemester(currentSemester);  // Przekazanie aktualnego semestru

    //// Generowanie losowego semestru w zakresie od 1 do 5
    //std::random_device rd;   // Pobranie losowego ziarna
    //std::mt19937 gen(rd());  // Silnik losowy
    //std::uniform_int_distribution<> dis(1, 5); // Zakres losowania: od 1 do 5

    //currentSemester = dis(gen); // Przypisanie losowego semestru

    // Symulacja dynamicznych zmian czasu (opcjonalne)
    currentTime = "21:37"; // Aktualny czas systemowy lub gry
}

bool WindowHandler::IsRunning() const 
{
    return window.isOpen();
}

std::shared_ptr<Scene> WindowHandler::GetCurrentScene() const 
{
    return currentScene;
}

//Pozycja Gracza
void WindowHandler::SetPlayerPosition(const sf::Vector2f& position)
{
    lastPlayerPosition = position;
}

sf::Vector2f WindowHandler::GetPlayerPosition() const
{
    return lastPlayerPosition;
}

//Lokacja
void WindowHandler::SetShopIndex(const int index)
{
    LocationIndex = index;
}

int WindowHandler::GetShopIndex() const
{
    return LocationIndex;
}

// Losowanie semestru
void WindowHandler::RandomizeSemester()
{
    static std::random_device rd;   // Pobranie losowego ziarna
    //static std::mt19937 gen(static_cast<unsigned>(std::time(nullptr)));
    //std::uniform_int_distribution<> dis(1, 5); // Zakres losowania: od 1 do 5

    //currentSemester = dis(gen); // Przypisanie losowego semestru
    currentSemester = 3;
    //currentSemester = rand() % 5 + 1;
}

void WindowHandler::CloseScene()
{
    window.close();
}