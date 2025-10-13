#pragma once

#include <string>

#include "MusicWrapper.h"
#include "taglib-2.1/taglib/tag.h"

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

