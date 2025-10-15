#pragma once

#using <Newtonsoft.Json.dll>

namespace SoundPlayer {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace Newtonsoft::Json;

	public ref class PlaylistInfo {
	public:
		[JsonProperty("name")]
		String^ name;

		[JsonProperty("path")]
		String^ path;

		[JsonProperty("musicPathes")]
		List<String^>^ musicPathes;

	public:
		PlaylistInfo(String^ name, List<String^>^ musicPathes);
		void Delete();
	};
}