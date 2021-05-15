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
		mSceneChanger->ChangeScene(eScene_Title);//�V�[�����Q�[����ʂɕύX
	}
}

void GameOver::Draw()
{
	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();
	gameoversprite->PreDraw(cmdList);
	gameoversprite->Draw();
	gameoversprite->PostDraw();
	// �[�x�o�b�t�@�N���A
	dxCommon->ClearDepthBuffer();
}