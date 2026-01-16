#pragma once
#include "ClearStates.h"
#include "StageState.h"
#include "TitleState.h"
// ======================
// ゲーム管理クラス
// ======================
class Game {
private:
	IState* state;

public:
	Game();

	~Game();

	void ChangeState(IState* newState);

	void Update(char* keys, char* preKeys);

	void Draw();
};
