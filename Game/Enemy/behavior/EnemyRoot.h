#pragma once

#include"BaseEnemyBehavior.h"

class EnemyRoot : public BaseEnemyBehavior {
private:
	/// ===================================================
	///private varians
	/// ===================================================

public:
	//コンストラクタ
	EnemyRoot(Enemy* boss);
	~EnemyRoot();

	void Update()override;

};
