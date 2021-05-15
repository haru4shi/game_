#include "GameOver.h"
GameOver::GameOver(ISceneChanger * changer)
	: BaseScene(changer)
{
}

void GameOver::Initialize(DirectXCommon * dxCommon, Input * input, Audio* audio)
{
	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	gameoversprite->LoadTexture(1, L"Resources/GameOver.png");

	gameoversprite->Create(1, {0,0});
}

void GameOver::Update()
{
	if (input->Trigger(DIK_SPACE))
	{
		mSceneChanger->ChangeScene(eScene_Title);//シーンをゲーム画面に変更
	}
}

void GameOver::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();
	gameoversprite->PreDraw(cmdList);
	gameoversprite->Draw();
	gameoversprite->PostDraw();
	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
}