#include "Playlist.h"

Playlist::Playlist(MusicWrapper* wrapper) {
	this->musicWrapper = wrapper;

	PlaylistNode* first = new PlaylistNode("test.mp3", this->musicWrapper);
	PlaylistNode* second = new PlaylistNode("test2.mp3", this->musicWrapper);

	first->next = second;
	second->prev = first;

	this->musicList.push_back(first);
	this->musicList.push_back(second);

	this->currentMusic = this->musicList.front();
}

bool Playlist::play() {
	return this->currentMusic->play();
}

bool Playlist::pause() {
	return this->musicWrapper->pause();
}

bool Playlist::playNext() {
	PlaylistNode* next = this->currentMusic->next;

	if (!next) {
		return false;
	}

	this->playAnotherMusic(next);

	return true;
}

bool Playlist::playPrev() {
	PlaylistNode* prev = this->currentMusic->prev;

	if (!prev) {
		return false;
	}

	this->playAnotherMusic(prev);

	return true;
}

void Playlist::playAnotherMusic(PlaylistNode* music) {
	this->musicWrapper->stop();

	music->play();
	this->currentMusic = music;
}