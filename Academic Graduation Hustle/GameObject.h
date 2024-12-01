#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

/// <summary>
/// Podstawowa klasa przechowuj�ca dane o pozycji i wygl�dzie obiektu.
/// </summary>
class GameObject
{
public:

	/// <summary>
	/// Domy�lny konstruktor.
	/// </summary>
	GameObject();

	/// <summary>
	/// Ustawia zmienn� logiczn� hidden na false.
	/// </summary>
	void show();
	/// <summary>
	/// Ustawia zmienn� logiczn� hidden na true.
	/// </summary>
	void hide();
	/// <returns>
	/// true - je�eli zmienna hidden jest false.
	///</returns>
	bool is_shown() const;

private:

	sf::Sprite sprite;			// Sprite obiektu.
	sf::Texture texture;		// Tekstura obiektu.
	sf::Vector2f position;		// Pozycja obiektu na oknie.
	bool hidden;				// Okre�la czy obiekt jest wy�wietlany na oknie.
};