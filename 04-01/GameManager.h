#pragma once
#include "TitleState.h"
#include "StageState.h"
#include "ClearStates.h"
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
