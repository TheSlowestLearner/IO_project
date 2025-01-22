#include "GameObjects.h"

RenderableInstance::~RenderableInstance()
{ }

void RenderableInstance::SetSprite(const sf::IntRect& _rect)
{
	this->sprite.setTextureRect(_rect);
}
void RenderableInstance::SetTexture(sf::Texture* _texture)
{
	this->texture = _texture;
}
void RenderableInstance::SetPosition(const sf::Vector2f& _position)
{
	this->sprite.setPosition(_position);
}
void RenderableInstance::Move(const sf::Vector2f& _offset)
{
	this->sprite.move(_offset);
}
void RenderableInstance::Move(const float& _x, const float& _y)
{
	this->sprite.move(_x, _y);
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
void Textbox::SetPosition(const sf::Vector2f& _position)
{
	this->sprite.setPosition(_position);
	this->text.setPosition(_position + this->textOffset);
}
void Textbox::Move(const sf::Vector2f& _offset)
{
	this->sprite.move(_offset);
	this->text.move(_offset);
}
void Textbox::Move(const float& _x, const float& _y)
{
	this->sprite.move(_x, _y);
	this->text.move(_x, _y);
}
void Textbox::SetOffset(const sf::Vector2f& _offset)
{
	this->textOffset = _offset;
}
void Textbox::SetText(const std::string& _text)
{
	this->text.setString(_text);
}

void Button::DrawOn(sf::RenderWindow& _window)
{
	if (!this->hide)
		_window.draw(this->sprite);
}
void Button::SetPosition(const sf::Vector2f& _position)
{
	this->sprite.setPosition(_position);
	this->hitbox.top = this->sprite.getPosition().y + this->hitboxOffset.y;
	this->hitbox.left = this->sprite.getPosition().x + this->hitboxOffset.x;
}
void Button::Move(const sf::Vector2f& _offset)
{
	this->sprite.move(_offset);
	this->hitbox.top += _offset.y;
	this->hitbox.left += _offset.x;
}
void Button::Move(const float& _x, const float& _y)
{
	this->sprite.move(_x, _y);
	this->hitbox.top += _y;
	this->hitbox.left += _x;
}

void Popup::DrawOn(sf::RenderWindow& _window)
{
	this->textbox.DrawOn(_window);
	for (auto& button : this->buttons)
		button.DrawOn(_window);
}
void Popup::SetPosition(const sf::Vector2f& _position)
{
	this->textbox.SetPosition(_position);
	for (Button& button : this->buttons)
		button.SetPosition(_position);
}
void Popup::Move(const sf::Vector2f& _offset)
{
	this->textbox.Move(_offset);
	for (Button& button : this->buttons)
		button.Move(_offset);
}
void Popup::Move(const float& _x, const float& _y)
{
	this->textbox.Move(_x, _y);
	for (Button& button : this->buttons)
		button.Move(_x, _y);
}