#pragma once
#include "Novice.h"

class Selector;

class Unit {
	int x_ = 0;
	int y_ = 0;
	int size_ = 32;
	bool isSelected_ = false;

public:
	void Init(int x, int y);

	void Move(int x, int y);
	
	
	void SetSelected(bool flag);

	void Draw();

	bool HitTest(int x, int y);

	int GetX() const;
	int GetY() const;
};
