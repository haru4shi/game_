#pragma once
typedef enum
{
	eScene_Title,    //メニュー画面
	eScene_Game,    //ゲーム画面(1ステージ目)
	eScene_Stage2,  //2ステージ目
	eScene_Stage3,  //3ステージ目
	eScene_Stage4,  //4ステージ目
	eScene_Stage5,  //5ステージ目
	eScene_Stage6,  //6ステージ目
	eScene_Stage7,  //7ステージ目
	eScene_Stage8,  //8ステージ目
	eScene_GameOver,//ゲームオーバー画面
	eScene_GameClear,//クリア画面

	eScene_None,    //無し
} eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene NextScene) = 0;//指定シーンに変更する
};

