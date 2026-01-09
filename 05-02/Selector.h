#pragma once
#include "Novice.h"

class Unit;

class Selector {
	int x_ = 0;
	int y_ = 0;
	int size_ = 32;

	Unit* selectedUnit_ = nullptr;

public:
	void Move(int dx, int dy);
	void Select(Unit* unit);

	Unit* GetSelectedUnit();

	void Draw();

	int GetX() const;
	int GetY() const;
};
