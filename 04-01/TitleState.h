#pragma once
#include "IStates.h"
// ======================
// タイトルシーン
// ======================
class TitleState : public IState {
private:
	bool finished = false;

public:
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

	bool IsFinished() override { return finished; }
};
