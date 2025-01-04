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
	virtual void Draw() = 0;

private:

	sf::Sprite		sprite;
	sf::Texture		texture;
	sf::Vector2f	position;

	bool	hide;				// Zmienna warunkuj�ca rysowanie obiektu.
};
/// <summary>
/// Podstawowy renderowalny obiekt, mo�liwy do wy�wietlenia.
/// </summary>
class Decoration : RenderableInstance
{
public:



private:


};
/// <summary>
/// Okienko z tekstem.
/// </summary>
class Textbox : RenderableInstance
{
public:



private:

	sf::RectangleShape	box;
	sf::Text			text;
	sf::Vector2f		textPosition;
};
/// <summary>
/// Przycisk wywo�uj�cy polecenia po wci�ni�ciu.
/// </summary>
class Button : public RenderableInstance, public TaskInvoker
{
public:



private:

	sf::Vector2f	hitbox;		// pole mo�liwe do wci�ni�cia
};
/// <summary>
/// Wyskakuj�ce okienko z tekstem i przyciskami.
/// </summary>
class Popup
{
public:



private:

	Textbox				textbox;	// okienko z tekstem
	std::vector<Button>	buttons;	// przyciski
};