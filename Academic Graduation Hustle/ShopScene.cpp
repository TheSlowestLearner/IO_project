#include "ShopScene.h"
#include "GameScene.h"
#include <iostream>

ShopScene::ShopScene(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    exitButton.setPosition(150, 300);             
    exitButton.setSize(sf::Vector2f(100, 100));
    exitButton.setFillColor(sf::Color::Blue);

    exchangeButton.setFillColor(sf::Color::Blue);
    exchangeButton2.setFillColor(sf::Color::Blue);

    offerPlace.setFillColor(sf::Color::Green); //Do zamiany na sprite
    itemFrame.setFillColor(sf::Color::Red); //Do zamiany na sprite
    itemFrame.setSize(sf::Vector2f(150, 150));

    if (!backgroundTexture.loadFromFile("graphics/shop_background.png")) 
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);

    //Indexy: Akademik=0, Biblioteka=1, Biedronka=2, Hala=3, Miasteczko=4, Studenciak=5, Wimiip=6
    LocationIndex = windowHandler->GetShopIndex();
}


void ShopScene::Update()
{
    sf::Vector2f currentSize;
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f mouseWorldPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
       if (exitButton.getGlobalBounds().contains(mouseWorldPosition))
       {
            auto newScene = std::make_shared<GameScene>(windowHandler);
            windowHandler->SetScene(newScene);
       }
       if (exitButton.getGlobalBounds().contains(mouseWorldPosition))
       {
           //DOCHODZI DO ZAKUPIENIA/WYMIANY/BUFFA

           //Polecam wykorzystaæ indexy LocationIndex
       }
      
    }

    if (exchangeButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        exchangeButton.setFillColor(sf::Color::Red);
        exchangeButton2.setFillColor(sf::Color::Red);
    }
    else
    {
        exchangeButton.setFillColor(sf::Color::Blue);
        exchangeButton2.setFillColor(sf::Color::Blue);
    }

    if (exchangeButton2.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        exchangeButton2.setFillColor(sf::Color::Red);
    }
    else
    {
        exchangeButton2.setFillColor(sf::Color::Blue);
    }
}

void ShopScene::Render(sf::RenderWindow& window)
{
    //T³o
    window.draw(backgroundSprite);
    window.draw(exitButton);

    //Sklepy: 2,5
    //Buffery: 3,6
    //Wymiany: 0,1,4
    switch (LocationIndex)
    {
    case 0:
    case 1:
    case 4:
        offerPlace.setPosition(350, 300);
        offerPlace.setSize(sf::Vector2f(850, 550));
        window.draw(offerPlace);
        itemFrame.setPosition(550, 400);
        window.draw(itemFrame);
        itemFrame.setPosition(850, 400);
        window.draw(itemFrame);
        exchangeButton.setSize(sf::Vector2f(300, 85));
        exchangeButton.setPosition(625, 700);
        window.draw(exchangeButton);
        break;

    case 2:
    case 5:
        offerPlace.setPosition(350, 300);
        offerPlace.setSize(sf::Vector2f(350, 550));
        window.draw(offerPlace);
        offerPlace.setPosition(750, 300);
        offerPlace.setSize(sf::Vector2f(350, 550));
        window.draw(offerPlace);
        itemFrame.setPosition(850, 400);
        window.draw(itemFrame);
        itemFrame.setPosition(450, 400);
        window.draw(itemFrame);
        exchangeButton.setSize(sf::Vector2f(150, 85));
        exchangeButton2.setSize(sf::Vector2f(150, 85));
        exchangeButton.setPosition(850, 750);
        window.draw(exchangeButton);
        exchangeButton2.setPosition(450, 750);
        window.draw(exchangeButton2);
        break;

    case 3:
    case 6:
        offerPlace.setPosition(350, 300);
        offerPlace.setSize(sf::Vector2f(850, 550));
        window.draw(offerPlace);
        itemFrame.setPosition(700, 400);
        window.draw(itemFrame);
        exchangeButton.setSize(sf::Vector2f(300, 100));
        exchangeButton.setPosition(625,700);
        window.draw(exchangeButton);
        break;

    default:

        std::cout << "Error" << std::endl;
    }
}

void ShopScene::HandleMouseClick(int x, int y)
{ }

