#pragma once
#include "TaskLogic.h"

/// <summary>
/// Abstrakcyjna klasa obiektu mo�liwego do wy�wietlenia na oknie.
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
	/// Ustawia tekstur� obiektu.
	/// </summary>
	/// <param name="_texture">- obiekt tekstury</param>
	void SetTexture(const sf::Texture& _texture);
	/// <summary>
	/// Ustawia pozycj� obiektu.
	/// </summary>
	/// <param name="_position">- obiekt wektora</param>
	void SetPosition(const sf::Vector2f& _position);

	sf::Sprite		sprite;		// instancja mo�liwa do narysowania na oknie
	sf::Texture		texture;	// obraz nak�adany na sprite

	bool	hide;				// stwierdza czy obiekt powinien zosta� narysowany czy nie
};
/// <summary>
/// Podstawowy renderowalny obiekt, mo�liwy do wy�wietlenia.
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
/// Przycisk wywo�uj�cy polecenia po wci�ni�ciu.
/// </summary>
class Button : public RenderableInstance, public TaskInvoker
{
public:

	void DrawOn(sf::RenderWindow& _window);

private:

	sf::Rect<int>	hitbox;			// pole mo�liwe do wci�ni�cia
	bool			hitboxEnabled;	// stwierdza czy hitbox jest w��czony czy nie
};
/// <summary>
/// Wyskakuj�ce okienko z tekstem i przyciskami.
/// </summary>
class Popup
{
public:

	void DrawOn(sf::RenderWindow& _window);

private:

	Textbox				textbox;	// okienko z tekstem
	std::vector<Button>	buttons;	// przyciski
};