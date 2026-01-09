#include "SelectorCommand.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int dx, int dy) : selector_(selector), dx_(dx), dy_(dy) {}

void SelectorMoveCommand::Exec() {
	selectedUnit_ = selector_->GetSelectedUnit();
	selector_->Move(dx_, dy_);
}

void SelectorMoveCommand::Undo() { selector_->Move(-dx_, -dy_); }

SelectUnitCommand::SelectUnitCommand(Selector* selector, Unit* unit) : selector_(selector), unit_(unit) {}

void SelectUnitCommand::Exec() {
	prevSelected_ = (selector_->GetSelectedUnit() != nullptr);
	unit_->SetSelected(true);
	selector_->Select(unit_);
}

void SelectUnitCommand::Undo() {
	unit_->SetSelected(false);
	selector_->Select(nullptr);
}