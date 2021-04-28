#pragma once
#include"WinApp.h"
#include "Task.h"
#include "ISceneChanger.h"
#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
#include "Object3d.h"
#include"TestObject.h"
#include"Stage1Item1.h"
#include"Stage1Item2.h"

class BaseScene :
	public Task
{
protected: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

protected:
	ISceneChanger* mSceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X 
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Sprite* sprite1 = nullptr;
	Sprite* sprite2 = nullptr;
	//Audio* audio = nullptr;

protected: // �ÓI�����o�ϐ�
	static const int debugTextTexNumber = 0;

public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize(DirectXCommon* dxCommon, Input* input/*,Audio* audio*/) override;    //�������������I�[�o�[���C�h�B
	virtual void Finalize() override;        //�I���������I�[�o�[���C�h�B
	virtual void Update() override;        //�X�V�������I�[�o�[���C�h�B
	virtual void Draw() override;            //�`�揈�����I�[�o�[���C�h�B

};

