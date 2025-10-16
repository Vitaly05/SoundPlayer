#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <regex>

#include "StringHelper.h"
#include "PlaylistInfo.h"
#include "UserSettings.h"

namespace fs = std::filesystem;

using namespace SoundPlayer;
using namespace System::IO;
using namespace System::Text::RegularExpressions;

static class DirectoryHelper {
public:
	static inline std::string musicFolderPath = "./music";
	static inline std::string playlistsFolderPath = "./playlists";
	static inline std::string playlistFileExt = ".json";
	static inline std::string userSettingsFileName = "usersettings.json";

public:
	static std::vector<fs::path> getMusicPathesArray();
	static void addMusic(String^ path);
	static void deleteMusic(std::string path);
	static void savePlaylist(PlaylistInfo^ playlistInfo);
	static String^ makeSafeFileName(String^ name);
	static List<PlaylistInfo^>^ getAllPlaylists();
	static void deleteFile(String^ path);
	static std::vector<fs::path> getPlaylistMusicPathesArray(PlaylistInfo^ playlistInfo);
	static void saveUserSetteings(UserSettings^ userSettings);
	static UserSettings^ getUserSetteings();
};

