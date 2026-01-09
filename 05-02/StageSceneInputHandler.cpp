#include "StageSceneInputHandler.h"
ISStageSceneCommand* StageSceneInputHandler::HandleSelectorInput(Selector* selector, Unit* unit) {
	if (keys_[DIK_W] && !preKeys_[DIK_W])
		return new SelectorMoveCommand(selector, 0, -1);
	if (keys_[DIK_S] && !preKeys_[DIK_S])
		return new SelectorMoveCommand(selector, 0, 1);
	if (keys_[DIK_A] && !preKeys_[DIK_A])
		return new SelectorMoveCommand(selector, -1, 0);
	if (keys_[DIK_D] && !preKeys_[DIK_D])
		return new SelectorMoveCommand(selector, 1, 0);

	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		if (unit->HitTest(selector->GetX(), selector->GetY())) {
			return new SelectUnitCommand(selector, unit);
		}
	}
	return nullptr;
}

ISStageSceneCommand* StageSceneInputHandler::HandleUnitInput(Unit* unit, Selector* selector) {
	if (keys_[DIK_W] && !preKeys_[DIK_W])
		return new SelectorMoveCommand(selector, 0, -1);
	if (keys_[DIK_S] && !preKeys_[DIK_S])
		return new SelectorMoveCommand(selector, 0, 1);
	if (keys_[DIK_A] && !preKeys_[DIK_A])
		return new SelectorMoveCommand(selector, -1, 0);
	if (keys_[DIK_D] && !preKeys_[DIK_D])
		return new SelectorMoveCommand(selector, 1, 0);

	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		return new UnitMoveCommand(unit, selector);
	}
	return nullptr;
}