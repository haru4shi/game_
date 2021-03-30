#pragma once
#include "ISceneChanger.h"
#include"BaseScene.h"
#include"Task.h"


class SceneManager :
	public ISceneChanger,Task
{
private:
	BaseScene* mScene;    //シーン管理変数
	eScene mNextScene;    //次のシーン管理変数
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	//Audio* audio = nullptr;

public:
	SceneManager();
	void Initialize(DirectXCommon* dxCommon, Input* input/*, Audio* audio*/) override;//初期化
	void Finalize() override;//終了処理
	void Update() override;//更新
	void Draw() override;//描画

	// 引数 nextScene にシーンを変更する
	void ChangeScene(eScene NextScene) override;

};

