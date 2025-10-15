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

void DirectoryHelper::addMusic(System::String^ path) {
	auto name = Path::GetFileName(path);
	auto destPath = Path::Combine(StringHelper::toSystemString(DirectoryHelper::musicFolderPath), name);

	Directory::CreateDirectory(StringHelper::toSystemString(DirectoryHelper::musicFolderPath));

	File::Copy(path, destPath, true);
}

void DirectoryHelper::deleteMusic(std::string path) {
	File::Delete(StringHelper::toSystemString(path));
}

void DirectoryHelper::savePlaylist(PlaylistInfo^ playlistInfo) {
	Directory::CreateDirectory(StringHelper::toSystemString(DirectoryHelper::playlistsFolderPath));

	auto path = Path::Combine(
		StringHelper::toSystemString(DirectoryHelper::playlistsFolderPath),
		DirectoryHelper::makeSafeFileName(playlistInfo->name) + StringHelper::toSystemString(DirectoryHelper::playlistFileExt)
	);

	playlistInfo->path = path;

	String^ json = JsonConvert::SerializeObject(playlistInfo, Formatting::None);

	File::WriteAllText(
		path,
		json
	);
}

String^ DirectoryHelper::makeSafeFileName(String^ name) {
	String^ invalidChars = Regex::Escape(gcnew String(Path::GetInvalidFileNameChars()));
	String^ pattern = "[" + invalidChars + "]";
	String^ safeName = Regex::Replace(name, pattern, "_");

	safeName = safeName->Replace(" ", "_");

	return safeName;
}

List<PlaylistInfo^>^ DirectoryHelper::getAllPlaylists() {
	List<PlaylistInfo^>^ playlists = gcnew List<PlaylistInfo^>();

	try {
		for (const auto& entry : fs::directory_iterator(DirectoryHelper::playlistsFolderPath)) {
			std::string ext = entry.path().extension().string();

			if (entry.is_regular_file() && ext == DirectoryHelper::playlistFileExt) {
				auto path = StringHelper::toSystemString(entry.path().string());
				auto data = File::ReadAllText(path);

				PlaylistInfo^ playlist = JsonConvert::DeserializeObject<PlaylistInfo^>(data);
				playlists->Add(playlist);
			}
		}
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << '\n';

		return gcnew List<PlaylistInfo^>();
	}

	return playlists;
}

void DirectoryHelper::deleteFile(String^ path) {
	File::Delete(path);
}

std::vector<fs::path> DirectoryHelper::getPlaylistMusicPathesArray(PlaylistInfo^ playlistInfo) {
	std::vector<fs::path> musicPathes;

	try {
		for each (auto path in playlistInfo->musicPathes) {
			auto fsPath = fs::path(StringHelper::toStdString(path));
			std::string ext = fsPath.extension().string();

			if (std::regex_match(ext, std::regex(R"(.mp3|.ogg)"))) {
				musicPathes.push_back(fsPath);
			}
		}
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	return musicPathes;
}