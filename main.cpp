#include"WinApp.h"
#include"DirectXCommon.h"
#include"SceneManager.h"
#include"BaseScene.h"


// Windows アプリでのエントリーポイント(main 関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	SceneManager* sceneManager = nullptr;

	//ゲームウィンドウ作成
	win = new WinApp();
	win->CreateGameWindow();

	//DirectXの初期化処理　ここから
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(win);

	//初期化
	input = new Input();
	input->Initialize(win->GetHwnd(),win->GetInstance());


	// スプライト静的初期化
	if (!Sprite::StaticInitialize(dxCommon->GetDevice(), win->window_width,win->window_height)) 
	{
		assert(0);
		return 1;
	}

#pragma region オブジェクト初期化
	Object3d::StaticInitialize(dxCommon->GetDevice());
	TestObject::StaticInitialize(dxCommon->GetDevice());
	Stage1Item1::StaticInitialize(dxCommon->GetDevice());
	Stage1Item2::StaticInitialize(dxCommon->GetDevice());
#pragma endregion

	//ゲームシーンの初期化
	sceneManager = new SceneManager();
	sceneManager->Initialize(dxCommon, input);

	while (1)
	{
		MSG msg{};
		//メッセージがある？
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);//キー入力メッセージの処理
			DispatchMessage(&msg);//プロシージャにメッセージを送る
		}
		//終了メッセージが来たらループを抜ける
		if (msg.message == WM_QUIT)
		{
			break;
		}

		//入力関係更新
		input->Update();

		//ゲームシーンの毎フレーム処理
		sceneManager->Update();

		//描画前の処理
		dxCommon->PreDraw();
		
		//ゲームシーン描画
		sceneManager->Draw();

		//描画後の処理
		dxCommon->PostDraw();
		//DirectXの毎フレーム処理　ここまで
	}
	safe_delete(dxCommon);
	safe_delete(sceneManager);
	safe_delete(input);
	
	//ウィンドウクラスを登録解除
	win->TerminateGameWindow();
	safe_delete(win);
	return 0;
}
