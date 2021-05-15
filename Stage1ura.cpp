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
	//�X�v���C�g
	safe_delete(leftMesssage);
	safe_delete(rigthMessage);
	safe_delete(message);

	//3D�I�u�W�F�N�g
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

#pragma region �X�v���C�g�ǂݍ��ݐ���
	//�ǂݍ���
	Sprite::LoadTexture(1, L"Resources/memo1_n_n2.png");
	Sprite::LoadTexture(2, L"Resources/memo.l_n.png");
	Sprite::LoadTexture(3, L"Resources/memo.r_n.png");

	//����
	message = Sprite::Create(1, { 0,0 });
	rigthMessage = Sprite::Create(2, { 0,0 });
	leftMesssage = Sprite::Create(3, { 0,0 });

#pragma endregion

	//�R���W�����}�l�[�W��������
	collisionManager = CollisionManager::GetInstance();

#pragma region 3D�I�u�W�F�N�g����
	object3d = Object3d::Create(winApp->window_width, winApp->window_height);
	//�R���C�_�[�ǉ�
	object3d->SetCollider(new SphereCollider);
	//�v���C���[�̍��W
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

#pragma region �L�[���͂ňړ�
	if (input->IsPush(DIK_RIGHT)) { playerPosition.x += 0.5f; }
	if (input->IsPush(DIK_LEFT)) { playerPosition.x -= 0.5f; }
	//if (input->IsPush(DIK_UP)) { playerPosition.y += 0.5f; }
	//if (input->IsPush(DIK_DOWN)) { playerPosition.y -= 0.5f; }
#pragma endregion

#pragma region �؂�[�ɓ��B���������

	//��������
	//�I�u�W�F�N�g�Ŕ�����
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

#pragma region �؂�[�m�F�ł���悤�ɂ���
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

#pragma region ���W�Z�b�g
	object3d->SetPosition(playerPosition);

#pragma endregion

#pragma region �X�V
	object3d->Update();
	stage1Item1->Update();
	stage1Item2->Update();

#pragma endregion

	//�S�Ă̏Փ˔�����`�F�b�N
	collisionManager->CheckAllCollision();
}

void Stage1ura::Draw()
{
	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 3D�I�u�W�F�N�g�`��
	//�`��O����
	Object3d::PreDraw(cmdList);
	//TestObject::PreDraw(cmdList);
	Stage1Item1::PreDraw(cmdList);
	Stage1Item2::PreDraw(cmdList);

	//�`��
	object3d->Draw();
	//testObject->Draw();
	if (DrawItem1) stage1Item1->Draw();
	if (DrawItem2) stage1Item2->Draw();

	//�`��㏈��
	Object3d::PostDraw();
	//TestObject::PostDraw();
	Stage1Item1::PostDraw();
	Stage1Item2::PostDraw();
#pragma endregion

#pragma region �O�i�X�v���C�g�`��
	//�`��O����
	Sprite::PreDraw(cmdList);

	//�`��
	if (DrawRaightMessage) rigthMessage->Draw();
	if (DrawLeftMessage) leftMesssage->Draw();
	if (DrawMessage) message->Draw();

	//�`��㏈��
	Sprite::PostDraw();
#pragma endregion
}
