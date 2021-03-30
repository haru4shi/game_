#include "WinApp.h"

const wchar_t WinApp::windowClassName[] = L"DirectXGame";

LRESULT WinApp::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//���b�Z�[�W�ŕ���
	switch (msg)
	{
	case WM_DESTROY://�E�B���h�E���j�����ꂽ
		PostQuitMessage(0);//OS�ɑ΂��āA�A�v���̏I����`����
		return 0;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);//�W���̏������s��
}

void WinApp::CreateGameWindow()
{
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpfnWndProc = (WNDPROC)WindowProc;//�E�B���h�E�v���V�[�W���[��ݒ�
	wndClass.lpszClassName = L"DirectXGame";//�E�B���h�E�N���X��
	wndClass.hInstance = GetModuleHandle(nullptr);//�E�B���h�E�n���h��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//�J�[�\���w��

	RegisterClassEx(&wndClass); // �E�B���h�E�N���X��OS�ɓo�^

	// �E�B���h�E�T�C�Y{ X���W Y���W ���� �c�� }
	RECT wrc = { 0, 0, window_width, window_height };
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false); // �����ŃT�C�Y�␳

	// �E�B���h�E�I�u�W�F�N�g�̐���
	hwnd = CreateWindow(wndClass.lpszClassName, // �N���X��
		windowClassName,			// �^�C�g���o�[�̕���
		WS_OVERLAPPEDWINDOW,	// �^�C�g���o�[�Ƌ��E��������E�B���h�E
		CW_USEDEFAULT,			// �\��X���W�iOS�ɔC����j
		CW_USEDEFAULT,			// �\��Y���W�iOS�ɔC����j
		wrc.right - wrc.left,	// �E�B���h�E����
		wrc.bottom - wrc.top,	// �E�B���h�E�c��
		nullptr,				// �e�E�B���h�E�n���h��
		nullptr,				// ���j���[�n���h��
		wndClass.hInstance,			// �Ăяo���A�v���P�[�V�����n���h��
		nullptr);				// �I�v�V����

	// �E�B���h�E�\��
	ShowWindow(hwnd, SW_SHOW);
}

void WinApp::TerminateGameWindow()
{	
	// �E�B���h�E�N���X��o�^����
	UnregisterClass(wndClass.lpszClassName, wndClass.hInstance);
}
