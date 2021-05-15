#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include"Sprite.h"

class GameOver:
	public BaseScene
{
private:
	Sprite* gameoversprite;
	WinApp* win = nullptr;
public:
	GameOver(ISceneChanger* changer);
	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio) override;    //初期化処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Draw() override;            //描画処理をオーバーライド。
};

