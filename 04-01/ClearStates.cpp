#include "ClearStates.h"
#include <Novice.h>
void ClearState::Update(char* keys, char* preKeys) {
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		finished = true;
	}
}

void ClearState::Draw() {
	Novice::ScreenPrintf(550, 300, "GameEnd");
	Novice::ScreenPrintf(520, 350, "Press SPACE to RETURN TITLE");
}
