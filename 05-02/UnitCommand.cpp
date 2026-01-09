#include "UnitCommand.h"
UnitMoveCommand::UnitMoveCommand(Unit* unit, Selector* selector) : unit_(unit), selector_(selector) {}

void UnitMoveCommand::Exec() {
	prevX_ = unit_->GetX();
	prevY_ = unit_->GetY();
	unit_->Move(selector_->GetX(), selector_->GetY());
	unit_->SetSelected(false);
	selector_->Select(nullptr);
}

void UnitMoveCommand::Undo(){ unit_->Move(prevX_, prevY_); }

