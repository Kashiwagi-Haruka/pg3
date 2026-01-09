#include "Selector.h"
void Selector::Move(int dx, int dy) {
	x_ += dx * size_;
	y_ += dy * size_;
}

void Selector::Select(Unit* unit) { selectedUnit_ = unit; }

Unit* Selector::GetSelectedUnit() { return selectedUnit_; }

void Selector::Draw() { Novice::DrawBox(x_, y_, size_, size_, 0.0f, RED, kFillModeWireFrame); }

int Selector::GetX() const { return x_; }
int Selector::GetY() const { return y_; }