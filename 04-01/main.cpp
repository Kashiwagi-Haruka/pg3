#define _CRT_SECURE_NO_WARNINGS
#include <Novice.h>
#include "GameManager.h"



// ======================
// メイン関数
// ======================
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	const char kWindowTitle[] = "LE2A_04_カシワギハルカ";

	Novice::Initialize(kWindowTitle, 1280, 720);

	char keys[256] = {0};
	char preKeys[256] = {0};

	Game game;

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		game.Update(keys, preKeys);
		game.Draw();

		Novice::EndFrame();
	}

	Novice::Finalize();
	return 0;
}
