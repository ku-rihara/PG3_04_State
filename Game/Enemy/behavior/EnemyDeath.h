#pragma once

#include"BaseEnemyBehavior.h"

class EnemyDeath : public BaseEnemyBehavior {
private:
	/// ===================================================
	///private varians
	/// ===================================================

public:
	//コンストラクタ
	EnemyDeath(Enemy* boss);
	~EnemyDeath();

	void Update()override;

};
