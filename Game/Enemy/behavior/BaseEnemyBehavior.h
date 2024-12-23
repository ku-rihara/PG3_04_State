#pragma once

#include<string>

class Enemy;
class BaseEnemyBehavior {
protected:
	//振る舞い名
	std::string name_;
	//敵
	Enemy* pEnemy_ = nullptr;
public:

	BaseEnemyBehavior(const std::string& name, Enemy* enemy) :name_(name), pEnemy_(enemy) {}
	
	virtual ~BaseEnemyBehavior() {}

	virtual void Update()=0;
};