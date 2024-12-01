#include "GameObject.h"

constexpr char spriteFile[] = "";		// œcie¿ka do pliku z teksturami

GameObject::GameObject()
	: sprite(sf::Sprite()), texture(sf::Texture()), position(sf::Vector2f()), hidden(true)
{

}
void GameObject::show()
{
	this->hidden = false;
}
void GameObject::hide()
{
	this->hidden = true;
}
bool GameObject::is_shown() const
{
	return !this->hidden;
}