#include <cstdio>

class Enemy {
public:
	Enemy() {
		// 最初の状態を接近に
		currentState = &Enemy::StateApproach;
	}

	// 更新処理ごとに呼ばれる想定
	void Update() {
		// メンバ関数ポインタ呼び出し
		(this->*currentState)();
	}

private:
	// 状態関数たち
	void StateApproach() {
		printf("敵は接近している…\n");
		currentState = &Enemy::StateShoot;
	}

	void StateShoot() {
		printf("敵は射撃している！\n");
		currentState = &Enemy::StateRetreat;
	}

	void StateRetreat() {
		printf("敵は離脱していく…\n");
		currentState = &Enemy::StateApproach;
	}

	// メンバ関数ポインタ型
	typedef void (Enemy::*StateFunc)();

	// 現在の状態
	StateFunc currentState;
};

int main() {
	Enemy enemy;

	// 何回か状態遷移させる
	for (int i = 0; i < 6; i++) {
		enemy.Update();
	}

	return 0;
}
