#include "MusicWrapper.h"

std::string MusicWrapper::getMusicPath(std::string musicName) {
	return this->musicFolder + musicName;
}

bool MusicWrapper::play(std::string musicName) {
	if (this->music.getStatus() == sf::Music::Paused) {
		this->music.play();

		return true;
	}

	if (this->music.getStatus() == sf::Music::Playing) {
		this->music.stop();
	}

	if (!this->music.openFromFile(this->getMusicPath(musicName))) {
		return false;
	}

	this->music.play();

	return true;
}

bool MusicWrapper::pause() {
	if (this->music.getStatus() == sf::Music::Playing) {
		this->music.pause();

		return true;
	}

	return false;
}

bool MusicWrapper::stop() {
	this->music.stop();

	return true;
}

bool MusicWrapper::setPlayingOffset(int seconds) {
	if (this->getDuration().asSeconds() < seconds) {
		return false;
	}

	this->music.setPlayingOffset(sf::seconds(seconds));
	
	return true;
}

sf::Time MusicWrapper::getDuration() {
	return this->music.getDuration();
}

sf::Time MusicWrapper::getPlayingOffset() {
	return this->music.getPlayingOffset();
}

void MusicWrapper::setVolume(float volume) {
	this->music.setVolume(volume);
}