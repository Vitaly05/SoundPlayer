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
	/// <summary>
	/// Returns true if this node was the last one, and false if there is another node.
	/// </summary>
	bool deleteNode(PlaylistNode* node);
};

