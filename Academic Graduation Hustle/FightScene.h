#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "Animator.h"
#include "WindowHandler.h" 
#include "GameManager.h"
#include "GameScene.h"
#include "Player.h"

class FightScene : public Scene
{
public:

    FightScene(std::shared_ptr<WindowHandler> handler);

    /// <summary>
    /// Rysuje obiekty na oknie.
    /// </summary>
    /// <param name="window">- </param>
    void Render(sf::RenderWindow& window) override;
    /// <summary>
    /// Aktualizuje okno.
    /// <para>
    /// Jest wywo�ywana co klatk�.
    /// </para>
    /// </summary>
    void Update() override;
    void HandleMouseClick(int x, int y) override;

private:

    //Wy�wietlanie gracza:
    sf::Sprite playerSprite;        // sprite gracza
    sf::Texture playerTexture;      // tekstura gracza
    Animator* playerAnimator;       // dynamiczny animator gracza

    //Enemy
    sf::Sprite enemySprite;     // sprite przeciwnika
    sf::Texture enemyTexture;   // tekstura przeciwnika
    Animator* enemyAnimator;    // dynamiczny animator przeciwnika

    //T�o
    sf::Sprite backgroundSprite;    // sprite t�a
    sf::Texture backgroundTexture;  // tekstura t�a

    // wska�nik do obs�ugiwacza okna
    std::shared_ptr<WindowHandler> windowHandler;

    sf::Sprite attackButton;    // przycisk do atakowania
    sf::Sprite itemButton;      // przycisk do wykorzystania przedmiotu
    sf::Texture buttonTexture;  // tekstury przycisk�w

    // Obs�uguje operacj� ataku
    void HandleAttack();
    // Obs�uguje operacj� u�ycia przedmiotu
    void HandleItem();
    // Obs�uguje opuszczenie sceny
    void HandleExit();
};
