#pragma once
#include"DirectXCommon.h"
#include"Input.h"
#include"Audio.h"

class Task
{
public:
	virtual ~Task() {}
	virtual void Initialize(DirectXCommon* dxCommon, Input* input,Audio* audio) {}     //����������
	virtual void Finalize() {}     //�I������
	virtual void Update() = 0;   //�X�V�����͕K���p����Ŏ�������
	virtual void Draw() = 0;   //�`�揈���͕K���p����Ŏ�������
};

