#include "GameScene.h"
#include "WindowHandler.h"
#include <iostream>

GameScene::GameScene() 
{
    if (!backgroundTexture.loadFromFile("graphics/background.png")) 
    {
        throw std::runtime_error("Texture not found!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);

    if (!locationTexture.loadFromFile("graphics/items_locations_sprite_sheet.png")) 
    {
        throw std::runtime_error("Texture not found!");
    }
    locationSprite.setTexture(locationTexture);
    locationSprite.setScale(4.5f, 4.5f);

    //Akademik
    locationSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    academicSprite = locationSprite;
    academicSprite.setPosition(585, 780);
    //Biblioteka
    locationSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
    librarySprite = locationSprite;
    librarySprite.setPosition(1385, 305);
    //Biedronka
    locationSprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
    biedronkaSprite = locationSprite;
    biedronkaSprite.setPosition(185, 585);
    //Hala
    locationSprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
    halaSprite = locationSprite;
    halaSprite.setPosition(485, 385);
    //Miasteczko
    locationSprite.setTextureRect(sf::IntRect(128, 0, 32, 32));
    miasteczkoSprite = locationSprite;
    miasteczkoSprite.setPosition(885, 285);
    //Studenciak
    locationSprite.setTextureRect(sf::IntRect(160, 0, 32, 32));
    studenciakSprite = locationSprite;
    studenciakSprite.setPosition(1195, 800);
    //Wydzia³
    locationSprite.setTextureRect(sf::IntRect(192, 0, 32, 32));
    wimiipSprite = locationSprite;
    wimiipSprite.setPosition(985, 585);

    if (!playerTexture.loadFromFile("graphics/player_sprite_sheet.png")) 
    {
        throw std::runtime_error("Texture not found!");
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(585, 680);      // Pozycja startowa
    playerSprite.setScale(4.5f, 4.5f);

    playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    playerAnimator = new Animator(playerSprite, { 32, 32 }, 7, 0, 2);
}

void MoveTowards(sf::Sprite& playerSprite, const sf::Sprite& targetLocationSprite, float speed, float deltaTime)
{
    sf::Vector2f playerPosition = playerSprite.getPosition();
    sf::Vector2f locationPosition = targetLocationSprite.getPosition();

    sf::Vector2f direction = locationPosition - playerPosition;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length > 0.1f)
    {
        direction /= length; 
    }

    if (length <= speed * deltaTime)
    {
        playerSprite.setPosition(locationPosition);
    }
    else
    {
        playerSprite.move(direction * speed * deltaTime);
    }
}

bool isMoving = false;
bool isWalking = true;
sf::Vector2f targetPosition;
sf::Clock gameClock;
int selectedLocationIndex = -1;
void GameScene::Update()
{
    playerAnimator->Update(0.016f);
    
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    float deltaTime = gameClock.restart().asSeconds();

    sf::Sprite* LocationSprites[] = {&academicSprite,&biedronkaSprite,&studenciakSprite,&halaSprite,&wimiipSprite,&miasteczkoSprite,&librarySprite};
    for (int i=0;i<7;i++)
    {
        if (LocationSprites[i]->getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
        {
            LocationSprites[i]->setScale(5.1f, 5.1f);
            //std::cout<<( "Mouse is over ") <<std::endl;
        }
        else
        {
            LocationSprites[i]->setScale(4.5f, 4.5f);
        }
    }

    sf::Vector2f mouseWorldPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    for (int i = 0; i < 7; i++)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isMoving)
        {
            if (LocationSprites[i]->getGlobalBounds().contains(mouseWorldPosition))
            {
                //MoveTowards(playerSprite, *LocationSprites[i], 50, deltaTime);
                targetPosition = LocationSprites[i]->getPosition();
                selectedLocationIndex = i;
                isMoving = true;
                break;
            }
        }
    }
    
    
    if (isMoving && selectedLocationIndex != -1)
    {
        MoveTowards(playerSprite,*LocationSprites[selectedLocationIndex], 150.f, deltaTime);
        
        if (isWalking)
        {
            isWalking = false;
            playerAnimator->SetAnimation(2, 5);
        }

        if (std::abs(playerSprite.getPosition().x - targetPosition.x) < 1.0f && std::abs(playerSprite.getPosition().y - targetPosition.y) < 1.0f)
        {
            playerSprite.setPosition(targetPosition); 
            playerAnimator->SetAnimation(0, 7);
            isMoving = false;
            isWalking = true;
            selectedLocationIndex = -1;
        }
    }
}

void GameScene::Render(sf::RenderWindow& window)
{
    //T³o
    window.draw(backgroundSprite);
    //Akademik
    window.draw(academicSprite);
    //Biblioteka
    window.draw(librarySprite);
    //Biedronka
    window.draw(biedronkaSprite);
    //Hala
    window.draw(halaSprite);
    //Miasteczko
    window.draw(miasteczkoSprite);
    //Studenciak
    window.draw(studenciakSprite);
    //Wydzia³
    window.draw(wimiipSprite);
    //Gracz
    window.draw(playerSprite);

}

void GameScene::HandleMouseClick(int x, int y) 
{
    
}