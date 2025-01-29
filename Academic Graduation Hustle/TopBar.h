#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TopBar {
public:
    TopBar();

    // Funkcje do aktualizacji dynamicznych elementów
    void UpdateTime(const std::string& time);
    void UpdateSemester(int semester);
    void UpdateFightText(int movesLeft);

    // Funkcja rysuj¹ca górny pasek
    void Render(sf::RenderWindow& window);

private:
    sf::Font font;                  // Czcionka dla tekstów
    sf::Text timeText;              // Tekst czasu
    sf::Text semesterText;          // Tekst semestru

    sf::RectangleShape background;  // T³o paska
    sf::RectangleShape placeholder; // Placeholder na œrodku paska
	sf::Text fightText;			 // Tekst walki

    sf::Texture timeTexture;        // Tekstura zegara
    sf::Sprite timeIcon;            // Ikona zegara

    sf::Texture settingsTexture;    // Tekstura ustawieñ
    sf::Sprite settingsIcon;        // Ikona ustawieñ

    sf::Texture examTexture;        // Tekstura egzaminu
    sf::Sprite examIcon;            // Ikona egzaminu
};
