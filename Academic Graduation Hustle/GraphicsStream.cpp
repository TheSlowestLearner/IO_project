#include "GraphicsStream.h"

// œcie¿ka do pliku ze sprite'ami gracza
const char* player_spritesheet_path = "graphics/spritesheet_placeholder.png";

// œcie¿ka do pliku ze sprite'ami przeciwników
const char* enemy_spritesheet_path = "graphics/spritesheet_placeholder.png";

// œcie¿ka do pliku ze sprite'ami dekoracji
const char* decoration_spritesheet_path = "graphics/spritesheet_placeholder.png";

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