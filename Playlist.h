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

public:
	PlaylistNode* currentMusic;
	PlaylistNode* firstMusic;

private:
	void playAnotherMusic(PlaylistNode* music);

public:
	Playlist(MusicWrapper* wrapper, std::vector<fs::path> musicPathes);
	bool play();
	bool play(PlaylistNode* music);
	bool pause();
	bool playNext();
	bool playPrev();
};

