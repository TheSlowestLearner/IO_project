#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TopBar {
public:
    TopBar();

    // Funkcje do aktualizacji dynamicznych element�w
    void UpdateTime(const std::string& time);
    void UpdateSemester(int semester);
    void UpdateFightText(int movesLeft);

    // Funkcja rysuj�ca g�rny pasek
    void Render(sf::RenderWindow& window);

private:
    sf::Font font;                  // Czcionka dla tekst�w
    sf::Text timeText;              // Tekst czasu
    sf::Text semesterText;          // Tekst semestru

    sf::RectangleShape background;  // T�o paska
    sf::RectangleShape placeholder; // Placeholder na �rodku paska
	sf::Text fightText;			 // Tekst walki

    sf::Texture timeTexture;        // Tekstura zegara
    sf::Sprite timeIcon;            // Ikona zegara

    sf::Texture settingsTexture;    // Tekstura ustawie�
    sf::Sprite settingsIcon;        // Ikona ustawie�

    sf::Texture examTexture;        // Tekstura egzaminu
    sf::Sprite examIcon;            // Ikona egzaminu
};
