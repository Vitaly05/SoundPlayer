
#include "MainForm.h"

#include <Windows.h>

#include "DirectoryHelper.h"

using namespace SoundPlayer;

[STAThreadAttribute]
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
	auto currentMusic = this->playlist->currentMusic;

	this->musicProgressBar->Maximum = duration;
	this->maxTime->Text = TimeHelper::formatSeconds(duration);
	this->musicTimer->Start();

	this->musicName->Text = StringHelper::toSystemString(currentMusic->name);
	this->musicArtist->Text = StringHelper::toSystemString(currentMusic->artist);

	this->setMusicCover();
}

void MainForm::setDefaultMusicInfo() {
	int duration = 0;
	PlaylistNode* currentMusic = nullptr;

	this->musicProgressBar->Maximum = 0;
	this->maxTime->Text = TimeHelper::formatSeconds(0);
	this->musicTimer->Stop();

	this->musicName->Text = "Выберите музыку";
	this->musicArtist->Text = "-";

	this->musicPictureBox->Image = this->defaultMusicImage;
}

void MainForm::setMusicCover() {
	auto ms = this->playlist->currentMusic->getCoverImageMemoryStream();

	if (!ms) {
		this->musicPictureBox->Image = this->defaultMusicImage;
	}
	else {
		this->musicPictureBox->Image = System::Drawing::Image::FromStream(ms);
	}
}

int MainForm::getTrackBarValue(System::Object^ sender) {
	TrackBar^ trackBar = safe_cast<TrackBar^>(sender);

	return trackBar->Value;
}

int MainForm::getNumericUpDownValue(System::Object^ sender) {
	NumericUpDown^ numericUpDown = safe_cast<NumericUpDown^>(sender);

	return Decimal::ToInt32(numericUpDown->Value);
}

void MainForm::scanMusicAndAddButtons() {
	auto musicPatches = DirectoryHelper::getMusicPathesArray();

	if (musicPatches.size() == 0) {
		this->allMusicPage->Controls->Add(this->allPageEmptyLabel);

		return;
	}

	this->playlist = new Playlist(this->musicWrapper, musicPatches);

	PlaylistNode* music = this->playlist->firstMusic;

	this->allMusicPage->Controls->Clear();

	do {
		addMusicButton(music->name, music->path, music);

		music = music->next;
	} while (music != this->playlist->firstMusic);
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
	this->defaultMusicImage = this->musicPictureBox->Image;

	this->scanMusicAndAddButtons();
}

System::Windows::Forms::TableLayoutPanel^ MainForm::createMusicButton(std::string text, std::string path, PlaylistNode* node) {
	auto newMusicButtonTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
	auto newMusicButton = (gcnew System::Windows::Forms::Button());
	auto newDeleteMusicButton = (gcnew System::Windows::Forms::Button());

	newMusicButtonTableLayoutPanel->ColumnCount = 2;
	newMusicButtonTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
		100)));
	newMusicButtonTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
		40)));
	newMusicButtonTableLayoutPanel->Controls->Add(newMusicButton, 0, 0);
	newMusicButtonTableLayoutPanel->Controls->Add(newDeleteMusicButton, 1, 0);
	newMusicButtonTableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
	newMusicButtonTableLayoutPanel->Location = System::Drawing::Point(3, 75);
	newMusicButtonTableLayoutPanel->Name = L"musicButtonTableLayoutPanel";
	newMusicButtonTableLayoutPanel->RowCount = 1;
	newMusicButtonTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
	newMusicButtonTableLayoutPanel->Size = System::Drawing::Size(263, 39);

	newMusicButton->Cursor = System::Windows::Forms::Cursors::Hand;
	newMusicButton->Dock = System::Windows::Forms::DockStyle::Fill;
	newMusicButton->Location = System::Drawing::Point(3, 3);
	newMusicButton->Margin = System::Windows::Forms::Padding(3, 3, 0, 3);
	newMusicButton->Name = L"musicButton-" + StringHelper::toSystemString(text);
	newMusicButton->Size = System::Drawing::Size(220, 34);
	newMusicButton->Text = StringHelper::toSystemString(text);
	newMusicButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	newMusicButton->UseVisualStyleBackColor = true;
	newMusicButton->Click += gcnew System::EventHandler(this, &MainForm::musicButton_Click);
	newMusicButton->Tag = IntPtr(node);

	newDeleteMusicButton->Cursor = System::Windows::Forms::Cursors::Hand;
	newDeleteMusicButton->Dock = System::Windows::Forms::DockStyle::Fill;
	newDeleteMusicButton->ImageKey = L"trash.png";
	newDeleteMusicButton->ImageList = this->iconsImageList;
	newDeleteMusicButton->Location = System::Drawing::Point(223, 3);
	newDeleteMusicButton->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
	newDeleteMusicButton->Name = L"deleteMusicButton";
	newDeleteMusicButton->Size = System::Drawing::Size(37, 34);
	newDeleteMusicButton->UseVisualStyleBackColor = true;
	newDeleteMusicButton->Click += gcnew System::EventHandler(this, &MainForm::DeleteMusicButton_Click);
	newDeleteMusicButton->Tag = IntPtr(node);

	return newMusicButtonTableLayoutPanel;
}

System::Void MainForm::addMusicButton(std::string text, std::string path, PlaylistNode* node) {
	auto musicButton = this->createMusicButton(text, path, node);

	this->allMusicPage->Controls->Add(musicButton);
	this->toolTip->SetToolTip(musicButton, StringHelper::toSystemString(text));
}

System::Void MainForm::musicButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);

	IntPtr p = safe_cast<IntPtr>(button->Tag);
	PlaylistNode* node = static_cast<PlaylistNode*>(p.ToPointer());
	
	bool res = this->playlist->play(node);

	if (res) {
		this->setMusicInfo();
	}
}

System::Void MainForm::DeleteMusicButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);

	IntPtr p = safe_cast<IntPtr>(button->Tag);
	PlaylistNode* node = static_cast<PlaylistNode*>(p.ToPointer());

	bool isPlaying = node == this->playlist->currentMusic;

	bool isLastNode = this->playlist->deleteNode(node);

	DirectoryHelper::deleteMusic(node->path);

	button->Parent->Visible = false;

	if (isLastNode) {
		this->allMusicPage->Controls->Add(this->allPageEmptyLabel);

		this->setDefaultMusicInfo();
		
	} else if (isPlaying) {
		bool res = this->playlist->play();

		if (res) {
			this->setMusicInfo();
		}
	}

	delete node;
}

System::Void MainForm::openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->addMusicFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		for each (auto fileName in this->addMusicFileDialog->FileNames) {
			DirectoryHelper::addMusic(fileName);
		}

		this->scanMusicAndAddButtons();
	}
}