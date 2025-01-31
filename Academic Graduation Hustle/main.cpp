#include "GameManager.h"
#include "AudioManager.h"

int main()
{
    AudioManager::LoadSounds();
    GameManager gameManager;
    gameManager.Run();
    return 0;


    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    */

    return 0;
}