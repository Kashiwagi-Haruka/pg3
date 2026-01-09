#pragma once
#include "ISStageSceneCommand.h"
#include "Selector.h"
#include "Unit.h"

class SelectorMoveCommand : public ISStageSceneCommand {
	Selector* selector_;
	int dx_;
	int dy_;

public:
	SelectorMoveCommand(Selector* selector, int dx, int dy);

	void Exec() override;

	void Undo() override;
};


class SelectUnitCommand : public ISStageSceneCommand {
	Selector* selector_;
	Unit* unit_;
	bool prevSelected_;

public:
	SelectUnitCommand(Selector* selector, Unit* unit);

	void Exec() override;

	void Undo() override;
	
	
	
};
