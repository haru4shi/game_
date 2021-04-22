#pragma once
#include "ISceneChanger.h"
#include<DirectXMath.h>
#include "BaseScene.h"
#include"CollisionManager.h"

//class Collisionmanager;

class GameScene:
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

	GameScene(ISceneChanger* changer);

	~GameScene();

	void Initialize(DirectXCommon* dxCommon, Input* input/*, Audio* audio*/);

	void Update();

	void Draw();

private: // �����o�ϐ�
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	
	float acceleration = 0.0001;
	float speed = 0;

	//�Փ˃}�l�[�W��
	CollisionManager* collisionManager = nullptr;

	Object3d* object3d = nullptr;
	TestObject* testObject = nullptr;
};

