#include "ScenePlay.h"
#include "SceneClear.h"
#include"SceneManager.h"
#include<Novice.h>
ScenePlay::ScenePlay() {

	
}

void ScenePlay::Init() {
	player_ = std::make_unique<Player>();
	enemy_ = std::make_unique<Enemy>();

	

	player_->Init();
	enemy_->Init();
}

void ScenePlay::Update() {
	
	// 各クラス更新
	player_->Update();
	enemy_->Update();

	 // 当たり判定
	IsCollisionEnemy(player_->GetBullets(), enemy_.get());

	ChangeClear();// シーン切り替え

}

void ScenePlay::Draw() {
	player_->Draw();
	enemy_->Draw();

	Novice::ScreenPrintf(0, 0, "Move::WASD");
	Novice::ScreenPrintf(0, 20, "Shot::Space");
}

void ScenePlay::ChangeClear() {
	if (!isClearScreenChange_)return;

	sceneCangeTime_++;
	if (sceneCangeTime_ >= 20) {
		SceneManager::GetInstance()->ChangeScene(std::make_unique<SceneClear>());
	}
}

void ScenePlay::IsCollisionEnemy(const std::list<std::unique_ptr<PlayerBullet>>& bullets, Enemy* enemy) {
	

	for (const auto& bullet : bullets) {
		if (!bullet) {
			continue; 
		}

		// 弾と敵の当たり判定をチェック
		if (CheckCollision(bullet->GetPosition(), bullet->GetRadius(), enemy->GetPosition(), enemy->GetRadius())) {
			enemy->OnHit(); 
			isClearScreenChange_ = true;
		}
	}
}



bool ScenePlay::CheckCollision(const Vector3& pos1, float radius1, const Vector3& pos2, float radius2) {
	float distanceSquared = (pos1.x - pos2.x) * (pos1.x - pos2.x) +
		(pos1.y - pos2.y) * (pos1.y - pos2.y) +
		(pos1.z - pos2.z) * (pos1.z - pos2.z);

	float radiusSum = radius1 + radius2;
	return distanceSquared <= (radiusSum * radiusSum);
}