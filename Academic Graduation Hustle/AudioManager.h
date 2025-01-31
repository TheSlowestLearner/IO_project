#pragma once
#include<SFML/Audio.hpp>

constexpr int sound_amount = 9;
constexpr int music_amount = 1;

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
		MUSIC1,
		MUSIC2,
		MUSIC3,
	};

	/// <summary>
	/// Odgrywa efekt d�wi�kowy.
	/// </summary>
	/// <param name="sound">- identyfikator d�wi�ku</param>
	static void PlaySound(const Sound& sound);
	/// <summary>
	/// Odgrywa muzyk�.
	/// </summary>
	/// <param name="music">- identyfikator utworu</param>
	static void PlayMusic(const Music& music);

private:

	static sf::SoundBuffer sounds[sound_amount];
	static sf::Music soundtracks[music_amount];
};