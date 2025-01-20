#include "GameObjects.h"

constexpr char spriteFile[] = "graphics/spritesheet_placeholder.png";	// �cie�ka do pliku z teksturami

/// <summary>
/// Zawiera pozycje wszystkich sprite'�w w pliku.
/// </summary>
namespace sp
{
	const sf::Rect<int> ExampleSprite1(0, 0, 200, 200);		// Przyk�ad 1
	const sf::Rect<int> ExampleSprite2(200, 200, 200, 200);	// Przyk�ad 2
	const sf::Rect<int> ExampleSprite3(400, 400, 200, 200);	// Przyk�ad 3
	const sf::Rect<int> ExampleSprite4(600, 600, 200, 200);	// Przyk�ad 4
	const sf::Rect<int> ExampleSprite5(800, 800, 200, 200);	// Przyk�ad 5
}

void RenderableInstance::SetSprite(const sf::Sprite& _sprite)
{
	this->sprite = _sprite;
}
void RenderableInstance::SetTexture(const sf::Texture& _texture)
{
	this->texture = _texture;
}
void RenderableInstance::SetPosition(const sf::Vector2f& _position)
{
	this->sprite.setPosition(_position);
}

void Decoration::DrawOn(sf::RenderWindow& _window)
{
	if (!this->hide)
		_window.draw(this->sprite);
}

void Textbox::DrawOn(sf::RenderWindow& _window)
{
	if (!this->hide)
	{
		_window.draw(this->sprite);
		_window.draw(this->text);
	}
}

void Button::DrawOn(sf::RenderWindow& _window)
{
	if (!this->hide)
		_window.draw(this->sprite);
}

void Popup::DrawOn(sf::RenderWindow& _window)
{
	this->textbox.DrawOn(_window);
	for (auto& button : this->buttons)
		button.DrawOn(_window);
}