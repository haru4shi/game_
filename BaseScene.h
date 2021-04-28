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
protected: // エイリアス
// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

protected:
	ISceneChanger* mSceneChanger;    //クラス所有元にシーン切り替えを伝えるインターフェイス 
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Sprite* sprite1 = nullptr;
	Sprite* sprite2 = nullptr;
	//Audio* audio = nullptr;

protected: // 静的メンバ変数
	static const int debugTextTexNumber = 0;

public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize(DirectXCommon* dxCommon, Input* input/*,Audio* audio*/) override;    //初期化処理をオーバーライド。
	virtual void Finalize() override;        //終了処理をオーバーライド。
	virtual void Update() override;        //更新処理をオーバーライド。
	virtual void Draw() override;            //描画処理をオーバーライド。

};

