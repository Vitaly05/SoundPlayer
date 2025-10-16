#pragma once

#using <Newtonsoft.Json.dll>

namespace SoundPlayer {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace Newtonsoft::Json;

	public ref class UserSettings {
	public:
		[JsonProperty("volume")]
		int volume;

		[JsonProperty("pitch")]
		int pitch;

	public:
		UserSettings();
		UserSettings(int volume, int pitch);
	};
}