#include "Player.h"
#include"Game/Input/InputManager.h"


Player::Player() {

}

Player::~Player() {
	
}

void Player::Init() {
	
	pos_.x = 640.0f;
	pos_.y = 320.0f;
}

void Player::Update() {

	Move();
	Attack();

	// デスフラグの立った弾を削除
	bullets_.remove_if([](const std::unique_ptr<PlayerBullet>& bullet) {
		return bullet->GetIsDead();
		});



	// 弾の更新
	for (auto& bullet : bullets_) {
		bullet->Update();
	}
}

void Player::Draw() {
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), 20, 20, 0, WHITE, kFillModeSolid);
	// 弾描画
	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
}


void Player::Move() {
	Vector3 move = {0, 0, 0};
	// キャラクターの移動の速さ
	const float kCharacterSpeed = 3.0f;
	// 押した方向で移動ベクトルを変更(左右)
	if (InputManager::GetInstance()->GetIsPressKey(DIK_A)) {
		move.x -= kCharacterSpeed;
	} else if (InputManager::GetInstance()->GetIsPressKey(DIK_D)) {
		move.x += kCharacterSpeed;
	}
	// 押した方向で移動ベクトルを変更(上下)
	if (InputManager::GetInstance()->GetIsPressKey(DIK_W)) {
		move.y -= kCharacterSpeed;
	} else if (InputManager::GetInstance()->GetIsPressKey(DIK_S)) {
		move.y += kCharacterSpeed;
	}
	pos_.x+= move.x;
	pos_.y += move.y;

	// 移動限界座標
	const float kMoveLimitX = 1280;
	const float kMoveLimitY = 720;
	// 範囲を超えない処理
	pos_.x = max(pos_.x, -kMoveLimitX);
	pos_.x = min(pos_.x, kMoveLimitX);
	pos_.y = max(pos_.y, -kMoveLimitY);
	pos_.y = min(pos_.y, kMoveLimitY);
}

void Player::Attack() {

	if (!InputManager::GetInstance()->GetIsTriggerKey(DIK_SPACE)) return;
		//弾の速度
		const float kBulletSpeed = -10.0f;
	
		std::unique_ptr<PlayerBullet> newBullet = std::make_unique<PlayerBullet>();
		
		newBullet->Init(pos_,kBulletSpeed);

		//弾を登録する
		bullets_.push_back(std::move(newBullet));
	
}


