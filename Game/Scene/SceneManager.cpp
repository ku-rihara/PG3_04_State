#include "SceneManager.h"


SceneManager* SceneManager::GetInstance() {
    static SceneManager instance;
    return &instance;
}

void SceneManager::ChangeScene(std::unique_ptr<BaseScene> newScene) {
   
    // 新しいシーンに切り替え
    currentScene_ = std::move(newScene);
    currentScene_->Init(); 
}

void SceneManager::Update() {
    if (currentScene_) {
        currentScene_->Update();
    }
   
}

void SceneManager::Draw() {
    if (currentScene_) {
        currentScene_->Draw();
    }
   
}
