#include "GameScene.h"
#include <cassert>

using namespace DirectX;

GameScene::GameScene(ISceneChanger * changer)
	:BaseScene(changer)
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input/*, Audio* audio*/)
{
	this->dxCommon = dxCommon;
	this->input = input;
	//this->audio = audio;
	WinApp* winApp= dxCommon->GetWinApp();

	// 3Dオブジェクト生成
	object3d = Object3d::Create(winApp->window_width,winApp->window_height);
	object3d->Update();
}

void GameScene::Update()
{
	XMFLOAT3 playerPosition = object3d->GetPosition();

	object3d->SetPosition(playerPosition);
	object3d->Update();
}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw(cmdList);
	// 3Dオブクジェクトの描画
	object3d->Draw();

	// 3Dオブジェクト描画後処理
	Object3d::PostDraw();
#pragma endregion
}
