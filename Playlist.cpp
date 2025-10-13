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

			prevNode = node;
		}
	}

	this->currentMusic = firstNode;
	this->firstMusic = firstNode;
}

bool Playlist::play() {
	if (this && this->currentMusic) {
		return this->currentMusic->play();
	}

	return false;
}

bool Playlist::play(PlaylistNode* music) {
	this->currentMusic = music;

	return this->currentMusic->play();
}

bool Playlist::pause() {
	if (!this || !this->currentMusic) {
		return false;
	}

	return this->musicWrapper->pause();
}

bool Playlist::playNext() {
	if (!this || !this->currentMusic) {
		return false;
	}

	PlaylistNode* next = this->currentMusic->next;

	if (!next) {
		return false;
	}

	this->playAnotherMusic(next);

	return true;
}

bool Playlist::playPrev() {
	if (!this || !this->currentMusic) {
		return false;
	}

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


bool Playlist::deleteNode(PlaylistNode* node) {
	if (node == this->currentMusic) {
		this->musicWrapper->play("");
	}

	if (node->prev == node) {
		this->musicWrapper->stop();

		this->currentMusic = nullptr;
		this->firstMusic = nullptr;

		return true;
	}

	node->prev->next = node->next;
	node->next->prev = node->prev;

	if (node == this->currentMusic) {
		this->currentMusic = node->next;
	}

	return false;
}