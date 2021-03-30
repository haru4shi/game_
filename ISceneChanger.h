#pragma once
typedef enum
{
	eScene_Title,    //���j���[���
	eScene_Game,    //�Q�[�����(1�X�e�[�W��)
	eScene_Stage2,  //2�X�e�[�W��
	eScene_Stage3,  //3�X�e�[�W��
	eScene_Stage4,  //4�X�e�[�W��
	eScene_Stage5,  //5�X�e�[�W��
	eScene_Stage6,  //6�X�e�[�W��
	eScene_Stage7,  //7�X�e�[�W��
	eScene_Stage8,  //8�X�e�[�W��
	eScene_GameOver,//�Q�[���I�[�o�[���
	eScene_GameClear,//�N���A���

	eScene_None,    //����
} eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene NextScene) = 0;//�w��V�[���ɕύX����
};

