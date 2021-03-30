#include "BaseScene.h"

BaseScene::BaseScene(ISceneChanger * changer)
	:mSceneChanger(changer)
{
}

void BaseScene::Initialize(DirectXCommon * dxCommon, Input * input)
{
	assert(dxCommon);
	assert(input);
	//assert(audio);

	this->dxCommon = dxCommon;
	this->input = input;
	//this->audio = audio;
}

void BaseScene::Finalize()
{
}

void BaseScene::Update()
{
}
void BaseScene::Draw()
{
}