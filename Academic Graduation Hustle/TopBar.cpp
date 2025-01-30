#include "TopBar.h"
#include <iostream>

// Konstruktor klasy
TopBar::TopBar() {
    // Wczytaj czcionk�
    if (!font.loadFromFile("fonts/VT323-Regular.ttf")) {
        std::cerr << "Nie uda�o si� za�adowa� czcionki!" << std::endl;
    }

    // Ustawienia tekstu czasu
    timeText.setFont(font);
    timeText.setStyle(sf::Text::Bold); // Pogrubiony tekst
    timeText.setCharacterSize(50);    // Wielko�� tekstu
    timeText.setFillColor(sf::Color::Black);
    timeText.setPosition(225.f, 17.f); // Pozycja obok ikony zegara

    // Ustawienia tekstu semestru
    semesterText.setFont(font);
    semesterText.setStyle(sf::Text::Bold); // Pogrubiony tekst
    semesterText.setCharacterSize(50);    // Wielko�� tekstu
    semesterText.setFillColor(sf::Color::Black);
    semesterText.setPosition(1625.f, 17.f); // Pozycja obok ikony egzaminu

    //Ustawienie tekstu o walce
    fightText.setFont(font);
    fightText.setStyle(sf::Text::Bold); // Pogrubiony tekst
    fightText.setCharacterSize(50);    // Wielko�� tekstu
    fightText.setFillColor(sf::Color::Black);
    fightText.setString("Kolejna walka za 0 ruch�w"); // Domy�lny tekst
    fightText.setPosition(680.f, 17.f); // Wy�rodkowany w placeholderze

    // Ustawienia t�a paska
    background.setSize(sf::Vector2f(1920.f, 100.f)); // Szeroko�� i wysoko�� paska
    background.setFillColor(sf::Color(200, 200, 200)); // Jasnoszary kolor t�a
    background.setPosition(0.f, 0.f);

    // Wczytaj tekstur� zegara
    if (!timeTexture.loadFromFile("graphics/time.png")) {
        std::cerr << "Nie uda�o si� za�adowa� tekstury zegara!" << std::endl;
    }
    timeIcon.setTexture(timeTexture);

    // Wczytaj tekstur� ustawie�
    if (!settingsTexture.loadFromFile("graphics/settings.png")) {
        std::cerr << "Nie uda�o si� za�adowa� tekstury ustawie�!" << std::endl;
    }
    settingsIcon.setTexture(settingsTexture);

    // Wczytaj tekstur� egzaminu
    if (!examTexture.loadFromFile("graphics/egzam.png")) {
        std::cerr << "Nie uda�o si� za�adowa� tekstury egzaminu!" << std::endl;
    }
    examIcon.setTexture(examTexture);

    // Skalowanie ikon
    const float barHeight = 100.f;               // Wysoko�� paska
    const float targetIconHeight = barHeight * 0.8f; // Ikony zajmuj� 80% wysoko�ci paska

    // Skalowanie ikony zegara
    sf::Vector2u timeIconSize = timeTexture.getSize();
    float scaleX = targetIconHeight / timeIconSize.y;
    float scaleY = targetIconHeight / timeIconSize.y;
    timeIcon.setScale(scaleX, scaleY);

    // Skalowanie ikony ustawie�
    sf::Vector2u settingsIconSize = settingsTexture.getSize();
    scaleX = targetIconHeight / settingsIconSize.y;
    scaleY = targetIconHeight / settingsIconSize.y;
    settingsIcon.setScale(scaleX, scaleY);

    // Skalowanie ikony egzaminu
    sf::Vector2u examIconSize = examTexture.getSize();
    scaleX = targetIconHeight / examIconSize.y;
    scaleY = targetIconHeight / examIconSize.y;
    examIcon.setScale(scaleX, scaleY);

    // Dodanie placeholdera na �rodek
    placeholder.setSize(sf::Vector2f(700.f, targetIconHeight)); // Szeroko�� placeholdera
    placeholder.setOutlineThickness(5.f);
	placeholder.setOutlineColor(sf::Color::Black);
    placeholder.setFillColor(sf::Color(230, 230, 230)); 
    placeholder.setPosition(600.f, (barHeight - targetIconHeight) / 2.f);

    // Pozycjonowanie ikon
    timeIcon.setPosition(115.f, (barHeight - targetIconHeight) / 2.f);         // Lewa strona
    examIcon.setPosition(1500.f, (barHeight - targetIconHeight) / 2.f);       // Obok zegara
    settingsIcon.setPosition(20.f, (barHeight - targetIconHeight) / 2.f);  // Prawa strona
}

// Aktualizacja czasu
void TopBar::UpdateTime(const std::string& time) {
    timeText.setString("Czas: " + time);
}

// Aktualizacja semestru
void TopBar::UpdateSemester(int semester) {
    semesterText.setString("Semestr: " + std::to_string(semester));
}

// Aktualizacja tekstu walki
void TopBar::UpdateFightText(int movesLeft) {
    fightText.setString("Nast�pna walka za " + std::to_string(movesLeft) + " ruch�w");
}

// Renderowanie paska
void TopBar::Render(sf::RenderWindow& window) {
    // Rysowanie t�a
    window.draw(background);

    // Rysowanie ikon
    window.draw(timeIcon);
    window.draw(settingsIcon);
    window.draw(examIcon);

    // Rysowanie placeholdera
    window.draw(placeholder);

    // Rysowanie tekst�w
    window.draw(timeText);
    window.draw(semesterText);
    window.draw(fightText);


}
