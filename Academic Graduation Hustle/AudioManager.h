#pragma once
#include<SFML/Audio.hpp>

constexpr int sound_amount = 9;
constexpr int music_amount = 2;

class AudioManager
{
public:

	enum Sound
	{
		CLICK,
		ENEMY_DYING,
		HARD_HIT,
		HEAL,
		PLAYER_DEATH,
		SELECT,
		SOFT_CLICK,
		SOFT_HIT,
		STEP,
	};
	enum Music
	{
		MAIN_THEME,
		MAIN_THEME_EXTENDED,
	};

	/// <summary>
	/// Funkcja u?ywana do inicjalizacji.
	/// </summary>
	static void LoadSounds();
	/// <summary>
	/// Odgrywa efekt d?wi?kowy.
	/// </summary>
	/// <param name="sound">- identyfikator d?wi?ku</param>
	static void PlaySound(const Sound& _sound);
	/// <summary>
	/// Odgrywa muzyk?.
	/// </summary>
	/// <param name="music">- identyfikator utworu</param>
	static void PlayMusic(const Music& _music);
	/// <summary>
	/// Wstrzymuje muzyk?.
	/// </summary>
	static void PauseMusic();
	/// <summary>
	/// Kontynuuje muzyk?.
	/// </summary>
	static void ContinueMusic();

private:

	static sf::SoundBuffer sounds[sound_amount];
	static sf::Music soundtracks[music_amount];

	static sf::Sound sound;
	static sf::Music* music;
};