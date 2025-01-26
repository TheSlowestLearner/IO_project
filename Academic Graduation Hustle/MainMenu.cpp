//#include "Scene.h"
#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu() : isStartClicked(false) 
{
    startButton.setPosition(850, 450);               //Zamienic na sprite faktyczny
    startButton.setSize(sf::Vector2f(200, 50));     
    startButton.setFillColor(sf::Color::Blue);      

    if (!backgroundTexture.loadFromFile("graphics/menu_background.png")) //Bedzie trzeba zamieniæ na inny
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);
}

void MainMenu::Render(sf::RenderWindow& window)
{
    window.draw(startButton); 
}

void MainMenu::Update() 
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();

    if (startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        startButton.setSize(sf::Vector2f(250, 100));
        //std::cout << ("Mouse is over ") << std::endl;
    }
    else
    {
        startButton.setSize(sf::Vector2f(200, 50));
    }
}

void MainMenu::HandleMouseClick(int x, int y) 
{
    if (startButton.getGlobalBounds().contains(x, y)) 
    {
        std::cout << "Start clicked!" << std::endl;
        isStartClicked = true;
    }
}

bool MainMenu::IsStartClicked() const 
{
    return isStartClicked;
}