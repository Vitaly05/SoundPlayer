#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include <random>
#include <algorithm>

#include "MusicWrapper.h"
#include "PlaylistNode.h"

namespace fs = std::filesystem;

using namespace System::Collections::Generic;

class Playlist {
private:
	MusicWrapper* musicWrapper = nullptr;
	std::vector<int> randomOrder = {};
	int currentRandomIndex = 0;
	bool isRandomMode = false;

public:
	PlaylistNode* currentMusic;
	PlaylistNode* firstMusic;

private:
	void initRandomOrder();
	void playAnotherMusic(PlaylistNode* music);
	PlaylistNode* getNextRandom();
	PlaylistNode* getPrevRandom();

public:
	Playlist(MusicWrapper* wrapper, std::vector<fs::path> musicPathes, bool isRandomMode = false);
	Playlist(MusicWrapper* wrapper, List<String^>^ musicPathes, bool isRandomMode = false);
	bool play();
	bool play(PlaylistNode* music);
	bool pause();
	bool playNext();
	bool playPrev();
	/// <summary>
	/// Returns true if this node was the last one, and false if there is another node.
	/// </summary>
	bool deleteNode(PlaylistNode* node);
	bool playInRandomOrder();
	void playInDefaultOrder();
};

