#include"Input.h"
#include"Sprite.h"
#include"Object3d.h"
#include"WinApp.h"
#include"DirectXCommon.h"
#include"SceneManager.h"


// Windows �A�v���ł̃G���g���[�|�C���g(main �֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	//Audio* audio = nullptr;
	//Sprite* sprite = nullptr;
	//Object3d* object3d = nullptr;
	SceneManager* sceneManager = nullptr;

	//�Q�[���E�B���h�E�쐬
	win = new WinApp();
	win->CreateGameWindow();

	//DirectX�̏����������@��������
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(win);

	//������
	input = new Input();
	input->Initialize(win->GetHwnd(),win->GetInstance());

	//sprite = new Sprite();
	//sprite->StaticInitialize(dxCommon->GetDevice(), win->window_width, win->window_height);

	// �X�v���C�g�ÓI������
	if (!Sprite::StaticInitialize(dxCommon->GetDevice(), win->window_width,win->window_height)) 
	{
		assert(0);
		return 1;
	}

	//Audio�̏�����
	//audio = new Audio();
	//if (!audio->Initialize()) 
	//{
	//	assert(0);
	//	return 1;
	//}

	//�I�u�W�F�N�g�̏�����
	Object3d::StaticInitialize(dxCommon->GetDevice());

	//�Q�[���V�[���̏�����
	sceneManager = new SceneManager();
	sceneManager->Initialize(dxCommon, input);

	while (1)
	{
		MSG msg{};
		//���b�Z�[�W������H
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);//�L�[���̓��b�Z�[�W�̏���
			DispatchMessage(&msg);//�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
		}
		//�I�����b�Z�[�W�������烋�[�v�𔲂���
		if (msg.message == WM_QUIT)
		{
			break;
		}

		//���͊֌W�X�V
		input->Update();

		//�Q�[���V�[���̖��t���[������
		sceneManager->Update();

		//�`��O�̏���
		dxCommon->PreDraw();
		
		//�Q�[���V�[���`��
		sceneManager->Draw();

		//�`���̏���
		dxCommon->PostDraw();
		//DirectX�̖��t���[�������@�����܂�
	}
	safe_delete(dxCommon);
	safe_delete(sceneManager);
	safe_delete(input);
	//safe_delete(audio);
	
	//�E�B���h�E�N���X��o�^����
	win->TerminateGameWindow();
	safe_delete(win);
	return 0;
}