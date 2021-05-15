#include "SceneManager.h"
#include "Title.h"
#include"GameScene.h"
#include "GameClear.h"
#include "GameOver.h"
#include"Stage1ura.h"

SceneManager::SceneManager() :
	mNextScene(eScene_None) //���̃V�[���Ǘ��ϐ�
{
	mScene = (BaseScene*) new Title(this);
}

//������
void SceneManager::Initialize(DirectXCommon* dxCommon, Input* input,Audio* audio)
{
	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	assert(audio);

	mScene->Initialize(dxCommon, input, audio);
}

//�I������
void SceneManager::Finalize()
{
	mScene->Finalize();
}

//�X�V
void SceneManager::Update()
{
	if (mNextScene != eScene_None)
	{//���̃V�[�����Z�b�g����Ă�����
		mScene->Finalize();//���݂̃V�[���̏I�����������s
		delete mScene;
		switch (mNextScene)
		{       //�V�[���ɂ���ď����𕪊�
		case eScene_Title:        //���̉�ʂ����j���[�Ȃ�
			mScene = (BaseScene*) new Title(this);   //���j���[��ʂ̃C���X�^���X�𐶐�����
			break;//�ȉ���
		case eScene_Game:
			mScene = (BaseScene*) new GameScene(this);
			break;
		case eScene_Stage1ura:
			mScene = (BaseScene*) new Stage1ura(this);
			break;
		case eScene_GameClear:
			mScene = (BaseScene*) new GameClear(this);
			break;
		case eScene_GameOver:
			mScene = (BaseScene*) new GameOver(this);
			break;
		}
		mNextScene = eScene_None;    //���̃V�[�������N���A
		mScene->Initialize(dxCommon, input, audio);    //�V�[����������
	}
	mScene->Update(); //�V�[���̍X�V
}

//�`��
void SceneManager::Draw()
{
	mScene->Draw();
}

// ���� nextScene �ɃV�[����ύX����
void SceneManager::ChangeScene(eScene NextScene)
{
	mNextScene = NextScene;    //���̃V�[�����Z�b�g����
}
