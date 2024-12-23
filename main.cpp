#include <Novice.h>
#include"Game/Scene/SceneManager.h"
#include "Game/Scene/SceneTitle.h"
#include"Game/Input/InputManager.h"

const char kWindowTitle[] = "LE2A_11_クリハラ_ケイタ_PG3_04_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	InputManager::GetInstance()->Init();

	// 初期シーンを設定
	SceneManager::GetInstance()->ChangeScene(std::make_unique<SceneTitle>());

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		 // シーンの更新
		SceneManager::GetInstance()->Update();
		InputManager::GetInstance()->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		// シーンの描画
		SceneManager::GetInstance()->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
