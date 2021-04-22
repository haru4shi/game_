#include "GameScene.h"
#include <cassert>
#include"SphereCollider.h"

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

	//コリジョンマネージャ初期化
	collisionManager = CollisionManager::GetInstance();

	// 3Dオブジェクト生成
	object3d = Object3d::Create(winApp->window_width,winApp->window_height);
	//コライダー追加
	object3d->SetCollider(new SphereCollider);
	object3d->Update();

	testObject = TestObject::Create(winApp->window_width, winApp->window_height);
	testObject->Update();
}

void GameScene::Update()
{
	XMFLOAT3 playerPosition = object3d->GetPosition();

#pragma region キー入力で移動
	if (input->IsPush(DIK_RIGHT)){ playerPosition.x += 0.5f; }
	if (input->IsPush(DIK_LEFT)) { playerPosition.x -= 0.5f; }
	if (input->IsPush(DIK_UP)) { playerPosition.y += 0.5f; }
	if (input->IsPush(DIK_DOWN)) { playerPosition.y -= 0.5f; }
#pragma endregion

	object3d->SetPosition(playerPosition);

#pragma region 更新
	object3d->Update();
	testObject->Update();
#pragma endregion
	
	//全ての衝突判定をチェック
	collisionManager->CheckAllCollision();
}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw(cmdList);
	TestObject::PreDraw(cmdList);
	// 3Dオブクジェクトの描画
	object3d->Draw();
	testObject->Draw();

	// 3Dオブジェクト描画後処理
	Object3d::PostDraw();
	TestObject::PostDraw();
#pragma endregion
}
