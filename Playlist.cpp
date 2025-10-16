#include "Playlist.h"

Playlist::Playlist(MusicWrapper* wrapper, std::vector<fs::path> musicPathes, bool isRandomMode) {
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

	if (isRandomMode) {
		this->initRandomOrder();

		this->currentRandomIndex = 0;
		this->isRandomMode = true;
	}
}

Playlist::Playlist(MusicWrapper* wrapper, List<String^>^ musicPathes, bool isRandomMode) {
	this->musicWrapper = wrapper;

	PlaylistNode* firstNode = nullptr;
	PlaylistNode* prevNode = nullptr;

	for each (auto path in musicPathes) {
		fs::path fsPath = fs::path(StringHelper::toStdString(path));
		auto node = new PlaylistNode(fsPath.string(), fsPath.filename().string(), this->musicWrapper);

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

	if (isRandomMode) {
		this->initRandomOrder();

		this->currentRandomIndex = 0;
		this->isRandomMode = true;
	}
}

void Playlist::initRandomOrder() {
	std::random_device rd;
	std::mt19937 g(rd());

	std::vector<int> arr;

	PlaylistNode* current = this->currentMusic;
	int i = 0;

	do {
		arr.push_back(i++);

		current = current->next;
	} while (current != this->currentMusic);

	std::shuffle(arr.begin(), arr.end(), g);

	this->randomOrder = arr;
}

bool Playlist::play() {
	if (this && this->currentMusic) {
		return this->currentMusic->play();
	}

	return false;
}

bool Playlist::play(PlaylistNode* music) {
	this->currentMusic = music;
	this->firstMusic = music;

	this->initRandomOrder();

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

	PlaylistNode* next;

	if (this->isRandomMode) {
		next = this->getNextRandom();
	}
	else {
		next = this->currentMusic->next;
	}

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

	PlaylistNode* prev;

	if (this->isRandomMode) {
		prev = this->getPrevRandom();
	}
	else {
		prev = this->currentMusic->prev;
	}

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

bool Playlist::playInRandomOrder() {
	this->initRandomOrder();

	this->currentRandomIndex = 0;
	this->isRandomMode = true;

	return this->playNext();
}

void Playlist::playInDefaultOrder() {
	this->isRandomMode = false;
}

PlaylistNode* Playlist::getNextRandom() {
	PlaylistNode* next = this->firstMusic;

	if (this->currentRandomIndex == this->randomOrder.size() - 1) {
		this->currentRandomIndex = 0;
	}
	else {
		this->currentRandomIndex++;
	}

	for (int i = 0; i < this->randomOrder[this->currentRandomIndex]; i++) {
		next = next->next;
	}

	return next;
}

PlaylistNode* Playlist::getPrevRandom() {
	PlaylistNode* prev = this->firstMusic;

	if (this->currentRandomIndex == 0) {
		this->currentRandomIndex = this->randomOrder.size() - 1;
	}
	else {
		this->currentRandomIndex--;
	}


	for (int i = 0; i < this->randomOrder[this->currentRandomIndex]; i++) {
		prev = prev->next;
	}

	return prev;
}