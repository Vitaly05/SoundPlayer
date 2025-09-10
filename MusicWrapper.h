#pragma once

#include <string>

#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>

class MusicWrapper {
private:
	sf::Music music;
	std::string musicFolder = "music/";

	std::string getMusicPath(std::string musicName);

public:
	bool play();
	bool pause();
	bool setPlayingOffset(int seconds);
	sf::Time getDuration();
	sf::Time getPlayingOffset();
};

