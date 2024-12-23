#include "PlayerBullet.h"
#include<Novice.h>


void PlayerBullet::Init(const Vector3& position, const float& speed) {

	pos_ = position;
	speed_ = speed;
	radius_ = 10.0f;
}

void PlayerBullet::Update() {
	//座標を移動させる
	pos_.y += speed_;
	if (--deathTimer_ <= 0) {
		isDeath_ = true;
	}
}

void PlayerBullet::Draw() {
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0, RED, kFillModeSolid);
}