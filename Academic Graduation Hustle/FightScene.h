#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"
#include "GameScene.h"
#include "Player.h"

class FightScene : public Scene
{
    enum Anim
    {
        IDLE,
        ATTACK,
        DEATH,
        HEAL,
        HURT,
    };
    struct Statistic
    {
        int amount;

        sf::Texture texture;
        sf::Sprite sprite;
        sf::Text name;
        sf::Text amountText;
        sf::Font font;

        Statistic();

        inline void Update();
    };
    struct UI
    {
        Statistic health;
        Statistic energy;
        Statistic sanity;

        UI();
    };
    struct EnemyUI
    {
        enum Attack
        {
            NONE,
            BASE,
            FOO1,
            FOO2,
        };

        int points;
        int required;
        sf::RectangleShape pointBar;
        sf::RectangleShape pointBar_empty;
        Attack nextAttack;
        sf::Font font;
        sf::Text pointText;
        sf::Text attackText;
        sf::Text nextAttackText;

        EnemyUI();
        inline void Update();
        inline void QueueNextAttack();
    };
    struct ItemBag
    {
        int currentItem;
        int itemAmount;

        sf::Texture bagTexture;
        sf::Texture itemTexture;
        sf::Texture arrowTexture;
        sf::Sprite bagSprite;
        sf::Sprite itemSprite;
        sf::Sprite leftArrow;
        sf::Sprite rightArrow;
        sf::RectangleShape background;
        
        bool empty;

        ItemBag();
        inline void Update();
        void HandleLeftArrow();
        void HandleRightArrow();
    };
public:

    FightScene(std::shared_ptr<WindowHandler> handler);

    /// <summary>
    /// Rysuje obiekty na oknie.
    /// </summary>
    /// <param name="window">- orygina³ instancji okna</param>
    void Render(sf::RenderWindow& window) override;
    /// <summary>
    /// Aktualizuje okno.
    /// <para>
    /// Jest wywo³ywana co klatkê.
    /// </para>
    /// </summary>
    void Update() override;
    void HandleMouseClick(int x, int y) override;

private:

    //Wyœwietlanie gracza:
    sf::Sprite playerSprite;        // sprite gracza
    sf::Texture playerTexture;      // tekstura gracza
    Animator* playerAnimator;       // dynamiczny animator gracza
    Anim currentPlayerAnimation;    // obecna animacja gracza

    //Enemy
    sf::Sprite enemySprite;     // sprite przeciwnika
    sf::Texture enemyTexture;   // tekstura przeciwnika
    Animator* enemyAnimator;    // dynamiczny animator przeciwnika
    Anim currentEnemyAnimation; // obecna animacja przeciwnika

    //T³o
    sf::Sprite backgroundSprite;    // sprite t³a
    sf::Texture backgroundTexture;  // tekstura t³a

    // wskaŸnik do obs³ugiwacza okna
    std::shared_ptr<WindowHandler> windowHandler;

    sf::Sprite attackButton;    // przycisk do atakowania
    sf::Sprite itemButton;      // przycisk do wykorzystania przedmiotu
    sf::Texture buttonTexture;  // tekstury przycisków

    UI stats;                   // interfejs ze statystykami gracza
    EnemyUI enemyStats;         // interfejs ze statystykami przeciwnika
    ItemBag itemBag;            // interfejs do zarz¹dzania u¿ywanymi przedmiotami

    // Obs³uguje operacjê ataku.
    inline void HandleAttack();
    // Obs³uguje operacjê u¿ycia przedmiotu.
    inline void HandleItem();
    // Obs³uguje interakcjê z przyciskami.
    inline void HandleButtons();
    // Obs³uguje opuszczenie sceny.
    inline void HandleExit();

    // Aktualizuje sprite'y postaci.
    inline void UpdateSprites();
    // Aktualizuje interfejs statystyk.
    inline void UpdateStats();
    // Aktualizuje interfejs przeciwnika.
    inline void UpdateEnemy();
};
