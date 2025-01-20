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
	void SetTexture(sf::Texture* _texture);
	/// <summary>
	/// Ustawia pozycj� obiektu.
	/// </summary>
	/// <param name="_position">- obiekt wektora</param>
	virtual void SetPosition(const sf::Vector2f& _position);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_offset">- kierunek i d�ugo�� ruchu</param>
	virtual void Move(const sf::Vector2f& _offset);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_x">- poziom; (-) lewo; (+) prawo</param>
	/// <param name="_y">- pion; (-) g�ra; (+) d�</param>
	virtual void Move(const float& _x, const float& _y);

	sf::Sprite		sprite;		// instancja mo�liwa do narysowania na oknie
	sf::Texture*	texture;	// obraz nak�adany na sprite

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

	/// <summary>
	/// Ustawia pozycj� obiektu.
	/// </summary>
	/// <param name="_position">- obiekt wektora</param>
	void SetPosition(const sf::Vector2f& _position);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_offset">- kierunek i d�ugo�� ruchu</param>
	void Move(const sf::Vector2f& _offset);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_x">- poziom; (-) lewo; (+) prawo</param>
	/// <param name="_y">- pion; (-) g�ra; (+) d�</param>
	void Move(const float& _x, const float& _y);
	/// <summary>
	/// Ustawia odchylenie pola tekstowego.
	/// </summary>
	/// <param name="_offset">- odchylenie</param>
	void SetOffset(const sf::Vector2f& _offset);
	/// <summary>
	/// Ustawia przechowywany tekst.
	/// </summary>
	/// <param name="_text">- tekst</param>
	void SetText(const std::string& _text);

private:

	sf::Text		text;		// pole tekstowe
	sf::Vector2f	textOffset;	// pozycja pola tekstowego (relatywna do pozycji obiektu)
};
/// <summary>
/// Przycisk wywo�uj�cy polecenia po wci�ni�ciu.
/// </summary>
class Button : public RenderableInstance, public TaskInvoker
{
public:

	void DrawOn(sf::RenderWindow& _window);

	/// <summary>
	/// Ustawia pozycj� obiektu.
	/// </summary>
	/// <param name="_position">- obiekt wektora</param>
	void SetPosition(const sf::Vector2f& _position);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_offset">- kierunek i d�ugo�� ruchu</param>
	void Move(const sf::Vector2f& _offset);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_x">- poziom; (-) lewo; (+) prawo</param>
	/// <param name="_y">- pion; (-) g�ra; (+) d�</param>
	void Move(const float& _x, const float& _y);

private:

	sf::IntRect		hitbox;			// pole mo�liwe do wci�ni�cia
	sf::Vector2f	hitboxOffset;	// pozycja hitboxa (relatywna do pozycji obiektu)
	bool			hitboxEnabled;	// stwierdza czy hitbox jest w��czony czy nie
};
/// <summary>
/// Wyskakuj�ce okienko z tekstem i przyciskami.
/// </summary>
class Popup
{
public:

	void DrawOn(sf::RenderWindow& _window);

	/// <summary>
	/// Ustawia pozycj� obiektu.
	/// </summary>
	/// <param name="_position">- obiekt wektora</param>
	void SetPosition(const sf::Vector2f& _position);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_offset">- kierunek i d�ugo�� ruchu</param>
	void Move(const sf::Vector2f& _offset);
	/// <summary>
	/// Przemieszcza obiekt w podanym kierunku.
	/// </summary>
	/// <param name="_x">- poziom; (-) lewo; (+) prawo</param>
	/// <param name="_y">- pion; (-) g�ra; (+) d�</param>
	void Move(const float& _x, const float& _y);

private:

	Textbox				textbox;	// okienko z tekstem
	std::vector<Button>	buttons;	// przyciski
};