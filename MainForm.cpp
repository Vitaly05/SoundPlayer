
#include "MainForm.h"

#include <Windows.h>

#include "DirectoryHelper.h"

using namespace SoundPlayer;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// Console for debug
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);

	return 0;
}

void MainForm::setMusicInfo() {
	int duration = this->musicWrapper->getDuration().asSeconds();

	this->musicProgressBar->Maximum = duration;
	this->maxTime->Text = TimeHelper::formatSeconds(duration);
	this->musicTimer->Start();
}

int MainForm::getTrackBarValue(System::Object^ sender) {
	TrackBar^ trackBar = safe_cast<TrackBar^>(sender);

	return trackBar->Value;
}

int MainForm::getNumericUpDownValue(System::Object^ sender) {
	NumericUpDown^ numericUpDown = safe_cast<NumericUpDown^>(sender);

	return Decimal::ToInt32(numericUpDown->Value);
}

System::Void MainForm::playButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool res = this->playlist->play();

	if (res) {
		this->setMusicInfo();
	}
}

System::Void MainForm::pauseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool res = this->playlist->pause();

	if (res) {
		this->musicTimer->Stop();
	}
}

System::Void MainForm::musicTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	int offset = this->musicWrapper->getPlayingOffset().asSeconds();

	this->currentTime->Text = TimeHelper::formatSeconds(offset);

	this->isProgrammaticTrackChange = true;
	this->musicProgressBar->Value = offset;
}

System::Void MainForm::musicProgressBar_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->isProgrammaticTrackChange) {
		this->isProgrammaticTrackChange = false;

		return;
	}

	TrackBar^ trackBar = safe_cast<TrackBar^>(sender);

	this->musicWrapper->setPlayingOffset(trackBar->Value);
	this->currentTime->Text = TimeHelper::formatSeconds(trackBar->Value);
}

System::Void MainForm::nextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool res = this->playlist->playNext();

	if (res) {
		this->setMusicInfo();
	}
}

System::Void MainForm::prevButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool res = this->playlist->playPrev();

	if (res) {
		this->setMusicInfo();
	}
}

System::Void MainForm::volumeBar_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	int newVolume = this->getTrackBarValue(sender);

	this->musicWrapper->setVolume(newVolume);
	this->volumeUpDown->Value = newVolume;
}

System::Void MainForm::volumeUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	int newVolume = this->getNumericUpDownValue(sender);

	this->musicWrapper->setVolume(newVolume);
	this->volumeBar->Value = newVolume;
	this->volumeUpDown->Value = newVolume;
}

System::Void MainForm::pitchBar_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	int newPitch = this->getTrackBarValue(sender);

	float floatPitch = (float)newPitch / 100;
	this->musicWrapper->setPitch(floatPitch);

	this->pitchUpDown->Value = newPitch;
}

System::Void MainForm::pitchUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	int newPitch = this->getNumericUpDownValue(sender);

	float floatPitch = (float)newPitch / 100;
	this->musicWrapper->setPitch(floatPitch);

	this->pitchBar->Value = newPitch;
	this->pitchUpDown->Value = newPitch;
}

System::Void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	auto musicPatches = DirectoryHelper::getMusicPathesArray();
	
	this->playlist = new Playlist(this->musicWrapper, musicPatches);
}