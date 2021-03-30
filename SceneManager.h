#pragma once
#include "ISceneChanger.h"
#include"BaseScene.h"
#include"Task.h"


class SceneManager :
	public ISceneChanger,Task
{
private:
	BaseScene* mScene;    //�V�[���Ǘ��ϐ�
	eScene mNextScene;    //���̃V�[���Ǘ��ϐ�
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	//Audio* audio = nullptr;

public:
	SceneManager();
	void Initialize(DirectXCommon* dxCommon, Input* input/*, Audio* audio*/) override;//������
	void Finalize() override;//�I������
	void Update() override;//�X�V
	void Draw() override;//�`��

	// ���� nextScene �ɃV�[����ύX����
	void ChangeScene(eScene NextScene) override;

};

