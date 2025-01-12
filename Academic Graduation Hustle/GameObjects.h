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

protected:

	sf::Sprite		sprite;		// instancja mo¿liwa do narysiwania na oknie
	sf::Texture		texture;	// obraz nak³adany na sprite
	sf::Vector2f	position;	// pozycja obiektu na oknie

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