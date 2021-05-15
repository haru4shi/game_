#include "Stage1ura.h"
#include <cassert>
#include"SphereCollider.h"

using namespace DirectX;

Stage1ura::Stage1ura(ISceneChanger* changer)
	:BaseScene(changer)
{
}

Stage1ura::~Stage1ura()
{
	//スプライト
	safe_delete(leftMesssage);
	safe_delete(rigthMessage);
	safe_delete(message);

	//3Dオブジェクト
	safe_delete(object3d);
	safe_delete(stage1Item1);
	safe_delete(stage1Item2);
}

void Stage1ura::Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio)
{
	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;
	WinApp* winApp = dxCommon->GetWinApp();

#pragma region スプライト読み込み生成
	//読み込み
	Sprite::LoadTexture(1, L"Resources/memo1_n_n2.png");
	Sprite::LoadTexture(2, L"Resources/memo.l_n.png");
	Sprite::LoadTexture(3, L"Resources/memo.r_n.png");

	//生成
	message = Sprite::Create(1, { 0,0 });
	rigthMessage = Sprite::Create(2, { 0,0 });
	leftMesssage = Sprite::Create(3, { 0,0 });

#pragma endregion

	//コリジョンマネージャ初期化
	collisionManager = CollisionManager::GetInstance();

#pragma region 3Dオブジェクト生成
	object3d = Object3d::Create(winApp->window_width, winApp->window_height);
	//コライダー追加
	object3d->SetCollider(new SphereCollider);
	//プレイヤーの座標
	XMFLOAT3 playerPos = object3d->GetPosition();
	object3d->SetPosition(playerPos);
	object3d->Update();

	stage1Item1 = Stage1Item1::Create(winApp->window_width, winApp->window_height);
	stage1Item1->Update();

	stage1Item2 = Stage1Item2::Create(winApp->window_width, winApp->window_height);
	stage1Item2->Update();

#pragma endregion

	
}

void Stage1ura::Update()
{
	XMFLOAT3 playerPosition = object3d->GetPosition();

#pragma region キー入力で移動
	if (input->IsPush(DIK_RIGHT)) { playerPosition.x += 0.5f; }
	if (input->IsPush(DIK_LEFT)) { playerPosition.x -= 0.5f; }
	//if (input->IsPush(DIK_UP)) { playerPosition.y += 0.5f; }
	//if (input->IsPush(DIK_DOWN)) { playerPosition.y -= 0.5f; }
#pragma endregion

#pragma region 切れ端に到達したら消す

	//ここ調整
	//オブジェクトで判定取る
	if (playerPosition.x == 38)
	{
		Item1Get = true;
	}
	if (playerPosition.x == -40 && playerPosition.y == 10)
	{
		Item2Get = true;
	}



	if (Item1Get == true)
	{
		DrawItem1 = false;
	}
	if (Item2Get == true)
	{
		DrawItem2 = false;
	}


#pragma endregion

#pragma region 切れ端確認できるようにする
	if (Item1Get == true && input->Trigger(DIK_TAB))
	{
		DrawRaightMessage = true;
	}
	if (Item2Get == true && input->Trigger(DIK_TAB))
	{
		DrawLeftMessage = true;
	}

	if (Item1Get == true && Item2Get == true)
	{
		Item1Get = false;
		Item2Get = false;
		AllitemGet = true;
	}

	if (AllitemGet == true && input->Trigger(DIK_TAB))
	{
		DrawMessage = true;
	}

	if (input->Trigger(DIK_ESCAPE))
	{
		DrawRaightMessage = false;
		DrawLeftMessage = false;
		DrawMessage = false;
	}

#pragma endregion

#pragma region 座標セット
	object3d->SetPosition(playerPosition);

#pragma endregion

#pragma region 更新
	object3d->Update();
	stage1Item1->Update();
	stage1Item2->Update();

#pragma endregion

	//全ての衝突判定をチェック
	collisionManager->CheckAllCollision();
}

void Stage1ura::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 3Dオブジェクト描画
	//描画前処理
	Object3d::PreDraw(cmdList);
	//TestObject::PreDraw(cmdList);
	Stage1Item1::PreDraw(cmdList);
	Stage1Item2::PreDraw(cmdList);

	//描画
	object3d->Draw();
	//testObject->Draw();
	if (DrawItem1) stage1Item1->Draw();
	if (DrawItem2) stage1Item2->Draw();

	//描画後処理
	Object3d::PostDraw();
	//TestObject::PostDraw();
	Stage1Item1::PostDraw();
	Stage1Item2::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	//描画前処理
	Sprite::PreDraw(cmdList);

	//描画
	if (DrawRaightMessage) rigthMessage->Draw();
	if (DrawLeftMessage) leftMesssage->Draw();
	if (DrawMessage) message->Draw();

	//描画後処理
	Sprite::PostDraw();
#pragma endregion
}
