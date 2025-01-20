#include "ObjectCreators.h"

Decoration* DecorationCreator::MakeDecoration(sf::Texture& texture, const sf::IntRect& rect)
{
	Decoration* decoration = new Decoration();
	decoration->SetTexture(texture);
	decoration->SetSprite(rect);

	return decoration;
}