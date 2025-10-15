#include "CreatePlaylistForm.h"

#include <iostream>

using namespace SoundPlayer;

void CreatePlaylistForm::createAddMusicButton(PlaylistNode* node) {
	auto newMusicGroup = (gcnew System::Windows::Forms::TableLayoutPanel());
	auto newMusicNameLabel = (gcnew System::Windows::Forms::Label());
	auto newAddMusicButton = (gcnew System::Windows::Forms::Button());

	newMusicGroup->ColumnCount = 2;
	newMusicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
	newMusicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 40)));
	newMusicGroup->Controls->Add(newMusicNameLabel, 0, 0);
	newMusicGroup->Controls->Add(newAddMusicButton, 1, 0);
	newMusicGroup->Dock = System::Windows::Forms::DockStyle::Top;
	newMusicGroup->Location = System::Drawing::Point(3, 3);
	newMusicGroup->RowCount = 1;
	newMusicGroup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
	newMusicGroup->Size = System::Drawing::Size(246, 39);
	newMusicGroup->Name = L"musicGroup" + StringHelper::toSystemString(node->name);

	newMusicNameLabel->AutoSize = true;
	newMusicNameLabel->Dock = System::Windows::Forms::DockStyle::Fill;
	newMusicNameLabel->Location = System::Drawing::Point(3, 3);
	newMusicNameLabel->Margin = System::Windows::Forms::Padding(3);
	newMusicNameLabel->Size = System::Drawing::Size(200, 34);
	newMusicNameLabel->TabIndex = 2;
	newMusicNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	newMusicNameLabel->Name = L"musicNameLabel" + StringHelper::toSystemString(node->name);
	newMusicNameLabel->Text = StringHelper::toSystemString(node->name);
	
	newAddMusicButton->Cursor = System::Windows::Forms::Cursors::Hand;
	newAddMusicButton->Dock = System::Windows::Forms::DockStyle::Fill;
	newAddMusicButton->ImageKey = L"plus.png";
	newAddMusicButton->ImageList = this->imageList;
	newAddMusicButton->Location = System::Drawing::Point(206, 3);
	newAddMusicButton->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
	newAddMusicButton->Size = System::Drawing::Size(37, 34);
	newAddMusicButton->MaximumSize = System::Drawing::Size(37, 34);
	newAddMusicButton->UseVisualStyleBackColor = true;
	newAddMusicButton->Name = L"addMusicButton" + StringHelper::toSystemString(node->name);
	newAddMusicButton->Tag = IntPtr(node);
	newAddMusicButton->Click += gcnew System::EventHandler(this, &CreatePlaylistForm::AddMusicButton_Click);

	this->toolTip->SetToolTip(newMusicNameLabel, StringHelper::toSystemString(node->name));
	this->toolTip->SetToolTip(newAddMusicButton, StringHelper::toSystemString(node->name));

	this->allMusicPage->Controls->Add(newMusicGroup);
}

void CreatePlaylistForm::createSelectedMusicButton(PlaylistNode* node) {
	auto newMusicGroup = (gcnew System::Windows::Forms::TableLayoutPanel());
	auto newMusicNameLabel = (gcnew System::Windows::Forms::Label());
	auto newRemoveMusicButton = (gcnew System::Windows::Forms::Button());

	newMusicGroup->ColumnCount = 2;
	newMusicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
	newMusicGroup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 40)));
	newMusicGroup->Controls->Add(newMusicNameLabel, 0, 0);
	newMusicGroup->Controls->Add(newRemoveMusicButton, 1, 0);
	newMusicGroup->Dock = System::Windows::Forms::DockStyle::Top;
	newMusicGroup->Location = System::Drawing::Point(3, 3);
	newMusicGroup->RowCount = 1;
	newMusicGroup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
	newMusicGroup->Size = System::Drawing::Size(246, 39);
	newMusicGroup->Name = L"musicGroup" + StringHelper::toSystemString(node->name);

	newMusicNameLabel->AutoSize = true;
	newMusicNameLabel->Dock = System::Windows::Forms::DockStyle::Fill;
	newMusicNameLabel->Location = System::Drawing::Point(3, 3);
	newMusicNameLabel->Margin = System::Windows::Forms::Padding(3);
	newMusicNameLabel->Size = System::Drawing::Size(200, 34);
	newMusicNameLabel->TabIndex = 2;
	newMusicNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
	newMusicNameLabel->Name = L"musicNameLabel" + StringHelper::toSystemString(node->name);
	newMusicNameLabel->Text = StringHelper::toSystemString(node->name);

	newRemoveMusicButton->Cursor = System::Windows::Forms::Cursors::Hand;
	newRemoveMusicButton->Dock = System::Windows::Forms::DockStyle::Fill;
	newRemoveMusicButton->ImageKey = L"minus.png";
	newRemoveMusicButton->ImageList = this->imageList;
	newRemoveMusicButton->Location = System::Drawing::Point(206, 3);
	newRemoveMusicButton->Margin = System::Windows::Forms::Padding(0, 3, 3, 3);
	newRemoveMusicButton->Size = System::Drawing::Size(37, 34);
	newRemoveMusicButton->MaximumSize = System::Drawing::Size(37, 34);
	newRemoveMusicButton->UseVisualStyleBackColor = true;
	newRemoveMusicButton->Name = L"removeMusicButton" + StringHelper::toSystemString(node->name);
	newRemoveMusicButton->Tag = IntPtr(node);
	newRemoveMusicButton->Click += gcnew System::EventHandler(this, &CreatePlaylistForm::RemoveMusicButton_Click);

	this->toolTip->SetToolTip(newMusicNameLabel, StringHelper::toSystemString(node->name));
	this->toolTip->SetToolTip(newRemoveMusicButton, StringHelper::toSystemString(node->name));

	this->selectedMusicPage->Controls->Add(newMusicGroup);
}

void CreatePlaylistForm::fillAllMusicPage() {
	auto musicPathes = DirectoryHelper::getMusicPathesArray();

	if (musicPathes.size() == 0) {
		return;
	}

	this->allMusicPage->Controls->Clear();

	for (auto path : musicPathes) {
		if (this->isEditMode && this->editingPlaylistInfo->musicPathes->Contains(StringHelper::toSystemString(path.string()))) {
			continue;
		}

		auto node = new PlaylistNode(path.string(), path.filename().string(), nullptr);

		this->createAddMusicButton(node);
	}
}

void CreatePlaylistForm::fillSelectedMusicPage() {
	if (!isEditMode || this->editingPlaylistInfo->musicPathes->Count == 0) {
		return;
	}

	this->selectedMusicPage->Controls->Clear();

	for each (auto path in this->editingPlaylistInfo->musicPathes) {
		auto fsPath = fs::path(StringHelper::toStdString(path));
		auto node = new PlaylistNode(fsPath.string(), fsPath.filename().string(), nullptr);

		this->createSelectedMusicButton(node);

		this->addedMusicPathes->Add(path);
	}
}

bool CreatePlaylistForm::validateParams() {
	auto name = this->nameTextBox->Text;

	if (name->Length == 0) {
		MessageBox::Show(
			"Введите название плейлиста",
			"Ошибка",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);

		return false;
	}

	if (this->addedMusicPathes->Count == 0) {
		MessageBox::Show(
			"Выберите хотябы одну песню",
			"Ошибка",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);

		return false;
	}

	return true;
}

System::Void CreatePlaylistForm::CreatePlaylistForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->fillAllMusicPage();

	if (this->isEditMode) {
		this->fillSelectedMusicPage();
		this->nameTextBox->Text = this->editingPlaylistInfo->name;
	}
}

System::Void CreatePlaylistForm::AddMusicButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);

	IntPtr p = safe_cast<IntPtr>(button->Tag);
	PlaylistNode* node = static_cast<PlaylistNode*>(p.ToPointer());

	this->addedMusicPathes->Add(StringHelper::toSystemString(node->path));

	this->selectedMusicPage->Controls->Remove(this->selectedPageEmptyLabel);
	this->createSelectedMusicButton(node);

	this->allMusicPage->Controls->Remove(button->Parent);
}

System::Void CreatePlaylistForm::RemoveMusicButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ button = safe_cast<Button^>(sender);

	IntPtr p = safe_cast<IntPtr>(button->Tag);
	PlaylistNode* node = static_cast<PlaylistNode*>(p.ToPointer());

	this->addedMusicPathes->Remove(StringHelper::toSystemString(node->path));

	if (this->addedMusicPathes->Count == 0) {
		this->selectedMusicPage->Controls->Add(this->selectedPageEmptyLabel);
	}

	this->createAddMusicButton(node);

	this->selectedMusicPage->Controls->Remove(button->Parent);
}

System::Void CreatePlaylistForm::cancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
	auto res = MessageBox::Show(
		"Вы уверены, что хотите выйти без сохранения?",
		"Подтверждение",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question
	);

	if (res == System::Windows::Forms::DialogResult::Yes) {
		this->Close();
	}
}

System::Void CreatePlaylistForm::saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool res = this->validateParams();

	if (!res) {
		return;
	}

	auto name = this->nameTextBox->Text;
	auto playlistInfo = gcnew PlaylistInfo(name, this->addedMusicPathes);

	if (this->isEditMode) {
		DirectoryHelper::deleteFile(this->editingPlaylistInfo->path);
	}

	DirectoryHelper::savePlaylist(playlistInfo);

	MessageBox::Show(
		"Плейлист успешно создан",
		"Успех",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);

	this->Close();
}