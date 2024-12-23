/// behavior
#include"Game/Enemy/behavior/EnemyDeath.h"
#include"Game/Enemy/Enemy.h"

//初期化
EnemyDeath::EnemyDeath(Enemy* enemy)
	: BaseEnemyBehavior("EnemyDeath",enemy) {

	/// ===================================================
	///変数初期化
	/// ===================================================

}

EnemyDeath ::~EnemyDeath() {

}

//更新
void EnemyDeath::Update() {
	
	/// 死亡処理
	pEnemy_->SetIsDeath(true);
	pEnemy_->SetRadius(0.0f);
}

