#pragma once
#include "IStates.h"
// ======================
// クリアシーン
// ======================
class ClearState : public IState {
private:
	bool finished = false;

public:
	void Update(char* keys, char* preKeys);

	void Draw();
	bool IsFinished() override { return finished; }
};
