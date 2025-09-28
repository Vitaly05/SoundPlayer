#pragma once

#include <string>
#include <vector>
#include <filesystem>

#include "MusicWrapper.h"
#include "PlaylistNode.h"

namespace fs = std::filesystem;

class Playlist {
private:
	MusicWrapper* musicWrapper = nullptr;
	std::vector<PlaylistNode*> musicList;

public:
	PlaylistNode* currentMusic;

private:
	void playAnotherMusic(PlaylistNode* music);

public:
	Playlist(MusicWrapper* wrapper, std::vector<fs::path> musicPathes);
	bool play();
	bool pause();
	bool playNext();
	bool playPrev();
};

