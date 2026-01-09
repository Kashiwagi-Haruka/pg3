#pragma once
#include "ISStageSceneCommand.h"
#include "Selector.h"
#include "StageSceneInputHandler.h"
#include "Unit.h"
#include <list>
#include <vector>
class StageScene {
private:
	// 入力
	StageSceneInputHandler* inputHandler_ = nullptr;

	// 現在のコマンド
	ISStageSceneCommand* command_ = nullptr;

	// Undo用履歴
	std::list<ISStageSceneCommand*> commandHistory_;
	std::list<ISStageSceneCommand*>::iterator historyItr_;

	// 操作対象
	Selector* selector_ = nullptr;
	std::vector<Unit*> units_;

private:
	void ExecuteCommand();
	void UndoCommand();

public:
	StageScene();
	~StageScene();

	void Init();
	void Update();
	void Draw();
};
