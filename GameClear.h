#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include"Sprite.h"


class GameClear :
	public BaseScene
{
private:
	Sprite* gameclearsprite;
	WinApp* win = nullptr;
public:
	GameClear(ISceneChanger* changer);
	void Initialize(DirectXCommon* dxCommon, Input* input,Audio* audio) override;    //�������������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw() override;            //�`�揈�����I�[�o�[���C�h�B

};

