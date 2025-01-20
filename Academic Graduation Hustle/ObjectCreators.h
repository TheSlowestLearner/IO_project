#pragma once
#include "GameObjects.h"

/// <summary>
/// Abstrakcja klasy tworz�cej renderowalne obiekty.
/// </summary>
class RenderableCreator
{
public:

	virtual ~RenderableCreator() = 0;

	static RenderableInstance* MakeRenderableInstance();

private:


};
/// <summary>
/// Klasa tworz�ca instancje dekoracji.
/// </summary>
class DecorationCreator : RenderableCreator
{
public:

	static Decoration* MakeDecoration(sf::Texture& texture, const sf::IntRect& rect);

private:


};
/// <summary>
/// Klasa tworz�ca instancje p�l tekstowych.
/// </summary>
class TextboxCreator : RenderableCreator
{
public:

	static Textbox* MakeTextbox();

private:


};
/// <summary>
/// Klasa tworz�ca instancje przycisk�w.
/// </summary>
class ButtonCreator : RenderableCreator
{
public:

	static Button* MakeButton();

private:


};
/// <summary>
/// Klasa tworz�ca instancje wyskakuj�cych okienek.
/// </summary>
class PopupCreator : RenderableCreator
{
public:

	static Popup* MakePopup();

private:


};