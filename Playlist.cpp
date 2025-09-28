#include "Playlist.h"

Playlist::Playlist(MusicWrapper* wrapper, std::vector<fs::path> musicPathes) {
	this->musicWrapper = wrapper;

	PlaylistNode* firstNode = nullptr;
	PlaylistNode* prevNode = nullptr;

	for (auto path : musicPathes) {
		auto node = new PlaylistNode(path.string(), path.filename().string(), this->musicWrapper);

		if (!firstNode) {
			node->next = node;
			node->prev = node;

			firstNode = node;
		}

		if (!prevNode) {
			prevNode = node;
		}
		else {
			node->prev = prevNode;
			node->next = firstNode;

			prevNode->next = node;
			firstNode->prev = node;
		}
	}

	this->currentMusic = firstNode;
	this->firstMusic = firstNode;
}

bool Playlist::play() {
	return this->currentMusic->play();
}

bool Playlist::play(PlaylistNode* music) {
	this->currentMusic = music;

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