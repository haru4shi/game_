#pragma once
#include <Windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION     0x0800          // DirectInput�̃o�[�W�����w��
#include <dinput.h>

class Input
{
private:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	Input();
	~Input();
	//������
	void Initialize(HWND hwnd, HINSTANCE hInstance);
	//���t���[���X�V
	void Update();
	//�L�[��������Ă��邩�ǂ������`�F�b�N����
	bool IsPush(int keyNumber);
	//�L�[�̃g���K�[�`�F�b�N
	bool Trigger(int keyNumber);

private:
	ComPtr<IDirectInput8> dinput;
	ComPtr<IDirectInputDevice8> devkeyboard;
	//�L�[�{�[�h���͏��
	BYTE key[256] = {};
	//�O��̃L�[���
	BYTE keyPre[256] = {};
};

