#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Sleep() 用

int main() {
	srand((unsigned int)time(NULL)); // 乱数初期化

	int userGuess = -1; // ユーザー入力（1:奇数＝丁, 0:偶数＝半）
	int roll;           // サイコロの出目（1〜6）

	// --- ラムダ: 結果表示 ---
	auto ShowResult = [](int roll, int userGuess) {
		printf("出目は %d でした。\n", roll);

		int isEven = (roll % 2 == 0) ? 1 : 0; // 偶数なら1
		int correct = (isEven == userGuess);

		if (correct) {
			printf("当たり！\n");
		} else {
			printf("はずれ...\n");
		}
	};

	// --- ラムダ: 遅延実行 ---
	auto DelayReveal = [&](auto fn, unsigned int delayMs, int roll, int userGuess) {
		printf("サイコロを振っています...\n");
		Sleep(delayMs); // ミリ秒単位で待機（3秒）
		fn(roll, userGuess);
	};

	// --- メイン処理 ---
	printf("=== 丁半ゲーム ===\n");
	printf("丁なら 1, 半なら 0 を入力してください: ");
	scanf_s("%d", &userGuess);

	roll = rand() % 6 + 1; // 出目（1〜6）

	// 3秒後に結果表示
	DelayReveal(ShowResult, 3000, roll, userGuess);

	return 0;
}
