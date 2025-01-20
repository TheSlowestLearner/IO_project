#pragma once
#include "GameObjects.h"

/// <summary>
/// Abstrakcja klasy tworz¹cej renderowalne obiekty.
/// </summary>
class RenderableCreator
{
public:

	virtual ~RenderableCreator() = 0;

private:


};
/// <summary>
/// Klasa tworz¹ca instancje dekoracji.
/// </summary>
class DecorationCreator : RenderableCreator
{
public:

	static Decoration* MakeDecoration(sf::Texture& texture, const sf::IntRect& rect);

private:


};
/// <summary>
/// Klasa tworz¹ca instancje pól tekstowych.
/// </summary>
class TextboxCreator : RenderableCreator
{
public:

	static Textbox* MakeTextbox(sf::Texture& texture, const sf::IntRect& rect, const sf::Vector2f& offset, const std::string& text);

private:


};
/// <summary>
/// Klasa tworz¹ca instancje przycisków.
/// </summary>
class ButtonCreator : RenderableCreator
{
public:

	static Button* MakeButton(sf::Texture& texture, const sf::IntRect& rect);

private:


};
/// <summary>
/// Klasa tworz¹ca instancje wyskakuj¹cych okienek.
/// </summary>
class PopupCreator : RenderableCreator
{
public:

	static Popup* MakePopup();

private:


};