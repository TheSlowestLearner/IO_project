#include "FightScene.h"
#include "WindowHandler.h"
#include "GameScene.h"
#include "Scene.h"
#include <iostream>

#pragma warning(disable : 4996)

// STATYSTYKI

FightScene::Statistic::Statistic()
    : amount(100)
{
    if (!texture.loadFromFile("graphics/spritesheet_placeholder.png"))
        throw std::runtime_error("Failed to load stat icon textures!");

    if (!font.loadFromFile("fonts/VT323-Regular.ttf"))
        throw std::runtime_error("Failed to load font!");
}
void FightScene::Statistic::Update()
{
    amountText.setString(std::to_string(amount));

    if (amount == 0)
        amountText.setColor({ 50,50,50 });
    else if (amount <= 10)
        amountText.setColor({ 200,0,0 });
    else if (amount <= 30)
        amountText.setColor({ 150,150,0 });
    else
        amountText.setColor({ 255,255,255 });

}

// INTERFEJS

constexpr int icon_col = 70;
constexpr float icon_scale = 1.f;
constexpr int text_col = 140;
constexpr int text_size = 40;
constexpr int value_col = 260;
constexpr int value_row_off = -6;
constexpr int value_size = 50;
constexpr int health_row = 100;
constexpr int energy_row = 200;
constexpr int sanity_row = 300;
FightScene::UI::UI()
{
    // zdrowie
    health.sprite.setTexture(health.texture);
    health.sprite.setTextureRect({ 0, 0, 60, 60 });
    health.sprite.setPosition(icon_col, health_row);
    health.sprite.setScale(icon_scale, icon_scale);
    
    health.name.setFont(health.font);
    health.name.setCharacterSize(text_size);
    health.name.setPosition(text_col, health_row);
    health.name.setString("HEALTH:");

    health.amountText.setFont(health.font);
    health.amountText.setCharacterSize(value_size);
    health.amountText.setPosition(value_col, health_row + value_row_off);

    // energia
    energy.sprite.setTexture(energy.texture);
    energy.sprite.setTextureRect({ 1700, 1700, 60, 60 });
    energy.sprite.setPosition(icon_col, energy_row);
    energy.sprite.setScale(icon_scale, icon_scale);

    energy.name.setFont(health.font);
    energy.name.setCharacterSize(text_size);
    energy.name.setPosition(text_col, energy_row);
    energy.name.setString("ENERGY:");

    energy.amountText.setFont(health.font);
    energy.amountText.setCharacterSize(value_size);
    energy.amountText.setPosition(value_col, energy_row + value_row_off);

    // psychika
    sanity.sprite.setTexture(sanity.texture);
    sanity.sprite.setTextureRect({ 0, 1700, 60, 60 });
    sanity.sprite.setPosition(icon_col, sanity_row);
    sanity.sprite.setScale(icon_scale, icon_scale);

    sanity.name.setFont(health.font);
    sanity.name.setCharacterSize(text_size);
    sanity.name.setPosition(text_col, sanity_row);
    sanity.name.setString("SANITY:");

    sanity.amountText.setFont(health.font);
    sanity.amountText.setCharacterSize(value_size);
    sanity.amountText.setPosition(value_col, sanity_row + value_row_off);
}

// KLASA SCENY

FightScene::FightScene(std::shared_ptr<WindowHandler> handler) : windowHandler(handler)
{
    if (!backgroundTexture.loadFromFile("graphics/background.png"))
        throw std::runtime_error("Failed to load background texture!");
    if (!enemyTexture.loadFromFile("graphics/enemy_sprite_sheet.png"))
        throw std::runtime_error("Failed to load enemy textures!");
    if (!playerTexture.loadFromFile("graphics/player_sprite_sheet.png"))
        throw std::runtime_error("Failed to load player textures!");
    if (!buttonTexture.loadFromFile("graphics/spritesheet_placeholder.png"))
        throw std::runtime_error("Failed to load button textures!");

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
        HandleExit();
    }
    // aktualizacja sceny
    else
    {
        UpdateSprites();
        UpdateStats();

        if (currentPlayerAnimation == IDLE)
            HandleButtons();
    }
}

void FightScene::Render(sf::RenderWindow& window)
{
    // t³o
    window.draw(backgroundSprite);

    // postacie
    window.draw(playerSprite);
    window.draw(enemySprite);

    // przyciski
    window.draw(attackButton);
    window.draw(itemButton);

    // interfejs
    window.draw(stats.health.sprite);
    window.draw(stats.health.name);
    window.draw(stats.health.amountText);

    window.draw(stats.energy.sprite);
    window.draw(stats.energy.name);
    window.draw(stats.energy.amountText);

    window.draw(stats.sanity.sprite);
    window.draw(stats.sanity.name);
    window.draw(stats.sanity.amountText);
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

constexpr int param = 128;
constexpr int pf_attack = 6 * param;    // iloœæ klatek ataku gracza
constexpr int pf_death = 10 * param;    // iloœæ klatek œmierci gracza
constexpr int pf_heal = 8 * param;      // iloœæ klatek uzdrowienia gracza
constexpr int pf_hurt = 6 * param;      // iloœæ klatek obra¿eñ gracza
constexpr int pf_idle = 7 * param;      // iloœæ klatek bezczynnoœci gracza
constexpr int ef_attack = 6 * param;    // iloœæ klatek ataku przeciwnika
constexpr int ef_death = 11 * param;    // iloœæ klatek œmierci przeciwnika
constexpr int ef_idle = 7 * param;      // iloœæ klatek bezczynnoœci przeciwnika
inline void FightScene::UpdateSprites()
{
    static int player_frame = 0;
    static int enemy_frame = 0;
    
    // obs³uga animacji gracza
    switch (currentPlayerAnimation)
    {
    case IDLE:      // ANIMACJA BEZCZYNNOŒCI
    {
        playerAnimator->Update(0.016f);
    }
        break;

    case ATTACK:    // ANIMACJA ATAKU
    {
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(3, 6);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;

            if (player_frame > pf_attack)
            {
                playerAnimator->SetAnimation(1, 7);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
    }
        break;
    
    case DEATH:     // ANIMACJA ŒMIERCI
    {
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(6, 10);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;

            if (player_frame > pf_death)
            {
                playerAnimator->SetAnimation(1, 7);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
    }
        break;
    
    case HEAL:      // ANIMACJA UZDROWIENIA
    {
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(4, 8);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;

            if (player_frame > pf_heal)
            {
                playerAnimator->SetAnimation(1, 7);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
    }
        break;
    
    case HURT:      // ANIMACJA OBRA¯EÑ
    {
        if (player_frame == 0)
        {
            playerAnimator->SetAnimation(5, 6);
            player_frame++;
        }
        else
        {
            playerAnimator->Update(0.016f);
            player_frame++;

            if (player_frame > pf_hurt)
            {
                playerAnimator->SetAnimation(1, 7);
                currentPlayerAnimation = IDLE;
                player_frame = 0;
            }
        }
    }
        break;
    
    default:
    {
        throw std::runtime_error("Trying to play invalid player animation!");
    }
        break;
    }

    // obs³uga animacji przeciwnika
    switch (currentEnemyAnimation)
    {
    case IDLE:      // ANIMACJA BEZCZYNNOŒCI
    {
        enemyAnimator->Update(0.016f);
    }
        break;

    case ATTACK:    // ANIMACJA ATAKU
    {
        if (enemy_frame == 0)
        {
            enemyAnimator->SetAnimation(3, 6);
            enemy_frame++;
        }
        else
        {
            enemyAnimator->Update(0.016f);
            enemy_frame++;

            if (enemy_frame > ef_attack)
            {
                enemyAnimator->SetAnimation(0, 7);
                currentEnemyAnimation = IDLE;
                enemy_frame = 0;
            }
        }
    }
        break;

    case DEATH:     // ANIMACJA ŒMIERCI
    {
        if (enemy_frame == 0)
        {
            enemyAnimator->SetAnimation(2, 11);
            enemy_frame++;
        }
        else
        {
            enemyAnimator->Update(0.016f);
            enemy_frame++;

            if (enemy_frame > ef_death)
            {
                enemyAnimator->SetAnimation(0, 7);
                currentEnemyAnimation = IDLE;
                enemy_frame = 0;
            }
        }
    }
        break;

    default:
    {
        throw std::runtime_error("Trying to play invalid enemy animation!");
    }
        break;
    }
}
inline void FightScene::UpdateStats()
{
    stats.health.Update();
    stats.energy.Update();
    stats.sanity.Update();
}