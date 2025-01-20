#pragma once
#include "TaskLogic.h"

/// <summary>
/// Abstrakcyjna klasa obiektu mo¿liwego do wyœwietlenia na oknie.
/// </summary>
class RenderableInstance
{
public:

	virtual	~RenderableInstance() = 0;

	/// <summary>
	/// Rysuje obiekt na buforze.
	/// </summary>
	virtual void DrawOn(sf::RenderWindow& _window) = 0;

	/// <summary>
	/// Ustawia sprite obiektu.
	/// </summary>
	/// <param name="_rect">- obszar tekstury</param>
	void SetSprite(const sf::IntRect& _rect);
	/// <summary>
	/// Ustawia teksturê obiektu.
	/// </summary>
	/// <param name="_texture">- obiekt tekstury</param>
	void SetTexture(const sf::Texture& _texture);
	/// <summary>
	/// Ustawia pozycjê obiektu.
	/// </summary>
	/// <param name="_position">- obiekt wektora</param>
	void SetPosition(const sf::Vector2f& _position);

	sf::Sprite		sprite;		// instancja mo¿liwa do narysowania na oknie
	sf::Texture		texture;	// obraz nak³adany na sprite

	bool	hide;				// stwierdza czy obiekt powinien zostaæ narysowany czy nie
};
/// <summary>
/// Podstawowy renderowalny obiekt, mo¿liwy do wyœwietlenia.
/// </summary>
class Decoration : public RenderableInstance
{
public:

	void DrawOn(sf::RenderWindow& _window);

private:


};
/// <summary>
/// Okienko z tekstem.
/// </summary>
class Textbox : public RenderableInstance
{
public:

	void DrawOn(sf::RenderWindow& _window);

private:

	sf::Text		text;			// pole tekstowe
	sf::Vector2f	textPosition;	// pozycja pola tekstowego relatywna do pozycji obiektu
};
/// <summary>
/// Przycisk wywo³uj¹cy polecenia po wciœniêciu.
/// </summary>
class Button : public RenderableInstance, public TaskInvoker
{
public:

	void DrawOn(sf::RenderWindow& _window);

private:

	sf::Rect<int>	hitbox;			// pole mo¿liwe do wciœniêcia
	bool			hitboxEnabled;	// stwierdza czy hitbox jest w³¹czony czy nie
};
/// <summary>
/// Wyskakuj¹ce okienko z tekstem i przyciskami.
/// </summary>
class Popup
{
public:

	void DrawOn(sf::RenderWindow& _window);

private:

	Textbox				textbox;	// okienko z tekstem
	std::vector<Button>	buttons;	// przyciski
};