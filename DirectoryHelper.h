#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <regex>

namespace fs = std::filesystem;

static class DirectoryHelper {
public:
	static inline std::string musicFolderPath = "./music";

public:
	static std::vector<fs::path> getMusicPathesArray();
};

