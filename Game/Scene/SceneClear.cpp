#include "SceneClear.h"
#include "SceneTitle.h"
#include"Input/InputManager.h"
#include"SceneManager.h"

SceneClear::SceneClear() {
	
}

void SceneClear::Init() {

}

void SceneClear::Update() {
	if (InputManager::GetInstance()->GetIsTriggerKey(DIK_SPACE)) {
		SceneManager::GetInstance()->ChangeScene(std::make_unique<SceneTitle>());
	}
}

void SceneClear::Draw() {

	Novice::DrawBox(0, 0, 1280, 720, 0, RED, kFillModeSolid);
	Novice::ScreenPrintf(640, 320, "Title::Space");
	Novice::ScreenPrintf(640, 300, "CLEAR");
}

