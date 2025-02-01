#include "ShopScene.h"
#include "GameScene.h"
#include <iostream>
#include <vector>

ShopScene::ShopScene(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    //czcionka
    if (!font.loadFromFile("fonts/VT323-Regular.ttf"))
    {
        throw std::runtime_error("Font not found!");
    }

    //przycisk do kupna
    if (!buttonTexture.loadFromFile("graphics/buy_button2.png"))
    {
        throw std::runtime_error("Button texture not found!");
    }
    buttonSprite.setTexture(buttonTexture);
    buttonSprite.setScale(2.0f, 2.0f);

    //wyjscie ze sceny - przycisk 
    if (!exitButtonTexture.loadFromFile("graphics/exit_button.png"))
    {
        throw std::runtime_error("Exit button texture not found!");
    }
    exitButtonSprite.setTexture(exitButtonTexture);
    exitButtonSprite.setScale(2.0f, 2.0f); 
    exitButtonSprite.setPosition(80, 200);

    offerPlace.setFillColor(sf::Color::Green); //Do zamiany na sprite
    itemFrame.setFillColor(sf::Color::Red); //Do zamiany na sprite
    itemFrame.setSize(sf::Vector2f(150, 150));

    if (!backgroundTexture.loadFromFile("graphics/shop_background.png")) 
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);

    // Dodajê rêczne przypisanie tekstur dla itemków
    std::vector<std::string> itemFiles = {
        "graphics/items/beer.png",
        "graphics/items/coffee.png",
        "graphics/items/salad.png",
        "graphics/items/toilet_paper.png"
    };


    //itemki
    for (const auto& file : itemFiles)
    {
        auto texture = std::make_unique<sf::Texture>();
        if (texture->loadFromFile(file))
        {
            itemTextures.push_back(std::move(texture));

            auto sprite = std::make_unique<sf::Sprite>();
            sprite->setTexture(*itemTextures.back());
            sprite->setScale(1.0f, 1.0f);

            itemSprites.push_back(std::move(sprite));
        }
    }

    //opisy itemków 
    for (const auto& description : itemDescriptionStrings)
    {
        sf::Text text;
        text.setFont(font);
        text.setString(description);
        text.setCharacterSize(30); // Rozmiar tekstu
        text.setFillColor(sf::Color::Black); // Kolor tekstu
        itemDescriptions.push_back(text);
    }

    // Przypisanie pozycji sprite'ów itemków do odpowiadaj¹cych im czerwonych kwadratów
    if (!itemSprites.empty())
    {
        itemSprites[0]->setPosition(700 + (150 - itemSprites[0]->getGlobalBounds().width) / 2,
            400 + (150 - itemSprites[0]->getGlobalBounds().height) / 2);
        if (itemSprites.size() > 1)
        {
            itemSprites[1]->setPosition(850 + (150 - itemSprites[1]->getGlobalBounds().width) / 2,
                400 + (150 - itemSprites[1]->getGlobalBounds().height) / 2);
        }
    }

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
        // Sprawdzenie klikniêcia w przycisk "Exit"
        if (exitButtonSprite.getGlobalBounds().contains(mouseWorldPosition))
        {
            auto newScene = std::make_shared<GameScene>(windowHandler);
            windowHandler->SetScene(newScene);
        }
    }

    if (buttonSprite.getGlobalBounds().contains(mouseWorldPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // Obs³uga klikniêcia przycisku
        std::cout << "Button clicked!" << std::endl;
    }
}

void ShopScene::Render(sf::RenderWindow& window)
{
    //T³o
    window.draw(backgroundSprite);
    window.draw(exitButtonSprite);

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

        // Pierwszy czerwony kwadrat
        itemFrame.setSize(sf::Vector2f(150, 150));
        itemFrame.setPosition(450, 400);
        window.draw(itemFrame);

        // Drugi czerwony kwadrat
        itemFrame.setPosition(750, 400);
        window.draw(itemFrame);

        // Wyœwietlanie itemków 
        if (itemSprites.size() >= 2)
        {
            // Pierwszy itemek
            itemSprites[0]->setScale(5.0f, 5.0f);
            itemSprites[0]->setPosition(
                450 + (150 - itemSprites[0]->getGlobalBounds().width) / 2,
                400 + (150 - itemSprites[0]->getGlobalBounds().height) / 2);
            window.draw(*itemSprites[0]);

            // Drugi itemek
            itemSprites[1]->setScale(5.0f, 5.0f);
            itemSprites[1]->setPosition(
                750 + (150 - itemSprites[1]->getGlobalBounds().width) / 2,
                400 + (150 - itemSprites[1]->getGlobalBounds().height) / 2);
            window.draw(*itemSprites[1]);
        }

        //opis itemka
        itemDescriptions[0].setPosition(700 + (150 - itemDescriptions[0].getLocalBounds().width) / 2, 580);
        window.draw(itemDescriptions[0]);


        // Przycisk wymiany
        buttonSprite.setPosition(680, 700);
        window.draw(buttonSprite);
        break;

    case 2:
    case 5:
        offerPlace.setPosition(350, 300);
        offerPlace.setSize(sf::Vector2f(350, 550));
        window.draw(offerPlace);
        offerPlace.setPosition(750, 300);
        offerPlace.setSize(sf::Vector2f(350, 550));
        window.draw(offerPlace);

        // Pierwszy czerwony kwadrat
        itemFrame.setSize(sf::Vector2f(150, 150));
        itemFrame.setPosition(450, 400);
        window.draw(itemFrame);

        // Drugi czerwony kwadrat
        itemFrame.setPosition(850, 400);
        window.draw(itemFrame);

        // Wyœwietlanie itemków 
        if (itemSprites.size() >= 2)
        {
            // Pierwszy itemek
            itemSprites[0]->setScale(5.0f, 5.0f);
            itemSprites[0]->setPosition(
                450 + (150 - itemSprites[0]->getGlobalBounds().width) / 2,
                400 + (150 - itemSprites[0]->getGlobalBounds().height) / 2);
            window.draw(*itemSprites[0]);
            // Drugi itemek
            itemSprites[1]->setScale(5.0f, 5.0f);
            itemSprites[1]->setPosition(
                850 + (150 - itemSprites[1]->getGlobalBounds().width) / 2,
                400 + (150 - itemSprites[1]->getGlobalBounds().height) / 2);
            window.draw(*itemSprites[1]);
        }

        //opisy itemków
        itemDescriptions[0].setPosition(450 + (150 - itemDescriptions[0].getLocalBounds().width) / 2, 580); // Pod pierwszym przedmiotem
        window.draw(itemDescriptions[0]);

        itemDescriptions[1].setPosition(850 + (150 - itemDescriptions[1].getLocalBounds().width) / 2, 580); // Pod drugim przedmiotem
        window.draw(itemDescriptions[1]);

        // Przyciski wymiany
        buttonSprite.setPosition(828, 750);
        window.draw(buttonSprite);

        buttonSprite.setPosition(428, 750);
        window.draw(buttonSprite);
        break;

    case 3:
    case 6:
        offerPlace.setPosition(350, 300);
        offerPlace.setSize(sf::Vector2f(850, 550));
        window.draw(offerPlace);


        // Jeden czerwony kwadrat
        itemFrame.setSize(sf::Vector2f(150, 150));
        itemFrame.setPosition(700, 400);
        window.draw(itemFrame);

        // Wyœwietlanie tylko jednego itemka
        if (!itemSprites.empty())
        {
            itemSprites[0]->setScale(5.0f, 5.0f);
            itemSprites[0]->setPosition(
                700 + (150 - itemSprites[0]->getGlobalBounds().width) / 2,
                400 + (150 - itemSprites[0]->getGlobalBounds().height) / 2);
            window.draw(*itemSprites[0]);
        }

        //opis itemka
        itemDescriptions[0].setPosition(700 + (150 - itemDescriptions[0].getLocalBounds().width) / 2, 580);
        window.draw(itemDescriptions[0]);



        // Przycisk wymiany
        buttonSprite.setPosition(680, 700);
        window.draw(buttonSprite);
        break;

    default:

        std::cout << "Error" << std::endl;
    }
}

void ShopScene::HandleMouseClick(int x, int y)
{ }

