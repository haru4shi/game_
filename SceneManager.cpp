#include "SceneManager.h"
#include "Title.h"
#include"GameScene.h"
#include "GameClear.h"
#include "GameOver.h"
#include"Stage1ura.h"

SceneManager::SceneManager() :
	mNextScene(eScene_None) //次のシーン管理変数
{
	mScene = (BaseScene*) new Title(this);
}

//初期化
void SceneManager::Initialize(DirectXCommon* dxCommon, Input* input,Audio* audio)
{
	this->dxCommon = dxCommon;
	this->input = input;
	this->audio = audio;

	assert(audio);

	mScene->Initialize(dxCommon, input, audio);
}

//終了処理
void SceneManager::Finalize()
{
	mScene->Finalize();
}

//更新
void SceneManager::Update()
{
	if (mNextScene != eScene_None)
	{//次のシーンがセットされていたら
		mScene->Finalize();//現在のシーンの終了処理を実行
		delete mScene;
		switch (mNextScene)
		{       //シーンによって処理を分岐
		case eScene_Title:        //次の画面がメニューなら
			mScene = (BaseScene*) new Title(this);   //メニュー画面のインスタンスを生成する
			break;//以下略
		case eScene_Game:
			mScene = (BaseScene*) new GameScene(this);
			break;
		case eScene_Stage1ura:
			mScene = (BaseScene*) new Stage1ura(this);
			break;
		case eScene_GameClear:
			mScene = (BaseScene*) new GameClear(this);
			break;
		case eScene_GameOver:
			mScene = (BaseScene*) new GameOver(this);
			break;
		}
		mNextScene = eScene_None;    //次のシーン情報をクリア
		mScene->Initialize(dxCommon, input, audio);    //シーンを初期化
	}
	mScene->Update(); //シーンの更新
}

//描画
void SceneManager::Draw()
{
	mScene->Draw();
}

// 引数 nextScene にシーンを変更する
void SceneManager::ChangeScene(eScene NextScene)
{
	mNextScene = NextScene;    //次のシーンをセットする
}
