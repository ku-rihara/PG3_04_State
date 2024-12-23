#pragma once

#include <memory>
#include "BaseScene.h"

class SceneManager {
private:
    std::unique_ptr<BaseScene> currentScene_; // 現在のシーン

public:
   static SceneManager* GetInstance();

    
    // シーンを変更
    void ChangeScene(std::unique_ptr<BaseScene> newScene);

    //更新、描画
    void Update();
    void Draw();
};
