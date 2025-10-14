#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <regex>

#include "StringHelper.h"
#include "PlaylistInfo.h"

namespace fs = std::filesystem;

using namespace SoundPlayer;
using namespace System::IO;
using namespace System::Text::RegularExpressions;

static class DirectoryHelper {
public:
	static inline std::string musicFolderPath = "./music";
	static inline std::string playlistsFolderPath = "./playlists";

public:
	static std::vector<fs::path> getMusicPathesArray();
	static void addMusic(System::String^ path);
	static void deleteMusic(std::string path);
	static void savePlaylist(PlaylistInfo^ playlistInfo);
	static String^ makeSafeFileName(String^ name);
};

