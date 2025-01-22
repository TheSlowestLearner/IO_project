#include "GraphicsStream.h"

sf::Texture SpriteStream::player_textures;
sf::Texture SpriteStream::enemy_textures;
sf::Texture SpriteStream::decoration_textures;

void SpriteStream::Init()
{
	player_textures.loadFromFile(player_spritesheet_path);
	enemy_textures.loadFromFile(enemy_spritesheet_path);
	decoration_textures.loadFromFile(decoration_spritesheet_path);
}
sf::Texture* SpriteStream::GetPlayerTexture()
{
	return &player_textures;
}
sf::Texture* SpriteStream::GetEnemyTexture()
{
	return &enemy_textures;
}
sf::Texture* SpriteStream::GetDecorationTexture()
{
	return &decoration_textures;
}