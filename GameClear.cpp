#include "GameClear.h"
GameClear::GameClear(ISceneChanger * changer) 
	: BaseScene(changer)
{
}

void GameClear::Initialize(DirectXCommon * dxCommon, Input * input,Audio* audio)
{
	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	gameclearsprite->LoadTexture(1, L"Resources/GameClear.png");

	gameclearsprite->Create(1, {0,0});
}

void GameClear::Update()
{
	if (input->Trigger(DIK_SPACE))
	{
		mSceneChanger->ChangeScene(eScene_Title);//�V�[�����Q�[����ʂɕύX
	}
}

void GameClear::Draw()
{
	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();
	gameclearsprite->PreDraw(cmdList);
	gameclearsprite->Draw();
	gameclearsprite->PostDraw();
	// �[�x�o�b�t�@�N���A
	dxCommon->ClearDepthBuffer();
}