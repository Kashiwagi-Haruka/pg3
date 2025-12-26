#include "TitleState.h"
#include <Novice.h>
void TitleState::Update(char* keys, char* preKeys){
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		finished = true;
	}
}

void TitleState::Draw(){
	Novice::ScreenPrintf(550, 300, "TITLE");
	Novice::ScreenPrintf(550, 350, "Press SPACE to START");
}