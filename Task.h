#pragma once
#include"DirectXCommon.h"
#include"Input.h"
#include"Audio.h"

class Task
{
public:
	virtual ~Task() {}
	virtual void Initialize(DirectXCommon* dxCommon, Input* input,Audio* audio) {}     //初期化処理
	virtual void Finalize() {}     //終了処理
	virtual void Update() = 0;   //更新処理は必ず継承先で実装する
	virtual void Draw() = 0;   //描画処理は必ず継承先で実装する
};

