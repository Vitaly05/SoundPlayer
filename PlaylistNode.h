#pragma once

#include <string>

#include "MusicWrapper.h"
#include "StringHelper.h"

#using <TagLibSharp.dll>

using namespace TagLib;
using namespace System;
using namespace System::IO;

class PlaylistNode {
private:
	void readTags();

public:
	MusicWrapper* musicWrapper = nullptr;
	std::string path;
	std::string name;
	std::string artist = "Unknown";
	PlaylistNode* next = nullptr;
	PlaylistNode* prev = nullptr;

	PlaylistNode(std::string path, std::string name, MusicWrapper* wrapper);
	bool play();
	MemoryStream^ getCoverImageMemoryStream();
};

