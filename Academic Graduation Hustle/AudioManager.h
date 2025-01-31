#pragma once
#include<SFML/Audio.hpp>

constexpr int sound_amount = 3;
constexpr int music_amount = 3;

class AudioManager
{
public:

	enum Sound
	{
		SOUND1,
		SOUND2,
		SOUND3,
	};
	enum Music
	{
		MUSIC1,
		MUSIC2,
		MUSIC3,
	};

	static void PlaySound(const Sound& sound);

	static void PlayMusic(const Music& music);

private:


};