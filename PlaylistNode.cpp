#include "PlaylistNode.h"

PlaylistNode::PlaylistNode(std::string path, std::string name, MusicWrapper* wrapper) {
	this->path = path;
	this->name = name;
	this->musicWrapper = wrapper;

	this->readTags();
}

void PlaylistNode::readTags() {
    auto file = TagLib::File::Create(StringHelper::toSystemString(this->path));

	if (file->Tag->Performers->Length > 0) {
		this->artist = StringHelper::toStdString(file->Tag->Performers[0]);
	}

	if (file->Tag->Title) {
		this->name = StringHelper::toStdString(file->Tag->Title);
	}
}

bool PlaylistNode::play() {
	return this->musicWrapper->play(this->path);
}

MemoryStream^ PlaylistNode::getCoverImageMemoryStream() {
    auto file = TagLib::File::Create(StringHelper::toSystemString(this->path));

    if (file->Tag->Pictures->Length > 0)
    {
        auto pic = file->Tag->Pictures[0];
        array<Byte>^ bytes = pic->Data->Data;

        return gcnew MemoryStream(bytes);
    }

	return {};
}