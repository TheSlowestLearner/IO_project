//#include "Scene.h"
#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu() : isStartClicked(false) , isExitClicked(false)
{
    if (!logoTexture.loadFromFile("graphics/title_screen.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    logoSprite.setTexture(logoTexture);
    logoSprite.setPosition(650, 100);
    logoSprite.setScale(8.0f, 8.0f);

    if (!startButtonTexture.loadFromFile("graphics/menu_buttons_sheet.png")) 
    {
        throw std::runtime_error("Texture not found!");
    }
    startButton.setTexture(startButtonTexture);
    startButton.setTextureRect(sf::IntRect(0, 0, 92, 32));
    startButton.setPosition(850, 450);               
    startButton.setScale(2.0f, 2.0f);

    if (!exitButtonTexture.loadFromFile("graphics/menu_buttons_sheet.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    exitButton.setTexture(exitButtonTexture);
    exitButton.setTextureRect(sf::IntRect(92, 0, 92, 32));
    exitButton.setPosition(850, 550);
    exitButton.setScale(2.0f, 2.0f);

    if (!backgroundTexture.loadFromFile("graphics/menu_background.png")) //Bedzie trzeba zamieniæ na inny
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);
}

void MainMenu::Render(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(startButton);    
    window.draw(exitButton);
    window.draw(logoSprite);
}

void MainMenu::Update() 
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();

    if (startButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        startButton.setScale(2.5f, 2.5f);
    }
    else
    {
        startButton.setScale(2.0f, 2.0f);
    }

    if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        exitButton.setScale(2.5f, 2.5f);
    }
    else
    {
        exitButton.setScale(2.0f, 2.0f);
    }
}

void MainMenu::HandleMouseClick(int x, int y) 
{
    if (startButton.getGlobalBounds().contains(x, y)) 
    {
        std::cout << "Start clicked!" << std::endl;
        isStartClicked = true;
    }

    if (exitButton.getGlobalBounds().contains(x, y))
    {
        std::cout << "Exit clicked!" << std::endl;
        isExitClicked = true;
    }
}

bool MainMenu::IsStartClicked() const 
{
    return isStartClicked;
}

bool MainMenu::IsExitClicked() const
{
    return isExitClicked;
}