#pragma once

#include "DirectoryHelper.h"
#include "StringHelper.h"
#include "PlaylistNode.h"
#include "PlaylistInfo.h"

#using <Newtonsoft.Json.dll>

namespace SoundPlayer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace Newtonsoft::Json;

	/// <summary>
	/// Summary for CreatePlaylistForm
	/// </summary>
	public ref class CreatePlaylistForm : public System::Windows::Forms::Form
	{
	public:
		CreatePlaylistForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CreatePlaylistForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ inputGroup;
	private: System::Windows::Forms::Label^ nameInputLabel;
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Button^ cancelButton;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::TabControl^ allMusic;
	private: System::Windows::Forms::TabPage^ allMusicPage;
	private: System::Windows::Forms::TabControl^ selectedMusic;
	private: System::Windows::Forms::TabPage^ selectedMusicPage;
	private: System::Windows::Forms::TableLayoutPanel^ musicGroup;
	private: System::Windows::Forms::Button^ addMusicButton;




	private: System::Windows::Forms::ImageList^ imageList;
	private: System::Windows::Forms::Label^ musicNameLabel;
	private: System::Windows::Forms::ToolTip^ toolTip;
	private: System::Windows::Forms::TableLayoutPanel^ selectedMusicGroup;
	private: System::Windows::Forms::Button^ removeMusicButton;
	private: System::Windows::Forms::Label^ selectedMusicNameLabel;
	private: System::Windows::Forms::Label^ selectedPageEmptyLabel;
	private: System::Windows::Forms::Label^ allPageEmptyLabel;






	protected:

	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private: List<String^>^ addedMusicPathes = gcnew List<String^>();

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreatePlaylistForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->inputGroup = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->nameInputLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->selectedMusic = (gcnew System::Windows::Forms::TabControl());
			this->selectedMusicPage = (gcnew System::Windows::Forms::TabPage());
			this->selectedPageEmptyLabel = (gcnew System::Windows::Forms::Label());
			this->selectedMusicGroup = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->removeMusicButton = (gcnew System::Windows::Forms::Button());
			this->imageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->selectedMusicNameLabel = (gcnew System::Windows::Forms::Label());
			this->allMusic = (gcnew System::Windows::Forms::TabControl());
			this->allMusicPage = (gcnew System::Windows::Forms::TabPage());
			this->allPageEmptyLabel = (gcnew System::Windows::Forms::Label());
			this->musicGroup = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->addMusicButton = (gcnew System::Windows::Forms::Button());
			this->musicNameLabel = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->inputGroup->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->selectedMusic->SuspendLayout();
			this->selectedMusicPage->SuspendLayout();
			this->selectedMusicGroup->SuspendLayout();
			this->allMusic->SuspendLayout();
			this->allMusicPage->SuspendLayout();
			this->musicGroup->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.80604F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 72.33704F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.0159F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(671, 629);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel2->Controls->Add(this->inputGroup, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 105)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(665, 105);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// inputGroup
			// 
			this->inputGroup->ColumnCount = 1;
			this->inputGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->inputGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->inputGroup->Controls->Add(this->nameInputLabel, 0, 0);
			this->inputGroup->Controls->Add(this->nameTextBox, 0, 1);
			this->inputGroup->Dock = System::Windows::Forms::DockStyle::Fill;
			this->inputGroup->Location = System::Drawing::Point(102, 10);
			this->inputGroup->Margin = System::Windows::Forms::Padding(3, 10, 3, 10);
			this->inputGroup->Name = L"inputGroup";
			this->inputGroup->RowCount = 2;
			this->inputGroup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			this->inputGroup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40)));
			this->inputGroup->Size = System::Drawing::Size(459, 85);
			this->inputGroup->TabIndex = 0;
			// 
			// nameInputLabel
			// 
			this->nameInputLabel->AutoSize = true;
			this->nameInputLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->nameInputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nameInputLabel->Location = System::Drawing::Point(3, 0);
			this->nameInputLabel->Name = L"nameInputLabel";
			this->nameInputLabel->Size = System::Drawing::Size(453, 51);
			this->nameInputLabel->TabIndex = 0;
			this->nameInputLabel->Text = L"Название плейлиста";
			this->nameInputLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// nameTextBox
			// 
			this->nameTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nameTextBox->Location = System::Drawing::Point(3, 54);
			this->nameTextBox->MaxLength = 256;
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(453, 26);
			this->nameTextBox->TabIndex = 1;
			this->nameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel3->Controls->Add(this->selectedMusic, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->allMusic, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 114);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(665, 448);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// selectedMusic
			// 
			this->selectedMusic->Controls->Add(this->selectedMusicPage);
			this->selectedMusic->Dock = System::Windows::Forms::DockStyle::Fill;
			this->selectedMusic->Location = System::Drawing::Point(335, 3);
			this->selectedMusic->Name = L"selectedMusic";
			this->selectedMusic->SelectedIndex = 0;
			this->selectedMusic->Size = System::Drawing::Size(260, 442);
			this->selectedMusic->TabIndex = 1;
			// 
			// selectedMusicPage
			// 
			this->selectedMusicPage->AutoScroll = true;
			this->selectedMusicPage->Controls->Add(this->selectedPageEmptyLabel);
			this->selectedMusicPage->Controls->Add(this->selectedMusicGroup);
			this->selectedMusicPage->Location = System::Drawing::Point(4, 22);
			this->selectedMusicPage->Name = L"selectedMusicPage";
			this->selectedMusicPage->Padding = System::Windows::Forms::Padding(3);
			this->selectedMusicPage->Size = System::Drawing::Size(252, 416);
			this->selectedMusicPage->TabIndex = 0;
			this->selectedMusicPage->Text = L"Выбранные песни";
			this->selectedMusicPage->UseVisualStyleBackColor = true;
			// 
			// selectedPageEmptyLabel
			// 
			this->selectedPageEmptyLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->selectedPageEmptyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->selectedPageEmptyLabel->Location = System::Drawing::Point(3, 42);
			this->selectedPageEmptyLabel->Name = L"selectedPageEmptyLabel";
			this->selectedPageEmptyLabel->Size = System::Drawing::Size(246, 72);
			this->selectedPageEmptyLabel->TabIndex = 5;
			this->selectedPageEmptyLabel->Text = L"Вы не добавили в плейлист ни одной песни";
			this->selectedPageEmptyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// selectedMusicGroup
			// 
			this->selectedMusicGroup->ColumnCount = 2;
			this->selectedMusicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->selectedMusicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				40)));
			this->selectedMusicGroup->Controls->Add(this->removeMusicButton, 1, 0);
			this->selectedMusicGroup->Controls->Add(this->selectedMusicNameLabel, 0, 0);
			this->selectedMusicGroup->Dock = System::Windows::Forms::DockStyle::Top;
			this->selectedMusicGroup->Location = System::Drawing::Point(3, 3);
			this->selectedMusicGroup->Name = L"selectedMusicGroup";
			this->selectedMusicGroup->RowCount = 1;
			this->selectedMusicGroup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->selectedMusicGroup->Size = System::Drawing::Size(246, 39);
			this->selectedMusicGroup->TabIndex = 4;
			this->selectedMusicGroup->Visible = false;
			// 
			// removeMusicButton
			// 
			this->removeMusicButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->removeMusicButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->removeMusicButton->ImageKey = L"minus.png";
			this->removeMusicButton->ImageList = this->imageList;
			this->removeMusicButton->Location = System::Drawing::Point(206, 3);
			this->removeMusicButton->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
			this->removeMusicButton->MaximumSize = System::Drawing::Size(37, 34);
			this->removeMusicButton->Name = L"removeMusicButton";
			this->removeMusicButton->Size = System::Drawing::Size(37, 34);
			this->removeMusicButton->TabIndex = 1;
			this->removeMusicButton->UseVisualStyleBackColor = true;
			// 
			// imageList
			// 
			this->imageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList.ImageStream")));
			this->imageList->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList->Images->SetKeyName(0, L"plus.png");
			this->imageList->Images->SetKeyName(1, L"minus.png");
			// 
			// selectedMusicNameLabel
			// 
			this->selectedMusicNameLabel->AutoSize = true;
			this->selectedMusicNameLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->selectedMusicNameLabel->Location = System::Drawing::Point(3, 3);
			this->selectedMusicNameLabel->Margin = System::Windows::Forms::Padding(3);
			this->selectedMusicNameLabel->Name = L"selectedMusicNameLabel";
			this->selectedMusicNameLabel->Size = System::Drawing::Size(200, 34);
			this->selectedMusicNameLabel->TabIndex = 2;
			this->selectedMusicNameLabel->Text = L"Template";
			this->selectedMusicNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// allMusic
			// 
			this->allMusic->Controls->Add(this->allMusicPage);
			this->allMusic->Dock = System::Windows::Forms::DockStyle::Fill;
			this->allMusic->Location = System::Drawing::Point(69, 3);
			this->allMusic->Name = L"allMusic";
			this->allMusic->SelectedIndex = 0;
			this->allMusic->Size = System::Drawing::Size(260, 442);
			this->allMusic->TabIndex = 0;
			// 
			// allMusicPage
			// 
			this->allMusicPage->AutoScroll = true;
			this->allMusicPage->Controls->Add(this->allPageEmptyLabel);
			this->allMusicPage->Controls->Add(this->musicGroup);
			this->allMusicPage->Location = System::Drawing::Point(4, 22);
			this->allMusicPage->Name = L"allMusicPage";
			this->allMusicPage->Padding = System::Windows::Forms::Padding(3);
			this->allMusicPage->Size = System::Drawing::Size(252, 416);
			this->allMusicPage->TabIndex = 0;
			this->allMusicPage->Text = L"Все песни";
			this->allMusicPage->UseVisualStyleBackColor = true;
			// 
			// allPageEmptyLabel
			// 
			this->allPageEmptyLabel->Dock = System::Windows::Forms::DockStyle::Top;
			this->allPageEmptyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->allPageEmptyLabel->Location = System::Drawing::Point(3, 42);
			this->allPageEmptyLabel->Name = L"allPageEmptyLabel";
			this->allPageEmptyLabel->Size = System::Drawing::Size(246, 72);
			this->allPageEmptyLabel->TabIndex = 4;
			this->allPageEmptyLabel->Text = L"У вас нет ни одной песни";
			this->allPageEmptyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// musicGroup
			// 
			this->musicGroup->ColumnCount = 2;
			this->musicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->musicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->musicGroup->Controls->Add(this->addMusicButton, 1, 0);
			this->musicGroup->Controls->Add(this->musicNameLabel, 0, 0);
			this->musicGroup->Dock = System::Windows::Forms::DockStyle::Top;
			this->musicGroup->Location = System::Drawing::Point(3, 3);
			this->musicGroup->Name = L"musicGroup";
			this->musicGroup->RowCount = 1;
			this->musicGroup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->musicGroup->Size = System::Drawing::Size(246, 39);
			this->musicGroup->TabIndex = 3;
			this->musicGroup->Visible = false;
			// 
			// addMusicButton
			// 
			this->addMusicButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addMusicButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addMusicButton->ImageKey = L"plus.png";
			this->addMusicButton->ImageList = this->imageList;
			this->addMusicButton->Location = System::Drawing::Point(206, 3);
			this->addMusicButton->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
			this->addMusicButton->MaximumSize = System::Drawing::Size(37, 34);
			this->addMusicButton->Name = L"addMusicButton";
			this->addMusicButton->Size = System::Drawing::Size(37, 34);
			this->addMusicButton->TabIndex = 1;
			this->addMusicButton->UseVisualStyleBackColor = true;
			// 
			// musicNameLabel
			// 
			this->musicNameLabel->AutoSize = true;
			this->musicNameLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->musicNameLabel->Location = System::Drawing::Point(3, 3);
			this->musicNameLabel->Margin = System::Windows::Forms::Padding(3);
			this->musicNameLabel->Name = L"musicNameLabel";
			this->musicNameLabel->Size = System::Drawing::Size(200, 34);
			this->musicNameLabel->TabIndex = 2;
			this->musicNameLabel->Text = L"Template";
			this->musicNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 4;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel4->Controls->Add(this->cancelButton, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->saveButton, 2, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 568);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(665, 58);
			this->tableLayoutPanel4->TabIndex = 2;
			// 
			// cancelButton
			// 
			this->cancelButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cancelButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->cancelButton->Location = System::Drawing::Point(69, 3);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(260, 52);
			this->cancelButton->TabIndex = 1;
			this->cancelButton->Text = L"Отменить";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &CreatePlaylistForm::cancelButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->saveButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->saveButton->Location = System::Drawing::Point(335, 3);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(260, 52);
			this->saveButton->TabIndex = 0;
			this->saveButton->Text = L"Сохранить";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &CreatePlaylistForm::saveButton_Click);
			// 
			// CreatePlaylistForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 629);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CreatePlaylistForm";
			this->Text = L"SoundPlayer - Плейлист";
			this->Load += gcnew System::EventHandler(this, &CreatePlaylistForm::CreatePlaylistForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->inputGroup->ResumeLayout(false);
			this->inputGroup->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->selectedMusic->ResumeLayout(false);
			this->selectedMusicPage->ResumeLayout(false);
			this->selectedMusicGroup->ResumeLayout(false);
			this->selectedMusicGroup->PerformLayout();
			this->allMusic->ResumeLayout(false);
			this->allMusicPage->ResumeLayout(false);
			this->musicGroup->ResumeLayout(false);
			this->musicGroup->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void createAddMusicButton(PlaylistNode* node);

	private: void createSelectedMusicButton(PlaylistNode* node);

	private: void fillAllMusicPage();

	private: bool validateParams();

	private: System::Void CreatePlaylistForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void AddMusicButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void RemoveMusicButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
