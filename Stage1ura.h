#pragma once
#include "ISceneChanger.h"
#include<DirectXMath.h>
#include "BaseScene.h"
#include"CollisionManager.h"
#include"GameScene.h"

class Stage1ura:
	public BaseScene
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: // �ÓI�����o�ϐ�
	static const int debugTextTexNumber = 0;

public: // �����o�֐�

	Stage1ura(ISceneChanger* changer);

	~Stage1ura();

	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio);

	void Update();

	void Draw();

private: // �����o�ϐ�
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	//�Փ˃}�l�[�W��
	CollisionManager* collisionManager = nullptr;

	Object3d* object3d = nullptr;
	Stage1Item1* stage1Item1 = nullptr;
	Stage1Item2* stage1Item2 = nullptr;

	//���b�Z�[�W
	Sprite* rigthMessage = nullptr;
	Sprite* leftMesssage = nullptr;
	Sprite* message = nullptr;

	//bool
	bool DrawMessage = false;
	bool DrawRaightMessage = false;
	bool DrawLeftMessage = false;

	bool Item1Get = false;
	bool Item2Get = false;
	bool AllitemGet = false;

	bool DrawItem1 = true;
	bool DrawItem2 = true;
};

