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
    player1->loadPlayer();

    if (!randomFont.loadFromFile("fonts/random_font.ttf"))
    {
        throw std::runtime_error("Font not found!");
    }
    itemsValue.setFont(randomFont);
    itemsValue.setCharacterSize(120);
    itemsValue.setPosition(920, 550);
    itemsValue.setFillColor(sf::Color::White);

    if (!exitButtonTexture.loadFromFile("graphics/exit_button.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!useButtonTexture.loadFromFile("graphics/use_button2.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!rightButtonTexture.loadFromFile("graphics/arrow.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!leftButtonTexture.loadFromFile("graphics/arrow.png"))
    {
        throw std::runtime_error("Texture not found!");
    }

    if (!backgroundTexture.loadFromFile("graphics/shop_background.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[0].loadFromFile("graphics/items/beer.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[1].loadFromFile("graphics/items/cigarettes.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[2].loadFromFile("graphics/items/coffee.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[3].loadFromFile("graphics/items/energy_drink.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[4].loadFromFile("graphics/items/harnas.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[5].loadFromFile("graphics/items/headphones.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[6].loadFromFile("graphics/items/salad.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[7].loadFromFile("graphics/items/snack_bar.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[8].loadFromFile("graphics/items/toilet_paper.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[9].loadFromFile("graphics/items/vape.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    if (!ItemsTexture[10].loadFromFile("graphics/energy.png"))
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);
    exitButtonSprite.setTexture(exitButtonTexture);
    exitButtonSprite.setPosition(0, 100);
    exitButtonSprite.setScale(3, 3);
    rightButtonSprite.setTexture(rightButtonTexture);
    rightButtonSprite.setPosition(1600, 500);
    rightButtonSprite.setScale(5, 3.15);
    leftButtonSprite.setTexture(rightButtonTexture);
    leftButtonSprite.setPosition(300, 600);
    leftButtonSprite.setScale(5, 3.15);
    leftButtonSprite.rotate(180);
    useButtonSprite.setTexture(useButtonTexture);
    useButtonSprite.setPosition(800, 740);
    useButtonSprite.setScale(3, 3);
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
        if (exitButtonSprite.getGlobalBounds().contains(mouseWorldPosition))
        {
            auto newScene = std::make_shared<GameScene>(windowHandler);
            windowHandler->SetScene(newScene);
        }
        if (rightButtonSprite.getGlobalBounds().contains(mouseWorldPosition))
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
        if (leftButtonSprite.getGlobalBounds().contains(mouseWorldPosition))
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
        if (useButtonSprite.getGlobalBounds().contains(mouseWorldPosition))
        {
            if (!isClicked)
            {
                if (itemId < items_number)
                {
                    if (player1->seeItems(itemId) >= 0)
                    {
                        if (itemId == beer)
                        {
                            player1->modifyStats(sanity, 15);
                            player1->modifyStats(heath, -10);
                        }
                        if (itemId == cigarettes)
                        {

                        }
                        if (itemId == coffee)
                        {
                            player1->modifyStats(energy, 5);
                        }
                        if (itemId == energy_drink)
                        {
                            
                        }
                        if (itemId == harnas)
                        {
                            
                        }
                        if (itemId == headphones)
                        {

                        }
                        if (itemId == salad)
                        {
                            player1->modifyStats(heath, 10);
                        }
                        if (itemId == snack_bar)
                        {

                        }
                        if (itemId == toilet_paper)
                        {
                            player1->modifyStats(energy, 10);
                        }
                        if (itemId == vape)
                        {

                        }
                        player1->modifyItem(itemId, -1);
                        player1->savePlayer();
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
    window.draw(exitButtonSprite);
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
        window.draw(rightButtonSprite);
        window.draw(leftButtonSprite);
        window.draw(useButtonSprite);
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

