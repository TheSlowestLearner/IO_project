#pragma once
#include "TaskLogic.h"

// œcie¿ka do pliku ze sprite'ami gracza
constexpr char player_spritesheet_path[]		= "graphics/spritesheet_placeholder.png";

// œcie¿ka do pliku ze sprite'ami przeciwników
constexpr char enemy_spritesheet_path[]			= "graphics/spritesheet_placeholder.png";

// œcie¿ka do pliku ze sprite'ami dekoracji
constexpr char decoration_spritesheet_path[]	= "graphics/spritesheet_placeholder.png";

/// <summary>
/// Zawiera pozycje wszystkich sprite'ów w pliku.
/// </summary>
namespace sp
{
	namespace player
	{
		const sf::IntRect placeholder1(0, 0, 200, 200);			// tymczasowy 1
		const sf::IntRect placeholder2(200, 200, 200, 200);		// tymczasowy 2
	}
	namespace enemy
	{
		const sf::IntRect placeholder1(400, 800, 200, 200);		// tymczasowy 1
		const sf::IntRect placeholder2(800, 400, 200, 200);		// tymczasowy 2
	}
	namespace deco
	{
		const sf::IntRect placeholder1(300, 1300, 200, 200);	// tymczasowy 1
		const sf::IntRect placeholder2(1300, 300, 200, 200);	// tymczasowy 2
	}
}

/// <summary>
/// Przechowuje strumienie do plików ze sprite'ami.
/// </summary>
class SpriteStream
{
public:

	/// <summary>
	/// Ustanawia strumienie.
	/// </summary>
	static void Init();
	/// <returns>WskaŸnik do strumienia tekstur gracza.</returns>
	static sf::Texture* GetPlayerTexture();
	/// <returns>WskaŸnik do strumienia tekstur przeciwników.</returns>
	static sf::Texture* GetEnemyTexture();
	/// <returns>WskaŸnik do strumienia tekstur dekoracji.</returns>
	static sf::Texture* GetDecorationTexture();

private:

	static sf::Texture player_textures;		// tekstury gracza
	static sf::Texture enemy_textures;		// tekstury przeciwników
	static sf::Texture decoration_textures;	// tekstury dekoracji
};