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

	// 3D�I�u�W�F�N�g����
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
	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 3D�I�u�W�F�N�g�`��
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw(cmdList);
	// 3D�I�u�N�W�F�N�g�̕`��
	object3d->Draw();

	// 3D�I�u�W�F�N�g�`��㏈��
	Object3d::PostDraw();
#pragma endregion
}
