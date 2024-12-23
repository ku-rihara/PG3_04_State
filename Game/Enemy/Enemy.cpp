#include"Game/Enemy/Enemy.h"
#include"behavior/EnemyRoot.h"
#include"behavior/EnemyDeath.h"
#include<Novice.h>

void Enemy::Init() {

	radius_ = 30.0f;
	ChangeBehavior(std::make_unique<EnemyRoot>(this));
	pos_ = { 640.0f,100.0f };
}

void Enemy::Update() {
	behavior_->Update();
}

void Enemy::Draw() {
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0, RED, kFillModeSolid);
}


void Enemy::ChangeBehavior(std::unique_ptr<BaseEnemyBehavior>behavior) {
	//引数で受け取った状態を次の状態としてセット
	behavior_ = std::move(behavior);
}

void Enemy::OnHit() {
	if (dynamic_cast<EnemyDeath*>(behavior_.get()))return;

	ChangeBehavior(std::make_unique<EnemyDeath>(this));
}