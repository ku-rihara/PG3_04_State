#pragma once

//class
#include"PlayerBullet.h"
//std
#include<list>
#include<memory>

class Player {
private:
	Vector3 pos_;
	
	// 弾
	std::list<std::unique_ptr<PlayerBullet>> bullets_;

public:

	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	void Move();
	void Attack();

	const std::list<std::unique_ptr<PlayerBullet>>& GetBullets() const {
		return bullets_;
	}
};
