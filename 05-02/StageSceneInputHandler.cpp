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
		if (unit && unit->HitTest(selector->GetX(), selector->GetY())) {
			return new SelectUnitCommand(selector, unit);
		}
	}
	return nullptr;
}

ISStageSceneCommand* StageSceneInputHandler::HandleUnitInput(Unit* unit, Selector* selector, const std::vector<Unit*>& units) {
	if (!unit)
		return nullptr;
	const int step = 32;
	const auto isBlocked = [&](int dx, int dy) {
		const int nextX = selector->GetX() + dx * step;
		const int nextY = selector->GetY() + dy * step;
		for (auto* other : units) {
			if (other != unit && other->HitTest(nextX, nextY)) {
				return true;
			}
		}
		return false;
	};
	if (keys_[DIK_W] && !preKeys_[DIK_W]) {
		if (isBlocked(0, -1))
			return nullptr;
		return new SelectorMoveCommand(selector, 0, -1);
	}
	if (keys_[DIK_S] && !preKeys_[DIK_S]) {
		if (isBlocked(0, 1))
			return nullptr;
		return new SelectorMoveCommand(selector, 0, 1);
	}
	if (keys_[DIK_A] && !preKeys_[DIK_A]) {
		if (isBlocked(-1, 0))
			return nullptr;
		return new SelectorMoveCommand(selector, -1, 0);
	}
	if (keys_[DIK_D] && !preKeys_[DIK_D]) {
		if (isBlocked(1, 0))
			return nullptr;
		return new SelectorMoveCommand(selector, 1, 0);
	}

	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		return new UnitMoveCommand(unit, selector);
	}
	return nullptr;
}