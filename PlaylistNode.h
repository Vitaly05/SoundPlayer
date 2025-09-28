#pragma once

#include <string>

#include "MusicWrapper.h"

class PlaylistNode {
public:
	MusicWrapper* musicWrapper = nullptr;
	std::string path;
	std::string name;
	PlaylistNode* next = nullptr;
	PlaylistNode* prev = nullptr;

	PlaylistNode(std::string path, std::string name, MusicWrapper* wrapper);
	bool play();
};

