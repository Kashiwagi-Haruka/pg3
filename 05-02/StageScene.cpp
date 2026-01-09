#include "StageScene.h"
#include "Novice.h"

StageScene::StageScene() {}

StageScene::~StageScene() {
	for (auto* cmd : commandHistory_) {
		delete cmd;
	}
	delete inputHandler_;
	delete selector_;
	for (auto* unit : units_) {
		delete unit;
	}
}

void StageScene::Init() {
	inputHandler_ = new StageSceneInputHandler();

	selector_ = new Selector();
	const int positions[][2] = {
	    {32 * 10, 32 * 6},
        {192,     192   },
        {960,     480   },
        {992,     512   },
        {1184,    640   },
	};
	for (const auto& pos : positions) {
		Unit* unit = new Unit();
		unit->Init(pos[0], pos[1]);
		units_.push_back(unit);
	}

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

	// Undo（Ctrl + Z）: セレクト中のみ
	const bool ctrlPressed = inputHandler_->IsKeyPressed(DIK_LCONTROL) || inputHandler_->IsKeyPressed(DIK_RCONTROL);
	if (selector_->GetSelectedUnit() != nullptr && ctrlPressed && inputHandler_->IsKeyTriggered(DIK_Z)) {
		UndoCommand();
		return;
	}

	// コマンド生成
	command_ = nullptr;

	if (selector_->GetSelectedUnit() == nullptr) {
		Unit* hitUnit = nullptr;
		for (auto* unit : units_) {
			if (unit->HitTest(selector_->GetX(), selector_->GetY())) {
				hitUnit = unit;
				break;
			}
		}
		command_ = inputHandler_->HandleSelectorInput(selector_, hitUnit);
	} else {
		command_ = inputHandler_->HandleUnitInput(selector_->GetSelectedUnit(), selector_, units_);
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
	for (auto* unit : units_) {
		unit->Draw();
	}
	if (selector_->GetSelectedUnit() == nullptr) {
		selector_->Draw();
		Novice::ScreenPrintf(32, 32 * 20 + 10, "WASD||arrow keys: move / space key: change unit mode");
		Novice::ScreenPrintf(32, 32 * 21 + 10, "In Selector Mode, you cannot use the 'Undo' action");
	} else {
		int undoRemaining = 0;
		Unit* selectedUnit = selector_->GetSelectedUnit();
		for (auto itr = commandHistory_.begin(); itr != historyItr_; ++itr) {
			auto* selectorMove = dynamic_cast<SelectorMoveCommand*>(*itr);
			if (selectorMove && selectorMove->GetSelectedUnit() == selectedUnit) {
				++undoRemaining;
				continue;
			}
			auto* unitMove = dynamic_cast<UnitMoveCommand*>(*itr);
			if (unitMove && unitMove->GetUnit() == selectedUnit) {
				++undoRemaining;
			}
		}
		Novice::ScreenPrintf(32, 32 * 20 + 10, "WASD||arrow keys: move / space key: change selector mode / ctrl+z: undo");
		Novice::ScreenPrintf(32, 32 * 21 + 10, "You have %d more 'Undo' actions available.", undoRemaining);
	}
	Novice::DrawBox(0, 32 * 20, 1280, 32 * 4, 0.0f, 0x000000ff, FillMode::kFillModeSolid);
}
