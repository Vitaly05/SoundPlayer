#pragma once

#include <string>
#include <vector>

#include "MusicWrapper.h"
#include "PlaylistNode.h"

class Playlist {
private:
	MusicWrapper* musicWrapper = nullptr;
	std::vector<PlaylistNode*> musicList;

public:
	PlaylistNode* currentMusic;

private:
	void playAnotherMusic(PlaylistNode* music);

public:
	Playlist(MusicWrapper* wrapper);
	bool play();
	bool pause();
	bool playNext();
	bool playPrev();
};

