#include "SceneTitle.h"
#include"ScenePlay.h"
#include"Game/Input/InputManager.h"
#include"SceneManager.h"

SceneTitle::SceneTitle() {

	
	
}

void SceneTitle::Init() {
	
}

void SceneTitle::Update() {
	    
	if (InputManager::GetInstance()->GetIsTriggerKey(DIK_SPACE)) {
		SceneManager::GetInstance()->ChangeScene(std::make_unique<ScenePlay>());
	}
}

void SceneTitle::Draw() {
	
	Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
	Novice::ScreenPrintf(640, 320, "Start::Space");
	Novice::ScreenPrintf(640, 300, "TITLE");
}

