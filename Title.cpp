#include "Title.h"

Title::Title(ISceneChanger * changer) 
	: BaseScene(changer)
{
}

void Title::Initialize(DirectXCommon * dxCommon, Input * input, Audio* audio)
{
	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	assert(audio);

	audio->Initialize();

	Sprite::LoadTexture(1, L"Resources/背景1.png");

	titlesprite1 = Sprite::Create(1, { 0,0 });
}
void Title::Update()
{
	if (input->Trigger(DIK_SPACE))
	{
		mSceneChanger->ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (input->Trigger(DIK_A))
	{
		audio->PlayWave("Resources/Alarm01.wav");//更新
	}
}

void Title::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();
	Sprite::PreDraw(cmdList);

	titlesprite1->Draw();

	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
}