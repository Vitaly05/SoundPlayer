#pragma once

#include "MusicWrapper.h"
#include "Playlist.h"
#include "TimeHelper.h"
#include "StringHelper.h"

#include "CreatePlaylistForm.h"

namespace SoundPlayer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ playButton;
	private: System::Windows::Forms::Button^ pauseButton;
	private: System::Windows::Forms::Button^ nextButton;
	private: System::Windows::Forms::Button^ prevButton;
	private: System::Windows::Forms::ImageList^ iconsImageList;

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TrackBar^ musicProgressBar;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Label^ currentTime;
	private: System::Windows::Forms::Label^ maxTime;
	private: System::Windows::Forms::Timer^ musicTimer;


	private:
		MusicWrapper* musicWrapper = new MusicWrapper();
		Playlist* playlist;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::TrackBar^ volumeBar;

	private: System::Windows::Forms::NumericUpDown^ volumeUpDown;

	private: System::Windows::Forms::TrackBar^ pitchBar;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::NumericUpDown^ pitchUpDown;


	private: System::Windows::Forms::TabControl^ musicTabPanel;
	private: System::Windows::Forms::TabPage^ allMusicPage;
	private: System::Windows::Forms::Label^ volumeLabel;
	private: System::Windows::Forms::TabPage^ playlistsPage;
	private: System::Windows::Forms::Label^ pitchLabel;

	private: System::Windows::Forms::Button^ musicButtonTemplate;
	private: System::Windows::Forms::ToolTip^ toolTip;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
	private: System::Windows::Forms::PictureBox^ musicPictureBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel7;
	private: System::Windows::Forms::Label^ musicName;
	private: System::Windows::Forms::Label^ musicArtist;



	private: int playlistsCount = 0;
	private: bool isProgrammaticTrackChange = false;
	private: System::Windows::Forms::OpenFileDialog^ addMusicFileDialog;

	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addMusicStripMenuItem;

	private: System::Windows::Forms::Label^ allPageEmptyLabel;
	private: System::Windows::Forms::TableLayoutPanel^ musicButtonTableLayoutPanel;
	private: System::Windows::Forms::Button^ deleteMusicButton;
	private: System::Windows::Forms::Label^ playlistsPageEmptyLabel;
	private: System::Windows::Forms::ToolStripMenuItem^ playlistToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createPlaylistStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^ playlistGroup;
	private: System::Windows::Forms::Button^ playlistButton;
	private: System::Windows::Forms::Button^ editPlaylistButton;
	private: System::Windows::Forms::Button^ deletePlaylistButton;
	private: System::Windows::Forms::TabPage^ selectedPlaylistPage;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ selectedPlaylistEmptyLabel;






	private: System::Drawing::Image^ defaultMusicImage;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addMusicStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->playlistToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createPlaylistStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->prevButton = (gcnew System::Windows::Forms::Button());
			this->iconsImageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->pauseButton = (gcnew System::Windows::Forms::Button());
			this->playButton = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->musicProgressBar = (gcnew System::Windows::Forms::TrackBar());
			this->currentTime = (gcnew System::Windows::Forms::Label());
			this->maxTime = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->volumeLabel = (gcnew System::Windows::Forms::Label());
			this->volumeBar = (gcnew System::Windows::Forms::TrackBar());
			this->volumeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pitchLabel = (gcnew System::Windows::Forms::Label());
			this->pitchBar = (gcnew System::Windows::Forms::TrackBar());
			this->pitchUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->musicTabPanel = (gcnew System::Windows::Forms::TabControl());
			this->allMusicPage = (gcnew System::Windows::Forms::TabPage());
			this->musicButtonTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->deleteMusicButton = (gcnew System::Windows::Forms::Button());
			this->musicButtonTemplate = (gcnew System::Windows::Forms::Button());
			this->allPageEmptyLabel = (gcnew System::Windows::Forms::Label());
			this->playlistsPage = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->playlistGroup = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->deletePlaylistButton = (gcnew System::Windows::Forms::Button());
			this->playlistButton = (gcnew System::Windows::Forms::Button());
			this->editPlaylistButton = (gcnew System::Windows::Forms::Button());
			this->playlistsPageEmptyLabel = (gcnew System::Windows::Forms::Label());
			this->selectedPlaylistPage = (gcnew System::Windows::Forms::TabPage());
			this->selectedPlaylistEmptyLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->musicPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->musicName = (gcnew System::Windows::Forms::Label());
			this->musicArtist = (gcnew System::Windows::Forms::Label());
			this->musicTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->addMusicFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->musicProgressBar))->BeginInit();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeUpDown))->BeginInit();
			this->tableLayoutPanel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pitchBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pitchUpDown))->BeginInit();
			this->musicTabPanel->SuspendLayout();
			this->allMusicPage->SuspendLayout();
			this->musicButtonTableLayoutPanel->SuspendLayout();
			this->playlistsPage->SuspendLayout();
			this->playlistGroup->SuspendLayout();
			this->selectedPlaylistPage->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->musicPictureBox))->BeginInit();
			this->tableLayoutPanel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->playlistToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1063, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addMusicStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->fileToolStripMenuItem->Text = L"Музыка";
			// 
			// addMusicStripMenuItem
			// 
			this->addMusicStripMenuItem->Name = L"addMusicStripMenuItem";
			this->addMusicStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->addMusicStripMenuItem->Text = L"Добавить";
			this->addMusicStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// playlistToolStripMenuItem
			// 
			this->playlistToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createPlaylistStripMenuItem });
			this->playlistToolStripMenuItem->Name = L"playlistToolStripMenuItem";
			this->playlistToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->playlistToolStripMenuItem->Text = L"Плейлист";
			// 
			// createPlaylistStripMenuItem
			// 
			this->createPlaylistStripMenuItem->Name = L"createPlaylistStripMenuItem";
			this->createPlaylistStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->createPlaylistStripMenuItem->Text = L"Создать";
			this->createPlaylistStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::createPlaylistStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				7.142857F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30.61225F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40.81633F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				7.142857F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				7.142857F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				7.142857F)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->musicTabPanel, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel6, 2, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 90.09174F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.908257F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1063, 682);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->Controls->Add(this->prevButton, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->nextButton, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->pauseButton, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->playButton, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(403, 621);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(427, 58);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// prevButton
			// 
			this->prevButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->prevButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->prevButton->ImageKey = L"prev.png";
			this->prevButton->ImageList = this->iconsImageList;
			this->prevButton->Location = System::Drawing::Point(3, 3);
			this->prevButton->Name = L"prevButton";
			this->prevButton->Size = System::Drawing::Size(100, 52);
			this->prevButton->TabIndex = 2;
			this->prevButton->UseVisualStyleBackColor = false;
			this->prevButton->Click += gcnew System::EventHandler(this, &MainForm::prevButton_Click);
			// 
			// iconsImageList
			// 
			this->iconsImageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"iconsImageList.ImageStream")));
			this->iconsImageList->TransparentColor = System::Drawing::Color::Transparent;
			this->iconsImageList->Images->SetKeyName(0, L"next.png");
			this->iconsImageList->Images->SetKeyName(1, L"pause.png");
			this->iconsImageList->Images->SetKeyName(2, L"play.png");
			this->iconsImageList->Images->SetKeyName(3, L"prev.png");
			this->iconsImageList->Images->SetKeyName(4, L"trash.png");
			this->iconsImageList->Images->SetKeyName(5, L"edit.png");
			// 
			// nextButton
			// 
			this->nextButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->nextButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->nextButton->ImageKey = L"next.png";
			this->nextButton->ImageList = this->iconsImageList;
			this->nextButton->Location = System::Drawing::Point(321, 3);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(103, 52);
			this->nextButton->TabIndex = 3;
			this->nextButton->UseVisualStyleBackColor = false;
			this->nextButton->Click += gcnew System::EventHandler(this, &MainForm::nextButton_Click);
			// 
			// pauseButton
			// 
			this->pauseButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pauseButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pauseButton->ImageKey = L"pause.png";
			this->pauseButton->ImageList = this->iconsImageList;
			this->pauseButton->Location = System::Drawing::Point(215, 3);
			this->pauseButton->Name = L"pauseButton";
			this->pauseButton->Size = System::Drawing::Size(100, 52);
			this->pauseButton->TabIndex = 1;
			this->pauseButton->UseVisualStyleBackColor = false;
			this->pauseButton->Click += gcnew System::EventHandler(this, &MainForm::pauseButton_Click);
			// 
			// playButton
			// 
			this->playButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->playButton->ImageKey = L"play.png";
			this->playButton->ImageList = this->iconsImageList;
			this->playButton->Location = System::Drawing::Point(109, 3);
			this->playButton->Name = L"playButton";
			this->playButton->Size = System::Drawing::Size(100, 52);
			this->playButton->TabIndex = 0;
			this->playButton->UseVisualStyleBackColor = false;
			this->playButton->Click += gcnew System::EventHandler(this, &MainForm::playButton_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 3;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel3->Controls->Add(this->musicProgressBar, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->currentTime, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->maxTime, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(403, 582);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(427, 33);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// musicProgressBar
			// 
			this->musicProgressBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicProgressBar->LargeChange = 10;
			this->musicProgressBar->Location = System::Drawing::Point(39, 3);
			this->musicProgressBar->Maximum = 180;
			this->musicProgressBar->Name = L"musicProgressBar";
			this->musicProgressBar->Size = System::Drawing::Size(286, 27);
			this->musicProgressBar->TabIndex = 1;
			this->musicProgressBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::musicProgressBar_ValueChanged);
			// 
			// currentTime
			// 
			this->currentTime->AutoSize = true;
			this->currentTime->Dock = System::Windows::Forms::DockStyle::Fill;
			this->currentTime->Location = System::Drawing::Point(3, 0);
			this->currentTime->Name = L"currentTime";
			this->currentTime->Size = System::Drawing::Size(30, 33);
			this->currentTime->TabIndex = 2;
			this->currentTime->Text = L"0:00";
			this->currentTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// maxTime
			// 
			this->maxTime->AutoSize = true;
			this->maxTime->Dock = System::Windows::Forms::DockStyle::Fill;
			this->maxTime->Location = System::Drawing::Point(331, 0);
			this->maxTime->Name = L"maxTime";
			this->maxTime->Size = System::Drawing::Size(32, 33);
			this->maxTime->TabIndex = 3;
			this->maxTime->Text = L"0:00";
			this->maxTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->volumeLabel, 0, 2);
			this->tableLayoutPanel4->Controls->Add(this->volumeBar, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->volumeUpDown, 0, 1);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(911, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(69, 573);
			this->tableLayoutPanel4->TabIndex = 3;
			// 
			// volumeLabel
			// 
			this->volumeLabel->AutoSize = true;
			this->volumeLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->volumeLabel->Location = System::Drawing::Point(3, 515);
			this->volumeLabel->Name = L"volumeLabel";
			this->volumeLabel->Size = System::Drawing::Size(63, 58);
			this->volumeLabel->TabIndex = 8;
			this->volumeLabel->Text = L"Громкость";
			this->volumeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// volumeBar
			// 
			this->volumeBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->volumeBar->Location = System::Drawing::Point(3, 3);
			this->volumeBar->Maximum = 100;
			this->volumeBar->Name = L"volumeBar";
			this->volumeBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->volumeBar->Size = System::Drawing::Size(63, 452);
			this->volumeBar->TabIndex = 0;
			this->volumeBar->Value = 100;
			this->volumeBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::volumeBar_ValueChanged);
			// 
			// volumeUpDown
			// 
			this->volumeUpDown->Dock = System::Windows::Forms::DockStyle::Fill;
			this->volumeUpDown->Location = System::Drawing::Point(3, 461);
			this->volumeUpDown->Name = L"volumeUpDown";
			this->volumeUpDown->Size = System::Drawing::Size(63, 20);
			this->volumeUpDown->TabIndex = 4;
			this->volumeUpDown->UpDownAlign = System::Windows::Forms::LeftRightAlignment::Left;
			this->volumeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->volumeUpDown->ValueChanged += gcnew System::EventHandler(this, &MainForm::volumeUpDown_ValueChanged);
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 1;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel5->Controls->Add(this->pitchLabel, 0, 2);
			this->tableLayoutPanel5->Controls->Add(this->pitchBar, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->pitchUpDown, 0, 1);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(836, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(69, 573);
			this->tableLayoutPanel5->TabIndex = 6;
			// 
			// pitchLabel
			// 
			this->pitchLabel->AutoSize = true;
			this->pitchLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pitchLabel->Location = System::Drawing::Point(3, 515);
			this->pitchLabel->Name = L"pitchLabel";
			this->pitchLabel->Size = System::Drawing::Size(63, 58);
			this->pitchLabel->TabIndex = 9;
			this->pitchLabel->Text = L"Высота";
			this->pitchLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pitchBar
			// 
			this->pitchBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pitchBar->Location = System::Drawing::Point(3, 3);
			this->pitchBar->Maximum = 300;
			this->pitchBar->Name = L"pitchBar";
			this->pitchBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->pitchBar->Size = System::Drawing::Size(63, 452);
			this->pitchBar->TabIndex = 5;
			this->pitchBar->Value = 100;
			this->pitchBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::pitchBar_ValueChanged);
			// 
			// pitchUpDown
			// 
			this->pitchUpDown->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pitchUpDown->Location = System::Drawing::Point(3, 461);
			this->pitchUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->pitchUpDown->Name = L"pitchUpDown";
			this->pitchUpDown->Size = System::Drawing::Size(63, 20);
			this->pitchUpDown->TabIndex = 6;
			this->pitchUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->pitchUpDown->ValueChanged += gcnew System::EventHandler(this, &MainForm::pitchUpDown_ValueChanged);
			// 
			// musicTabPanel
			// 
			this->musicTabPanel->Controls->Add(this->allMusicPage);
			this->musicTabPanel->Controls->Add(this->playlistsPage);
			this->musicTabPanel->Controls->Add(this->selectedPlaylistPage);
			this->musicTabPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicTabPanel->Location = System::Drawing::Point(78, 3);
			this->musicTabPanel->Name = L"musicTabPanel";
			this->musicTabPanel->SelectedIndex = 0;
			this->musicTabPanel->Size = System::Drawing::Size(319, 573);
			this->musicTabPanel->TabIndex = 7;
			// 
			// allMusicPage
			// 
			this->allMusicPage->AutoScroll = true;
			this->allMusicPage->Controls->Add(this->musicButtonTableLayoutPanel);
			this->allMusicPage->Controls->Add(this->allPageEmptyLabel);
			this->allMusicPage->Location = System::Drawing::Point(4, 22);
			this->allMusicPage->Name = L"allMusicPage";
			this->allMusicPage->Padding = System::Windows::Forms::Padding(3);
			this->allMusicPage->Size = System::Drawing::Size(311, 547);
			this->allMusicPage->TabIndex = 0;
			this->allMusicPage->Text = L"Все песни";
			this->allMusicPage->UseVisualStyleBackColor = true;
			// 
			// musicButtonTableLayoutPanel
			// 
			this->musicButtonTableLayoutPanel->ColumnCount = 2;
			this->musicButtonTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->musicButtonTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				40)));
			this->musicButtonTableLayoutPanel->Controls->Add(this->deleteMusicButton, 1, 0);
			this->musicButtonTableLayoutPanel->Controls->Add(this->musicButtonTemplate, 0, 0);
			this->musicButtonTableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->musicButtonTableLayoutPanel->Location = System::Drawing::Point(3, 75);
			this->musicButtonTableLayoutPanel->Name = L"musicButtonTableLayoutPanel";
			this->musicButtonTableLayoutPanel->RowCount = 1;
			this->musicButtonTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->musicButtonTableLayoutPanel->Size = System::Drawing::Size(305, 39);
			this->musicButtonTableLayoutPanel->TabIndex = 2;
			this->musicButtonTableLayoutPanel->Visible = false;
			// 
			// deleteMusicButton
			// 
			this->deleteMusicButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deleteMusicButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->deleteMusicButton->ImageKey = L"trash.png";
			this->deleteMusicButton->ImageList = this->iconsImageList;
			this->deleteMusicButton->Location = System::Drawing::Point(265, 3);
			this->deleteMusicButton->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
			this->deleteMusicButton->Name = L"deleteMusicButton";
			this->deleteMusicButton->Size = System::Drawing::Size(37, 34);
			this->deleteMusicButton->TabIndex = 1;
			this->deleteMusicButton->UseVisualStyleBackColor = true;
			// 
			// musicButtonTemplate
			// 
			this->musicButtonTemplate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->musicButtonTemplate->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicButtonTemplate->Location = System::Drawing::Point(3, 3);
			this->musicButtonTemplate->Margin = System::Windows::Forms::Padding(3, 3, 0, 3);
			this->musicButtonTemplate->Name = L"musicButtonTemplate";
			this->musicButtonTemplate->Size = System::Drawing::Size(262, 34);
			this->musicButtonTemplate->TabIndex = 0;
			this->musicButtonTemplate->Text = L"Template";
			this->musicButtonTemplate->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->musicButtonTemplate->UseVisualStyleBackColor = true;
			// 
			// allPageEmptyLabel
			// 
			this->allPageEmptyLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->allPageEmptyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->allPageEmptyLabel->Location = System::Drawing::Point(3, 3);
			this->allPageEmptyLabel->Name = L"allPageEmptyLabel";
			this->allPageEmptyLabel->Size = System::Drawing::Size(305, 72);
			this->allPageEmptyLabel->TabIndex = 1;
			this->allPageEmptyLabel->Text = L" Добавьте музыку\r\n\r\n(Музыка -> Добавить)";
			this->allPageEmptyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// playlistsPage
			// 
			this->playlistsPage->Controls->Add(this->label1);
			this->playlistsPage->Controls->Add(this->playlistGroup);
			this->playlistsPage->Controls->Add(this->playlistsPageEmptyLabel);
			this->playlistsPage->Location = System::Drawing::Point(4, 22);
			this->playlistsPage->Name = L"playlistsPage";
			this->playlistsPage->Padding = System::Windows::Forms::Padding(3);
			this->playlistsPage->Size = System::Drawing::Size(269, 547);
			this->playlistsPage->TabIndex = 1;
			this->playlistsPage->Text = L"Плейлисты";
			this->playlistsPage->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// playlistGroup
			// 
			this->playlistGroup->ColumnCount = 3;
			this->playlistGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->playlistGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->playlistGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->playlistGroup->Controls->Add(this->deletePlaylistButton, 2, 0);
			this->playlistGroup->Controls->Add(this->playlistButton, 0, 0);
			this->playlistGroup->Controls->Add(this->editPlaylistButton, 1, 0);
			this->playlistGroup->Dock = System::Windows::Forms::DockStyle::Top;
			this->playlistGroup->Location = System::Drawing::Point(3, 75);
			this->playlistGroup->Name = L"playlistGroup";
			this->playlistGroup->RowCount = 1;
			this->playlistGroup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->playlistGroup->Size = System::Drawing::Size(263, 39);
			this->playlistGroup->TabIndex = 3;
			this->playlistGroup->Visible = false;
			// 
			// deletePlaylistButton
			// 
			this->deletePlaylistButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deletePlaylistButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->deletePlaylistButton->ImageKey = L"trash.png";
			this->deletePlaylistButton->ImageList = this->iconsImageList;
			this->deletePlaylistButton->Location = System::Drawing::Point(223, 3);
			this->deletePlaylistButton->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
			this->deletePlaylistButton->Name = L"deletePlaylistButton";
			this->deletePlaylistButton->Size = System::Drawing::Size(37, 33);
			this->deletePlaylistButton->TabIndex = 2;
			this->deletePlaylistButton->UseVisualStyleBackColor = true;
			// 
			// playlistButton
			// 
			this->playlistButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playlistButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->playlistButton->Location = System::Drawing::Point(3, 3);
			this->playlistButton->Margin = System::Windows::Forms::Padding(3, 3, 0, 3);
			this->playlistButton->Name = L"playlistButton";
			this->playlistButton->Size = System::Drawing::Size(181, 33);
			this->playlistButton->TabIndex = 0;
			this->playlistButton->Text = L"Template";
			this->playlistButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->playlistButton->UseVisualStyleBackColor = true;
			// 
			// editPlaylistButton
			// 
			this->editPlaylistButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->editPlaylistButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->editPlaylistButton->ImageKey = L"edit.png";
			this->editPlaylistButton->ImageList = this->iconsImageList;
			this->editPlaylistButton->Location = System::Drawing::Point(184, 3);
			this->editPlaylistButton->Margin = System::Windows::Forms::Padding(0, 3, 0, 3);
			this->editPlaylistButton->Name = L"editPlaylistButton";
			this->editPlaylistButton->Size = System::Drawing::Size(39, 33);
			this->editPlaylistButton->TabIndex = 1;
			this->editPlaylistButton->UseVisualStyleBackColor = true;
			// 
			// playlistsPageEmptyLabel
			// 
			this->playlistsPageEmptyLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->playlistsPageEmptyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->playlistsPageEmptyLabel->Location = System::Drawing::Point(3, 3);
			this->playlistsPageEmptyLabel->Name = L"playlistsPageEmptyLabel";
			this->playlistsPageEmptyLabel->Size = System::Drawing::Size(263, 72);
			this->playlistsPageEmptyLabel->TabIndex = 2;
			this->playlistsPageEmptyLabel->Text = L"Создайте плейлист\r\n\r\n(Плейлист -> Создать)";
			this->playlistsPageEmptyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// selectedPlaylistPage
			// 
			this->selectedPlaylistPage->Controls->Add(this->selectedPlaylistEmptyLabel);
			this->selectedPlaylistPage->Location = System::Drawing::Point(4, 22);
			this->selectedPlaylistPage->Name = L"selectedPlaylistPage";
			this->selectedPlaylistPage->Size = System::Drawing::Size(269, 547);
			this->selectedPlaylistPage->TabIndex = 2;
			this->selectedPlaylistPage->Text = L"Выберите плейлист";
			this->selectedPlaylistPage->UseVisualStyleBackColor = true;
			// 
			// selectedPlaylistEmptyLabel
			// 
			this->selectedPlaylistEmptyLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->selectedPlaylistEmptyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->selectedPlaylistEmptyLabel->Location = System::Drawing::Point(0, 0);
			this->selectedPlaylistEmptyLabel->Name = L"selectedPlaylistEmptyLabel";
			this->selectedPlaylistEmptyLabel->Size = System::Drawing::Size(269, 72);
			this->selectedPlaylistEmptyLabel->TabIndex = 3;
			this->selectedPlaylistEmptyLabel->Text = L"В этом плейлисте нет песен";
			this->selectedPlaylistEmptyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 1;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel6->Controls->Add(this->musicPictureBox, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->tableLayoutPanel7, 0, 1);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(403, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 2;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(427, 573);
			this->tableLayoutPanel6->TabIndex = 8;
			// 
			// musicPictureBox
			// 
			this->musicPictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicPictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"musicPictureBox.Image")));
			this->musicPictureBox->Location = System::Drawing::Point(3, 3);
			this->musicPictureBox->Name = L"musicPictureBox";
			this->musicPictureBox->Size = System::Drawing::Size(421, 452);
			this->musicPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->musicPictureBox->TabIndex = 0;
			this->musicPictureBox->TabStop = false;
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 3;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel7->Controls->Add(this->musicName, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->musicArtist, 1, 1);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 461);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 2;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 70)));
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 30)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(421, 109);
			this->tableLayoutPanel7->TabIndex = 1;
			// 
			// musicName
			// 
			this->musicName->AutoSize = true;
			this->musicName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->musicName->Location = System::Drawing::Point(45, 0);
			this->musicName->Name = L"musicName";
			this->musicName->Size = System::Drawing::Size(330, 76);
			this->musicName->TabIndex = 0;
			this->musicName->Text = L"Выберите музыку";
			this->musicName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// musicArtist
			// 
			this->musicArtist->AutoSize = true;
			this->musicArtist->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicArtist->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->musicArtist->Location = System::Drawing::Point(45, 76);
			this->musicArtist->Name = L"musicArtist";
			this->musicArtist->Size = System::Drawing::Size(330, 33);
			this->musicArtist->TabIndex = 1;
			this->musicArtist->Text = L"-";
			this->musicArtist->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// musicTimer
			// 
			this->musicTimer->Interval = 1000;
			this->musicTimer->Tick += gcnew System::EventHandler(this, &MainForm::musicTimer_Tick);
			// 
			// addMusicFileDialog
			// 
			this->addMusicFileDialog->Filter = L"Music files (.mp3; .ogg)|*.mp3;*.ogg";
			this->addMusicFileDialog->Multiselect = true;
			this->addMusicFileDialog->Title = L"Выберите музыкальные файлы для добавления";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1063, 706);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"SoundPlayer";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->musicProgressBar))->EndInit();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->volumeUpDown))->EndInit();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pitchBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pitchUpDown))->EndInit();
			this->musicTabPanel->ResumeLayout(false);
			this->allMusicPage->ResumeLayout(false);
			this->musicButtonTableLayoutPanel->ResumeLayout(false);
			this->playlistsPage->ResumeLayout(false);
			this->playlistsPage->PerformLayout();
			this->playlistGroup->ResumeLayout(false);
			this->selectedPlaylistPage->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->musicPictureBox))->EndInit();
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void setMusicInfo();

	private: void setDefaultMusicInfo();

	private: void setMusicCover();

	private: int getTrackBarValue(System::Object^ sender);

	private: int getNumericUpDownValue(System::Object^ sender);

	private: void scanMusicAndAddButtons();

	private: void scanPlaylistsAndAddButtons();

	private: void scanPlaylistAndAddMusicButtons(PlaylistInfo^ playlistInfo);

	private: System::Windows::Forms::TableLayoutPanel^ createMusicButton(std::string text, std::string path, PlaylistNode* node);

	private: System::Windows::Forms::TableLayoutPanel^ createPlaylistButton(PlaylistInfo^ playlistInfo);

	private: System::Windows::Forms::Button^ createPlaylistMusicButton(PlaylistNode* node);

	private: System::Void addMusicButton(std::string text, std::string path, PlaylistNode* node);

	private: System::Void addPlaylistButton(PlaylistInfo^ playlistInfo);

	private: System::Void addPlaylistMusicButton(PlaylistNode* node);

	private: System::Void playButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pauseButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void musicTimer_Tick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void musicProgressBar_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void nextButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void prevButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void volumeBar_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void volumeUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pitchBar_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void pitchUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void musicButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void DeleteMusicButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void createPlaylistStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void deletePlaylistButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void playlistButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
