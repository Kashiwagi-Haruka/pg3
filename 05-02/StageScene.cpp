#include "StageScene.h"
#include "Novice.h"

StageScene::StageScene() {}

StageScene::~StageScene() {
	for (auto* cmd : commandHistory_) {
		delete cmd;
	}
	delete inputHandler_;
	delete selector_;
	delete unit_;
}

void StageScene::Init() {
	inputHandler_ = new StageSceneInputHandler();

	selector_ = new Selector();
	unit_ = new Unit();
	unit_->Init(128, 128);

	historyItr_ = commandHistory_.end();
}

void StageScene::ExecuteCommand() {
	if (!command_)
		return;

	command_->Exec();

	// Undo途中で新しいコマンドが来たら未来を削除
	if (historyItr_ != commandHistory_.end()) {
		auto itr = historyItr_;
		while (itr != commandHistory_.end()) {
			delete *itr;
			itr = commandHistory_.erase(itr);
		}
	}

	commandHistory_.push_back(command_);
	historyItr_ = commandHistory_.end();
}

void StageScene::UndoCommand() {
	if (commandHistory_.empty())
		return;
	if (historyItr_ == commandHistory_.begin())
		return;

	--historyItr_;
	(*historyItr_)->Undo();
}

void StageScene::Update() {
	inputHandler_->UpdateKeyState();

	// Undo（Zキー）
	if (Novice::CheckHitKey(DIK_Z)) {
		UndoCommand();
		return;
	}

	// コマンド生成
	command_ = nullptr;

	if (selector_->GetSelectedUnit() == nullptr) {
		command_ = inputHandler_->HandleSelectorInput(selector_, unit_);
	} else {
		command_ = inputHandler_->HandleUnitInput(unit_, selector_);
	}

	ExecuteCommand();
}

void StageScene::Draw() {
	for (float i = 0; i < 1280.0f / 32.0f; i++) {
		Novice::DrawLine(static_cast<int>(i + 1) * 32, 0, static_cast<int>(i + 1) * 32, 720, WHITE);
	}
	for (float i = 0; i < 720.0f / 32.0f; i++) {
		Novice::DrawLine(0, static_cast<int>(i + 1) * 32, 1280, static_cast<int>(i + 1) * 32, WHITE);
	}
	unit_->Draw();
	selector_->Draw();

	Novice::DrawBox(0, 32 * 20, 1280, 32 * 4, 0.0f, 0x000000ff, FillMode::kFillModeSolid);
	Novice::ScreenPrintf(32, 32 * 20+10, "WASD||arrow keys: move / space key: change unit mode");
	Novice::ScreenPrintf(32, 32 * 21+10, "In Selector Mode, you cannot use the 'Undo' action");
}
