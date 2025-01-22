#include "ObjectCreators.h"

RenderableCreator::~RenderableCreator()
{ }

Decoration* DecorationCreator::MakeDecoration(sf::Texture* texture, const sf::IntRect& rect)
{
	Decoration* decoration = new Decoration();
	decoration->SetTexture(texture);
	decoration->SetSprite(rect);

	return decoration;
}

Textbox* TextboxCreator::MakeTextbox(sf::Texture* texture, const sf::IntRect& rect, const sf::Vector2f& offset, const std::string& text)
{
	Textbox* textbox = new Textbox();
	textbox->SetTexture(texture);
	textbox->SetSprite(rect);
	textbox->SetOffset(offset);
	textbox->SetText(text);

	return textbox;
}

Button* ButtonCreator::MakeButton(sf::Texture* texture, const sf::IntRect& rect)
{
	Button* button = new Button();
	button->SetTexture(texture);
	button->SetSprite(rect);

	return button;
}