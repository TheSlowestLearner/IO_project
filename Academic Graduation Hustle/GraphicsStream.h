#pragma once
#include "TaskLogic.h"

// �cie�ka do pliku ze sprite'ami gracza
constexpr char player_spritesheet_path[]		= "graphics/spritesheet_placeholder.png";

// �cie�ka do pliku ze sprite'ami przeciwnik�w
constexpr char enemy_spritesheet_path[]			= "graphics/spritesheet_placeholder.png";

// �cie�ka do pliku ze sprite'ami dekoracji
constexpr char decoration_spritesheet_path[]	= "graphics/spritesheet_placeholder.png";

/// <summary>
/// Zawiera pozycje wszystkich sprite'�w w pliku.
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
/// Przechowuje strumienie do plik�w ze sprite'ami.
/// </summary>
class SpriteStream
{
public:

	/// <summary>
	/// Ustanawia strumienie.
	/// </summary>
	static void Init();
	/// <returns>Wska�nik do strumienia tekstur gracza.</returns>
	static sf::Texture* GetPlayerTexture();
	/// <returns>Wska�nik do strumienia tekstur przeciwnik�w.</returns>
	static sf::Texture* GetEnemyTexture();
	/// <returns>Wska�nik do strumienia tekstur dekoracji.</returns>
	static sf::Texture* GetDecorationTexture();

private:

	static sf::Texture player_textures;		// tekstury gracza
	static sf::Texture enemy_textures;		// tekstury przeciwnik�w
	static sf::Texture decoration_textures;	// tekstury dekoracji
};