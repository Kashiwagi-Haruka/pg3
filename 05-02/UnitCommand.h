#pragma once
#include "ISStageSceneCommand.h"
#include "Unit.h"
#include "Selector.h"

class UnitMoveCommand : public ISStageSceneCommand {
	Unit* unit_;
	Selector* selector_;
	int prevX_;
	int prevY_;

public:
	UnitMoveCommand(Unit* unit, Selector* selector);

	void Exec() override;

	void Undo() override;
};
