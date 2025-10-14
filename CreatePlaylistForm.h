#pragma once

namespace SoundPlayer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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




	protected:

	private: System::ComponentModel::IContainer^ components;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->inputGroup = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->nameInputLabel = (gcnew System::Windows::Forms::Label());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->allMusicPage = (gcnew System::Windows::Forms::TabPage());
			this->allMusic = (gcnew System::Windows::Forms::TabControl());
			this->selectedMusic = (gcnew System::Windows::Forms::TabControl());
			this->selectedMusicPage = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->inputGroup->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->allMusic->SuspendLayout();
			this->selectedMusic->SuspendLayout();
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
			// 
			// allMusicPage
			// 
			this->allMusicPage->AutoScroll = true;
			this->allMusicPage->Location = System::Drawing::Point(4, 22);
			this->allMusicPage->Name = L"allMusicPage";
			this->allMusicPage->Padding = System::Windows::Forms::Padding(3);
			this->allMusicPage->Size = System::Drawing::Size(252, 416);
			this->allMusicPage->TabIndex = 0;
			this->allMusicPage->Text = L"Все песни";
			this->allMusicPage->UseVisualStyleBackColor = true;
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
			this->selectedMusicPage->Location = System::Drawing::Point(4, 22);
			this->selectedMusicPage->Name = L"selectedMusicPage";
			this->selectedMusicPage->Padding = System::Windows::Forms::Padding(3);
			this->selectedMusicPage->Size = System::Drawing::Size(252, 416);
			this->selectedMusicPage->TabIndex = 0;
			this->selectedMusicPage->Text = L"Выбранные песни";
			this->selectedMusicPage->UseVisualStyleBackColor = true;
			// 
			// CreatePlaylistForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 629);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"CreatePlaylistForm";
			this->Text = L"SoundPlayer - Плейлист";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->inputGroup->ResumeLayout(false);
			this->inputGroup->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->allMusic->ResumeLayout(false);
			this->selectedMusic->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
