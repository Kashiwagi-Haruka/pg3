#include "StageState.h"
#include <Novice.h>

#include "StageState.h"
#include <Novice.h>

Bullet::Bullet(Vector2 pos, Vector2 vel, int color) {
	pos_ = pos;
	vel_ = vel;
	color_ = color;
}

void Bullet::Update() {
	pos_.x += vel_.x;
	pos_.y += vel_.y;
}

void Bullet::Draw() { Novice::DrawBox((int)pos_.x, (int)pos_.y, 8, 8, 0.0f, color_, kFillModeSolid); }

void StageState::Update(char* keys, char* preKeys) {
	player_.pos.y = 500;
	enemy_.pos.y = 200;

	// プレイヤー移動
	if (keys[DIK_A])
		player_.pos.x -= 5;
	if (keys[DIK_D])
		player_.pos.x += 5;

	// ★ プレイヤー発射
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		Bullet pb(player_.pos, {0, -5}, WHITE);
		playerbullet_.push_back(pb);
	}

	// ★ 敵発射（一定時間ごと）
	enemyShootTimer++;
	if (enemyShootTimer >= enemyShootInterval) {
		Bullet eb(enemy_.pos, {0, +5}, RED);
		enemybuleet_.push_back(eb);
		enemyShootTimer = 0;
	}

// ★ プレイヤー弾更新 & 当たり判定
	for (auto& pb : playerbullet_) {
		pb.Update();
		if (abs(pb.GetPos().x - enemy_.pos.x) < 32 && abs(pb.GetPos().y - enemy_.pos.y) < 32) {
			finished = true;
		}
	}

	// ★ 敵弾更新 & 当たり判定
	for (auto& eb : enemybuleet_) {
		eb.Update();
		if (abs(eb.GetPos().x - player_.pos.x) < 32 && abs(eb.GetPos().y - player_.pos.y) < 32) {
			finished = true;
		}
	}

	// ================================
	// ★ ここが新しい削除処理！
	// ================================

	// プレイヤー弾：上に消える
	playerbullet_.erase(std::remove_if(playerbullet_.begin(), playerbullet_.end(), [](const Bullet& b) { return b.GetPos().y <= 0; }), playerbullet_.end());

	// 敵弾：下に消える
	enemybuleet_.erase(std::remove_if(enemybuleet_.begin(), enemybuleet_.end(), [](const Bullet& b) { return b.GetPos().y >= 720; }), enemybuleet_.end());
}

void StageState::Draw() {
	Novice::ScreenPrintf(550, 300, "STAGE");
	Novice::DrawBox(int(player_.pos.x), 500, 32, 32, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawBox(int(enemy_.pos.x), 200, 32, 32, 0.0f, RED, kFillModeSolid);
	
for (auto& pb : playerbullet_) {
		pb.Draw();
	}
	for (auto& eb : enemybuleet_) {
		eb.Draw();
	}

	
	Novice::ScreenPrintf(500, 50, "Press A/D to move player, SPACE to CLEAR");
}