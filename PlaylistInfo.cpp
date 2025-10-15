#include "DirectoryHelper.h"
#include "Playlist.h"

PlaylistInfo::PlaylistInfo(String^ name, List<String^>^ musicPathes) {
	this->name = name;
	this->musicPathes = musicPathes;
}

void PlaylistInfo::Delete() {
	DirectoryHelper::deleteFile(this->path);
}