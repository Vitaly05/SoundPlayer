#include "UserSettings.h"

using namespace SoundPlayer;

UserSettings::UserSettings() {
	this->volume = 100;
	this->pitch = 100;
}

UserSettings::UserSettings(int volume, int pitch) {
	this->volume = volume;
	this->pitch = pitch;
}