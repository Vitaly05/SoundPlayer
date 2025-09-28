#include "DirectoryHelper.h"

std::vector<fs::path> DirectoryHelper::getMusicPathesArray() {
	std::vector<fs::path> musicPathes;

	try {
		for (const auto& entry : fs::directory_iterator(DirectoryHelper::musicFolderPath)) {
			std::string ext = entry.path().extension().string();

			if (entry.is_regular_file() && std::regex_match(ext, std::regex(R"(.mp3|.ogg)"))) {
				musicPathes.push_back(entry.path());
			}
		}
	} catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	return musicPathes;
}