#pragma once 
#include"Vector3.h"
#include"Game/Enemy/behavior/BaseEnemyBehavior.h"
#include<memory>

class Enemy {
private:
	std::unique_ptr<BaseEnemyBehavior>behavior_;
	Vector3 pos_;
	float radius_;
	bool isDeaath_;

public:
	void Init();
	void Update();
	void Draw();

	float GetRadius()const { return radius_; }
	Vector3 GetPosition()const { return pos_; }
	void ChangeBehavior(std::unique_ptr<BaseEnemyBehavior>behavior);
	void OnHit();

	void SetRadius(float rad) { radius_ = rad; }
	void SetIsDeath(bool is) { isDeaath_ = is; }
};