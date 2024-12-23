#pragma once

//base
#include "BaseScene.h"

#include"Enemy/Enemy.h"
#include"Player/Player.h"
#include<memory>

class ScenePlay :public BaseScene {

private:
	std::unique_ptr<Player>player_;
	std::unique_ptr<Enemy>enemy_;

	float sceneCangeTime_;
	bool isClearScreenChange_;
public:

	ScenePlay();

	void Init()override;
	void Update()override;
	void Draw()override;

	void IsCollisionEnemy(const std::list<std::unique_ptr<PlayerBullet>>& bullets, Enemy* enemy);
	bool CheckCollision(const Vector3& pos1, float radius1, const Vector3& pos2, float radius2);
	void ChangeClear();
};

