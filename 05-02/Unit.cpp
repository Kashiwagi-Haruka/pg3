#include "Unit.h"
void Unit::Init(int x, int y) {
	x_ = x;
	y_ = y;
}

void Unit::Move(int x, int y) {
	x_ = x;
	y_ = y;
}

void Unit::SetSelected(bool flag) { isSelected_ = flag; }

void Unit::Draw() {
	unsigned int color = isSelected_ ? GREEN : WHITE;
	Novice::DrawBox(x_, y_, size_, size_, 0.0f, color, kFillModeSolid);
}

bool Unit::HitTest(int x, int y) { return x_ == x && y_ == y; }

int Unit::GetX() const { return x_; }
int Unit::GetY() const { return y_; }