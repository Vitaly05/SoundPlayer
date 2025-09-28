#include "PlaylistNode.h"

PlaylistNode::PlaylistNode(std::string path, std::string name, MusicWrapper* wrapper) {
	this->path = path;
	this->name = name;
	this->musicWrapper = wrapper;

}

bool PlaylistNode::play() {
	return this->musicWrapper->play(this->path);
}