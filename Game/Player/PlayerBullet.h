#pragma once

#include"\KamataEngine\DirectXGame\math\Vector3.h"
#include<stdint.h>
/// <summary>
/// 自キャラの弾
/// </summary>
class PlayerBullet {
private:
	static const int32_t kLifeTime = 60 * 5;//寿命
	int32_t deathTimer_ = kLifeTime;//デスタイマー
	bool isDeath_ = false; // デスフラグ
	
	float speed_;
	float radius_;
	Vector3 pos_;

public:
	
	void Init(const Vector3& position, const float& speed);
	void Update();
	void Draw();

	float GetRadius()const { return radius_; }
	Vector3 GetPosition()const { return pos_; }
	bool GetIsDead() const { return isDeath_; }
};
