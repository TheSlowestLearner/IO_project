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
	void	Draw();

private:

	sf::Sprite		sprite;
	sf::Texture		texture;
	sf::Vector2f	position;

	bool	hide;				// Zmienna warunkuj¹ca rysowanie obiektu.
};
/// <summary>
/// Podstawowy renderowalny obiekt, mo¿liwy do wyœwietlenia.
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

	sf::Text		text;
	sf::Vector2f	textPosition;
};
/// <summary>
/// Przycisk wywo³uj¹cy polecenia po wciœniêciu.
/// </summary>
class Button : RenderableInstance, TaskInvoker
{
public:



private:

	sf::Vector2f	hitbox;		// pole mo¿liwe do wciœniêcia
};
/// <summary>
/// Wyskakuj¹ce okienko z tekstem i przyciskami.
/// </summary>
class Popup
{
public:



private:

	Textbox				textbox;	// okienko z tekstem
	std::vector<Button>	buttons;	// przyciski
};