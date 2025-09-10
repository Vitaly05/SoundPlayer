#include "TimeHelper.h"

System::String^ TimeHelper::formatSeconds(int seconds) {
	int minutes = seconds / 60;
	int remainingSeconds = seconds % 60;

	if (remainingSeconds < 10) {
		return System::String::Format("{0}:0{1}", minutes, remainingSeconds);
	}

	return System::String::Format("{0}:{1}", minutes, remainingSeconds);
}