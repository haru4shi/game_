#include "Title.h"

Title::Title(ISceneChanger * changer) 
	: BaseScene(changer)
{
}

void Title::Initialize(DirectXCommon * dxCommon, Input * input/*, Audio* audio*/)
{
	this->dxCommon = dxCommon;
	this->input = input;
	//this->audio = audio;

	Sprite::LoadTexture(1, L"Resources/�w�i1.png");

	titlesprite1 = Sprite::Create(1, { 0,0 });
}
void Title::Update()
{
	if (input->Trigger(DIK_SPACE))
	{
		mSceneChanger->ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
}

void Title::Draw()
{
	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();
	Sprite::PreDraw(cmdList);

	titlesprite1->Draw();

	Sprite::PostDraw();
	// �[�x�o�b�t�@�N���A
	dxCommon->ClearDepthBuffer();
}