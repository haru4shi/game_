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

	//�R���W�����}�l�[�W��������
	collisionManager = CollisionManager::GetInstance();

	// 3D�I�u�W�F�N�g����
	object3d = Object3d::Create(winApp->window_width,winApp->window_height);
	//�R���C�_�[�ǉ�
	object3d->SetCollider(new SphereCollider);
	object3d->Update();

	testObject = TestObject::Create(winApp->window_width, winApp->window_height);
	testObject->Update();
}

void GameScene::Update()
{
	XMFLOAT3 playerPosition = object3d->GetPosition();

#pragma region �L�[���͂ňړ�
	if (input->IsPush(DIK_RIGHT)){ playerPosition.x += 0.5f; }
	if (input->IsPush(DIK_LEFT)) { playerPosition.x -= 0.5f; }
	if (input->IsPush(DIK_UP)) { playerPosition.y += 0.5f; }
	if (input->IsPush(DIK_DOWN)) { playerPosition.y -= 0.5f; }
#pragma endregion

	object3d->SetPosition(playerPosition);

#pragma region �X�V
	object3d->Update();
	testObject->Update();
#pragma endregion
	
	//�S�Ă̏Փ˔�����`�F�b�N
	collisionManager->CheckAllCollision();
}

void GameScene::Draw()
{
	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 3D�I�u�W�F�N�g�`��
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw(cmdList);
	TestObject::PreDraw(cmdList);
	// 3D�I�u�N�W�F�N�g�̕`��
	object3d->Draw();
	testObject->Draw();

	// 3D�I�u�W�F�N�g�`��㏈��
	Object3d::PostDraw();
	TestObject::PostDraw();
#pragma endregion
}
