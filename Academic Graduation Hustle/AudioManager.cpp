#pragma once
#include "AudioManager.h"

sf::SoundBuffer AudioManager::sounds[sound_amount];
sf::Music AudioManager::soundtracks[music_amount];

sf::Sound AudioManager::sound;
sf::Music* AudioManager::music;

void AudioManager::LoadSounds()
{
	// dŸwiêki
	if (!sounds[0].loadFromFile("sounds/click.wav"))
		throw std::runtime_error("Failed to load the \"click\" sound!");
	if (!sounds[1].loadFromFile("sounds/enemy_dying.wav"))
		throw std::runtime_error("Failed to load the \"enemy_dying\" sound!");
	if (!sounds[2].loadFromFile("sounds/hard_hit.wav"))
		throw std::runtime_error("Failed to load the \"hard_hit\" sound!");
	if (!sounds[3].loadFromFile("sounds/heal.wav"))
		throw std::runtime_error("Failed to load the \"heal\" sound!");
	if (!sounds[4].loadFromFile("sounds/player_death.wav"))
		throw std::runtime_error("Failed to load the \"player_death\" sound!");
	if (!sounds[5].loadFromFile("sounds/select.wav"))
		throw std::runtime_error("Failed to load the \"select\" sound!");
	if (!sounds[6].loadFromFile("sounds/soft_click.wav"))
		throw std::runtime_error("Failed to load the \"soft_click\" sound!");
	if (!sounds[7].loadFromFile("sounds/soft_hit.wav"))
		throw std::runtime_error("Failed to load the \"soft_hit\" sound!");
	if (!sounds[8].loadFromFile("sounds/step.wav"))
		throw std::runtime_error("Failed to load the \"step\" sound!");

	// utwory
	// ;(

	music = &soundtracks[0];
}
void AudioManager::PlaySound(const Sound& _sound)
{
	sound.setBuffer(sounds[_sound]);
	sound.play();
}
void AudioManager::PlayMusic(const Music& _music)
{
	// nie ma muzyki wiêc nie ma funkcji
	music->setLoop(true);
}
void AudioManager::PauseMusic()
{
	music->pause();
}
void AudioManager::ContinueMusic()
{
	music->play();
}