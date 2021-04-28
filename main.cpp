#include"WinApp.h"
#include"DirectXCommon.h"
#include"SceneManager.h"
#include"BaseScene.h"


// Windows �A�v���ł̃G���g���[�|�C���g(main �֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
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


	// �X�v���C�g�ÓI������
	if (!Sprite::StaticInitialize(dxCommon->GetDevice(), win->window_width,win->window_height)) 
	{
		assert(0);
		return 1;
	}

#pragma region �I�u�W�F�N�g������
	Object3d::StaticInitialize(dxCommon->GetDevice());
	TestObject::StaticInitialize(dxCommon->GetDevice());
	Stage1Item1::StaticInitialize(dxCommon->GetDevice());
	Stage1Item2::StaticInitialize(dxCommon->GetDevice());
#pragma endregion

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
	
	//�E�B���h�E�N���X��o�^����
	win->TerminateGameWindow();
	safe_delete(win);
	return 0;
}
