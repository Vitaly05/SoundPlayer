#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <regex>

#include "StringHelper.h"

namespace fs = std::filesystem;

static class DirectoryHelper {
public:
	static inline std::string musicFolderPath = "./music";

public:
	static std::vector<fs::path> getMusicPathesArray();
	static void addMusic(System::String^ path);
	static void deleteMusic(std::string path);
};

