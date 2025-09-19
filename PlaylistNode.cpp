#include "PlaylistNode.h"

PlaylistNode::PlaylistNode(std::string name, MusicWrapper* wrapper) {
	this->name = name;
	this->musicWrapper = wrapper;

}

bool PlaylistNode::play() {
	return this->musicWrapper->play(this->name);
}