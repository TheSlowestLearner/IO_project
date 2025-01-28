#include "FightScene.h"
#include "WindowHandler.h"
#include "GameScene.h"
#include "Scene.h"
#include <iostream>

FightScene::FightScene(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    if (!backgroundTexture.loadFromFile("graphics/background.png"))
        throw std::runtime_error("Background texture not found!");
    if (!enemyTexture.loadFromFile("graphics/enemy_sprite_sheet.png"))
        throw std::runtime_error("Enemy texture not found!");
    if (!playerTexture.loadFromFile("graphics/player_sprite_sheet.png"))
        throw std::runtime_error("Player texture not found!");
    if (!buttonTexture.loadFromFile("graphics/spritesheet_placeholder.png"))
        throw std::runtime_error("Button texture not found!");

    // t³o
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);

    // gracz
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(385, 480);
    playerSprite.setScale(4.5f, 4.5f);

    playerSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
    playerAnimator = new Animator(playerSprite, { 32, 32 }, 7, 1, 2);
    currentPlayerAnimation = IDLE;

    // przeciwnik
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(1005, 480);
    enemySprite.setScale(-4.5f,4.5f);

    enemySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    enemyAnimator = new Animator(enemySprite, { 32, 32 }, 7, 0, 2);
    currentEnemyAnimation = IDLE;

    // przyciski
    attackButton.setTexture(buttonTexture);
    attackButton.setTextureRect({ 1500,100,200,80 });
    attackButton.setPosition(200, 800);
    attackButton.setScale(1.f, 1.f);

    itemButton.setTexture(buttonTexture);
    itemButton.setTextureRect({ 1500,1700,200,80 });
    itemButton.setPosition(600, 800);
    itemButton.setScale(1.f, 1.f);

    // przyciski korzystaj¹ z placeholdera
}

void FightScene::Update()
{
    // opuszczanie sceny
    if (false)
    {
        this->HandleExit();
    }
    // aktualizacja sceny
    else
    {
        // playerAnimator->Update(0.016f);
        // enemyAnimator->Update(0.016f);

        this->UpdateSprites();

        if (currentPlayerAnimation == IDLE)
            this->HandleButtons();
    }
}

void FightScene::Render(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(playerSprite);
    window.draw(enemySprite);
    window.draw(attackButton);
    window.draw(itemButton);
}

void FightScene::HandleMouseClick(int x, int y) {}

void FightScene::HandleAttack()
{
    std::cout << "FIGHT SCENE: attack pressed" << std::endl;
    currentPlayerAnimation = ATTACK;
    currentEnemyAnimation = DEATH;
}
void FightScene::HandleItem()
{
    std::cout << "FIGHT SCENE: item pressed" << std::endl;
    currentPlayerAnimation = HEAL;
}
void FightScene::HandleButtons()
{
    // pobranie pozycji kursora
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f mouseWorldPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    // podœwietlanie przycisków
    if (attackButton.getGlobalBounds().contains(mouseWorldPosition))
        attackButton.setColor({ 100,100,100 });
    else
        attackButton.setColor({ 255,255,255 });

    if (itemButton.getGlobalBounds().contains(mouseWorldPosition))
        itemButton.setColor({ 100,100,100 });
    else
        itemButton.setColor({ 255,255,255 });

    // obs³uga funkcjonalnoœci przycisków
    static bool held = false; // czy przycisk myszy jest przytrzymywany?
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !held)
    {
        if (attackButton.getGlobalBounds().contains(mouseWorldPosition))
        {
            this->HandleAttack();
        }
        else if (itemButton.getGlobalBounds().contains(mouseWorldPosition))
        {
            this->HandleItem();
        }

        held = true;
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        held = false;
}
void FightScene::HandleExit()
{
    std::cout << "FIGHT SCENE: over 5 buttons pushed, returning to game scene" << std::endl;
    this->windowHandler->SetScene(std::make_shared<GameScene>(windowHandler));
}

constexpr int pf_attack = 6;    // iloœæ klatek ataku gracza
constexpr int pf_death = 10;    // iloœæ klatek œmierci gracza
constexpr int pf_heal = 8;      // iloœæ klatek uzdrowienia gracza
constexpr int pf_hurt = 6;      // iloœæ klatek obra¿eñ gracza
constexpr int pf_idle = 7;      // iloœæ klatek bezczynnoœci gracza
constexpr int ef_attack = 6;    // iloœæ klatek ataku przeciwnika
constexpr int ef_death = 11;    // iloœæ klatek œmierci przeciwnika
constexpr int ef_idle = 7;      // iloœæ klatek bezczynnoœci przeciwnika
inline void FightScene::UpdateSprites()
{
    static int player_frame = 0;
    static int enemy_frame = 0;
    
    // obs³uga animacji gracza
    switch (currentPlayerAnimation)
    {
    case IDLE:      // ANIMACJA BEZCZYNNOŒCI
        playerAnimator->Update(0.016f);
        break;

    case ATTACK:    // ANIMACJA ATAKU
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(3, pf_attack);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;
    
            if (player_frame > pf_attack)
            {
                playerAnimator->SetAnimation(1, pf_idle);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
        break;
    
    case DEATH:     // ANIMACJA ŒMIERCI
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(6, pf_death);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;

            if (player_frame > pf_death)
            {
                playerAnimator->SetAnimation(1, pf_idle);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
        break;
    
    case HEAL:      // ANIMACJA UZDROWIENIA
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(4, pf_heal);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;

            if (player_frame > pf_heal)
            {
                playerAnimator->SetAnimation(1, pf_idle);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
        // wydruk kontrolny
        if (currentPlayerAnimation == HEAL)
            std::cout << "FIGHT SCENE: played 'heal' frame no." << player_frame << std::endl;
        break;
    
    case HURT:      // ANIMACJA OBRA¯EÑ
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(5, pf_hurt);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;

            if (player_frame > pf_hurt)
            {
                playerAnimator->SetAnimation(1, pf_idle);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
        break;
    
    default:
        throw std::runtime_error("Trying to play invalid player animation!");
        break;
    }

    // obs³uga animacji przeciwnika
    switch (currentEnemyAnimation)
    {
    case IDLE:      // ANIMACJA BEZCZYNNOŒCI
        enemyAnimator->Update(0.016f);
        break;

    case ATTACK:    // ANIMACJA ATAKU
        if (enemy_frame == 0)
        {
            enemyAnimator->SetAnimation(3, ef_attack);
            enemy_frame++;
        }
        else
        {
            enemyAnimator->Update(0.016f);
            enemy_frame++;

            if (enemy_frame > ef_attack)
            {
                enemyAnimator->SetAnimation(0, ef_idle);
                currentEnemyAnimation = IDLE;
                enemy_frame = 0;
            }
        }
        break;

    case DEATH:     // ANIMACJA ŒMIERCI
        if (enemy_frame == 0)
        {
            enemyAnimator->SetAnimation(2, ef_death);
            enemy_frame++;
        }
        else
        {
            enemyAnimator->Update(0.016f);
            enemy_frame++;

            if (enemy_frame > ef_death)
            {
                enemyAnimator->SetAnimation(0, ef_idle);
                currentEnemyAnimation = IDLE;
                enemy_frame = 0;
            }
        }
        break;

    default:
        throw std::runtime_error("Trying to play invalid enemy animation!");
        break;
    }
}