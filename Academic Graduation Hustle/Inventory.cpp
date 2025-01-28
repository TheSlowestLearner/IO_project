#include "Inventory.h"
#include "ShopScene.h"
#include "FightScene.h"
#include "GameScene.h"
#include "Player.h"
#include <iostream>
#include <string>

Inventory::Inventory(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    player1 = new Player;
    player1->savePlayer();
    exitButton.setPosition(0, 0);
    exitButton.setSize(sf::Vector2f(100, 100));
    exitButton.setFillColor(sf::Color::Black);
    rightButton.setPosition(1600, 500);
    rightButton.setSize(sf::Vector2f(100, 100));
    rightButton.setFillColor(sf::Color::Yellow);
    leftButton.setPosition(200, 500);
    leftButton.setSize(sf::Vector2f(100, 100));
    leftButton.setFillColor(sf::Color::Yellow);
    useButton.setPosition(895, 730);
    useButton.setSize(sf::Vector2f(100, 100));
    useButton.setFillColor(sf::Color::Green);

    if (!randomFont.loadFromFile("fonts/random_font.ttf"))
    {
        throw std::runtime_error("Font not found!");
    }
    itemsValue.setFont(randomFont);
    itemsValue.setCharacterSize(120);
    itemsValue.setPosition(920, 550);
    itemsValue.setFillColor(sf::Color::White);

    if (!backgroundTexture.loadFromFile("graphics/shop_background.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[0].loadFromFile("graphics/items/beer.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[1].loadFromFile("graphics/items/beer2.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[2].loadFromFile("graphics/items/cigarettes.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[3].loadFromFile("graphics/items/coffee.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[4].loadFromFile("graphics/items/energy_drink.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[5].loadFromFile("graphics/items/harnas.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[6].loadFromFile("graphics/items/headphones.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[7].loadFromFile("graphics/items/salad.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[8].loadFromFile("graphics/items/snack_bar.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[9].loadFromFile("graphics/items/toilet_paper.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[10].loadFromFile("graphics/items/vape.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[11].loadFromFile("graphics/energy.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);
    for (int i = 0; i <= items_number; i++)
    {
        ItemsSprite[i].setTexture(ItemsTexture[i]);
        ItemsSprite[i].setScale(10, 10);
        ItemsSprite[i].setPosition(815, 285);
    }
}


void Inventory::Update()
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
        if (rightButton.getGlobalBounds().contains(mouseWorldPosition))
        {
            if (!isClicked)
            {
                if (itemId >= items_number - 1)
                    itemId = 0;
                else
                    itemId++;
                for (int antyloop = 0; player1->seeItems(itemId) <= 0; antyloop++)
                {
                    if (itemId >= items_number - 1)
                        itemId = 0;
                    else
                        itemId++;
                    if (antyloop > items_number)
                    {
                        itemId = items_number;
                        break;
                    }
                }
            }
        }
        if (leftButton.getGlobalBounds().contains(mouseWorldPosition))
        {
            if (!isClicked)
            {
                if (itemId <= 0)
                    itemId = items_number-1;
                else
                    itemId--;
                for (int antyloop = 0; player1->seeItems(itemId) <= 0; antyloop++)
                {
                    if (itemId <0)
                        itemId = items_number-1;
                    else
                        itemId--;
                    if (antyloop > items_number)
                    {
                        itemId = items_number;
                        break;
                    }
                }
            }
        }
        if (useButton.getGlobalBounds().contains(mouseWorldPosition))
        {
            if (!isClicked)
            {
                if (itemId < items_number)
                {
                    if (player1->seeItems(itemId) >= 0)
                    {
                        //Efekt przedmiotu
                        player1->modifyItem(itemId, -1);
                    }
                }
            }
        }
        isClicked = true;
    }
    else
    {
        isClicked = false;
    }

}

void Inventory::Render(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(exitButton);
    window.draw(rightButton);
    window.draw(leftButton);
    for (int antyloop = 0; player1->seeItems(itemId)<=0; antyloop++)
    {
        if (itemId >= items_number - 1)
            itemId = 0;
        else
            itemId++;
        if (antyloop > items_number)
        {
            itemId = items_number;
            break;
        }
    }
    window.draw(ItemsSprite[itemId]);
    if (itemId < items_number)
    {
        window.draw(useButton);
        itemsValue.setString(std::to_string(player1->seeItems(itemId)));
        window.draw(itemsValue);
    }
}

void Inventory::HandleMouseClick(int x, int y)
{ }
void Inventory::UploadPlayer(Player *player)
{
    player1 = player;
}

