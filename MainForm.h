#pragma once

#include "MusicWrapper.h"
#include "Playlist.h"
#include "TimeHelper.h"
#include "StringHelper.h"

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


	private: bool isProgrammaticTrackChange = false;

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
			this->musicButtonTemplate = (gcnew System::Windows::Forms::Button());
			this->playlistsPage = (gcnew System::Windows::Forms::TabPage());
			this->musicTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
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
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1033, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 6;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				54)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				56)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				283)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel5, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->musicTabPanel, 4, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 90.09174F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.908257F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1033, 682);
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
			this->tableLayoutPanel2->Location = System::Drawing::Point(121, 621);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(506, 58);
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
			this->prevButton->Size = System::Drawing::Size(120, 52);
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
			// 
			// nextButton
			// 
			this->nextButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->nextButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->nextButton->ImageKey = L"next.png";
			this->nextButton->ImageList = this->iconsImageList;
			this->nextButton->Location = System::Drawing::Point(381, 3);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(122, 52);
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
			this->pauseButton->Location = System::Drawing::Point(255, 3);
			this->pauseButton->Name = L"pauseButton";
			this->pauseButton->Size = System::Drawing::Size(120, 52);
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
			this->playButton->Location = System::Drawing::Point(129, 3);
			this->playButton->Name = L"playButton";
			this->playButton->Size = System::Drawing::Size(120, 52);
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
			this->tableLayoutPanel3->Location = System::Drawing::Point(121, 582);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(506, 33);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// musicProgressBar
			// 
			this->musicProgressBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicProgressBar->LargeChange = 10;
			this->musicProgressBar->Location = System::Drawing::Point(53, 3);
			this->musicProgressBar->Maximum = 180;
			this->musicProgressBar->Name = L"musicProgressBar";
			this->musicProgressBar->Size = System::Drawing::Size(398, 27);
			this->musicProgressBar->TabIndex = 1;
			this->musicProgressBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::musicProgressBar_ValueChanged);
			// 
			// currentTime
			// 
			this->currentTime->AutoSize = true;
			this->currentTime->Dock = System::Windows::Forms::DockStyle::Fill;
			this->currentTime->Location = System::Drawing::Point(3, 0);
			this->currentTime->Name = L"currentTime";
			this->currentTime->Size = System::Drawing::Size(44, 33);
			this->currentTime->TabIndex = 2;
			this->currentTime->Text = L"0:00";
			this->currentTime->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// maxTime
			// 
			this->maxTime->AutoSize = true;
			this->maxTime->Dock = System::Windows::Forms::DockStyle::Fill;
			this->maxTime->Location = System::Drawing::Point(457, 0);
			this->maxTime->Name = L"maxTime";
			this->maxTime->Size = System::Drawing::Size(46, 33);
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
			this->tableLayoutPanel4->Location = System::Drawing::Point(67, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(48, 573);
			this->tableLayoutPanel4->TabIndex = 3;
			// 
			// volumeLabel
			// 
			this->volumeLabel->AutoSize = true;
			this->volumeLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->volumeLabel->Location = System::Drawing::Point(3, 515);
			this->volumeLabel->Name = L"volumeLabel";
			this->volumeLabel->Size = System::Drawing::Size(42, 58);
			this->volumeLabel->TabIndex = 8;
			this->volumeLabel->Text = L"Volume";
			this->volumeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// volumeBar
			// 
			this->volumeBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->volumeBar->Location = System::Drawing::Point(3, 3);
			this->volumeBar->Maximum = 100;
			this->volumeBar->Name = L"volumeBar";
			this->volumeBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->volumeBar->Size = System::Drawing::Size(42, 452);
			this->volumeBar->TabIndex = 0;
			this->volumeBar->Value = 100;
			this->volumeBar->ValueChanged += gcnew System::EventHandler(this, &MainForm::volumeBar_ValueChanged);
			// 
			// volumeUpDown
			// 
			this->volumeUpDown->Dock = System::Windows::Forms::DockStyle::Fill;
			this->volumeUpDown->Location = System::Drawing::Point(3, 461);
			this->volumeUpDown->Name = L"volumeUpDown";
			this->volumeUpDown->Size = System::Drawing::Size(42, 20);
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
			this->tableLayoutPanel5->Location = System::Drawing::Point(633, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 3;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(50, 573);
			this->tableLayoutPanel5->TabIndex = 6;
			// 
			// pitchLabel
			// 
			this->pitchLabel->AutoSize = true;
			this->pitchLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pitchLabel->Location = System::Drawing::Point(3, 515);
			this->pitchLabel->Name = L"pitchLabel";
			this->pitchLabel->Size = System::Drawing::Size(44, 58);
			this->pitchLabel->TabIndex = 9;
			this->pitchLabel->Text = L"Pitch";
			this->pitchLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pitchBar
			// 
			this->pitchBar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pitchBar->Location = System::Drawing::Point(3, 3);
			this->pitchBar->Maximum = 300;
			this->pitchBar->Name = L"pitchBar";
			this->pitchBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->pitchBar->Size = System::Drawing::Size(44, 452);
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
			this->pitchUpDown->Size = System::Drawing::Size(44, 20);
			this->pitchUpDown->TabIndex = 6;
			this->pitchUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->pitchUpDown->ValueChanged += gcnew System::EventHandler(this, &MainForm::pitchUpDown_ValueChanged);
			// 
			// musicTabPanel
			// 
			this->musicTabPanel->Controls->Add(this->allMusicPage);
			this->musicTabPanel->Controls->Add(this->playlistsPage);
			this->musicTabPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicTabPanel->Location = System::Drawing::Point(689, 3);
			this->musicTabPanel->Name = L"musicTabPanel";
			this->musicTabPanel->SelectedIndex = 0;
			this->musicTabPanel->Size = System::Drawing::Size(277, 573);
			this->musicTabPanel->TabIndex = 7;
			// 
			// allMusicPage
			// 
			this->allMusicPage->AutoScroll = true;
			this->allMusicPage->Controls->Add(this->musicButtonTemplate);
			this->allMusicPage->Location = System::Drawing::Point(4, 22);
			this->allMusicPage->Name = L"allMusicPage";
			this->allMusicPage->Padding = System::Windows::Forms::Padding(3);
			this->allMusicPage->Size = System::Drawing::Size(269, 547);
			this->allMusicPage->TabIndex = 0;
			this->allMusicPage->Text = L"��� �����";
			this->allMusicPage->UseVisualStyleBackColor = true;
			// 
			// musicButtonTemplate
			// 
			this->musicButtonTemplate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->musicButtonTemplate->Dock = System::Windows::Forms::DockStyle::Top;
			this->musicButtonTemplate->Location = System::Drawing::Point(3, 3);
			this->musicButtonTemplate->Name = L"musicButtonTemplate";
			this->musicButtonTemplate->Size = System::Drawing::Size(263, 23);
			this->musicButtonTemplate->TabIndex = 0;
			this->musicButtonTemplate->Text = L"Template";
			this->musicButtonTemplate->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->musicButtonTemplate->UseVisualStyleBackColor = true;
			this->musicButtonTemplate->Visible = false;
			// 
			// playlistsPage
			// 
			this->playlistsPage->Location = System::Drawing::Point(4, 22);
			this->playlistsPage->Name = L"playlistsPage";
			this->playlistsPage->Padding = System::Windows::Forms::Padding(3);
			this->playlistsPage->Size = System::Drawing::Size(269, 547);
			this->playlistsPage->TabIndex = 1;
			this->playlistsPage->Text = L"���������";
			this->playlistsPage->UseVisualStyleBackColor = true;
			// 
			// musicTimer
			// 
			this->musicTimer->Interval = 1000;
			this->musicTimer->Tick += gcnew System::EventHandler(this, &MainForm::musicTimer_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1033, 706);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"SoundPlayer";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void setMusicInfo();

	private: int getTrackBarValue(System::Object^ sender);

	private: int getNumericUpDownValue(System::Object^ sender);

	private: System::Windows::Forms::Button^ MainForm::createMusicButton(std::string text, std::string path, PlaylistNode* node);

	private: System::Void MainForm::addMusicButton(std::string text, std::string path, PlaylistNode* node);

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
	};
}
