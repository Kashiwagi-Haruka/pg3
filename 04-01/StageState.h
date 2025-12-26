#pragma once
#include "IStates.h"
#include "KamataEngine.h"
#include "math/Vector2.h"
#include <vector>
// ======================
// ゲーム(ステージ)シーン
// ======================
using namespace KamataEngine;

class Bullet {
public:
	Bullet(Vector2 pos, Vector2 vel, int color);
	void Update();
	void Draw();
	Vector2 GetPos() const { return pos_; } // ★ const修飾子を追加

private:
	Vector2 pos_;
	Vector2 vel_;
	int color_;
};

class StageState : public IState {
private:
	bool finished = false;

	struct Object {
		Vector2 pos;
		bool isShot;
		int color;
	};

	Object player_;
	Object enemy_;
	std::vector<Bullet> playerbullet_;
	std::vector<Bullet> enemybuleet_;

	float enemyShootTimer = 0.0f;           // ★ 追加：敵の弾発射タイミング用
	const float enemyShootInterval = 60.0f; // ★ 約1秒ごと（60fps想定）

public:
	void Update(char* keys, char* preKeys);

	void Draw();

	bool IsFinished() override { return finished; }
};
