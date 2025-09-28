#pragma once

#include <string>

#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>

class MusicWrapper {
private:
	sf::Music music;

public:
	bool play(std::string musicPath);
	bool pause();
	bool stop();
	bool setPlayingOffset(int seconds);
	sf::Time getDuration();
	sf::Time getPlayingOffset();
	void setVolume(float volume);
	void setPitch(float pitch);
};

