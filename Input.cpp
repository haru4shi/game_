#include "Input.h"
#include<cassert>

#pragma comment(lib, "dinput8.lib")

//�����o�֐��̒�`
Input::Input()
{
}

Input::~Input()
{
}

void Input::Initialize(HWND hwnd, HINSTANCE hInstance)
{
	HRESULT result;
	//DirectInput�I�u�W�F�N�g����
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, nullptr);
	//�L�[�{�[�h�f�o�C�X�̐���
	result = dinput->CreateDevice(GUID_SysKeyboard, &devkeyboard, NULL);
	//���̓f�[�^�̃Z�b�g
	result = devkeyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
	//�r���I���x���̃Z�b�g
	result = devkeyboard->SetCooperativeLevel(
		hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
}

void Input::Update()
{
	HRESULT result;
	//�L�[�{�[�h���̎擾�J�n UpDateKey
	result = devkeyboard->Acquire();

	//�O��̃L�[���͏������R�s�[
	for (int i = 0; i < 256; i++)
	{
		keyPre[i] = key[i];
	}
	//�S�L�[�̓��͏�Ԃ��擾����
	result = devkeyboard->GetDeviceState(sizeof(key), key);
}

bool Input::IsPush(int keyNumber)
{
	//�L�[�z��̐ݒ�l�𒴂����画������Ȃ�
	if (keyNumber < 0)
	{
		OutputDebugString(TEXT("�L�[�z��̐ݒ�l�𒴂������߃g���K�[������s���Ȃ�"));
		return false;
	}
	if (keyNumber > 255)
	{
		OutputDebugString(TEXT("�L�[�z��̐ݒ�l�𒴂������߃g���K�[������s���Ȃ�"));
		return false;
	}

	//�͈͓��Ȃ�L�[���͔���
	if (key[keyNumber])
	{
		return true;
	}
	return false;
}

bool Input::Trigger(int keyNumber)
{
	//�L�[�z��̐ݒ�l�𒴂����画������Ȃ�
	if (keyNumber < 0)
	{
		OutputDebugString(TEXT("�L�[�z��̐ݒ�l�𒴂������߃g���K�[������s���Ȃ�"));
		return false;
	}
	if (keyNumber > 255)
	{
		OutputDebugString(TEXT("�L�[�z��̐ݒ�l�𒴂������߃g���K�[������s���Ȃ�"));
		return false;
	}

	//�O�񉟂���Ă��Ȃ��i1�t���[���O�j�����񉟂���Ă���
	if (!keyPre[keyNumber] && key[keyNumber])
	{
		return true;
	}
	return false;
}

Input* Input::GetInstance()
{
	static Input instance;

	return &instance;
}
