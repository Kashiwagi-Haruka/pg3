#pragma once
#include "ISStageSceneCommand.h"
#include "Selector.h"
#include "Unit.h"
#include "SelectorCommand.h"
#include "UnitCommand.h"

class StageSceneInputHandler {
	char keys_[256]{};
	char preKeys_[256]{};

public:
	void UpdateKeyState() {
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);
	}
	bool IsKeyPressed(int dik) const { return keys_[dik]; }
	bool IsKeyTriggered(int dik) const { return keys_[dik] && !preKeys_[dik]; }
	ISStageSceneCommand* HandleSelectorInput(Selector* selector, Unit* unit);

	ISStageSceneCommand* HandleUnitInput(Unit* unit, Selector* selector);
};
