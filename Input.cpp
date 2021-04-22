#include "Input.h"
#include<cassert>

#pragma comment(lib, "dinput8.lib")

//メンバ関数の定義
Input::Input()
{
}

Input::~Input()
{
}

void Input::Initialize(HWND hwnd, HINSTANCE hInstance)
{
	HRESULT result;
	//DirectInputオブジェクト生成
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, nullptr);
	//キーボードデバイスの生成
	result = dinput->CreateDevice(GUID_SysKeyboard, &devkeyboard, NULL);
	//入力データのセット
	result = devkeyboard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
	//排他的レベルのセット
	result = devkeyboard->SetCooperativeLevel(
		hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
}

void Input::Update()
{
	HRESULT result;
	//キーボード情報の取得開始 UpDateKey
	result = devkeyboard->Acquire();

	//前回のキー入力処理をコピー
	for (int i = 0; i < 256; i++)
	{
		keyPre[i] = key[i];
	}
	//全キーの入力状態を取得する
	result = devkeyboard->GetDeviceState(sizeof(key), key);
}

bool Input::IsPush(int keyNumber)
{
	//キー配列の設定値を超えたら判定をしない
	if (keyNumber < 0)
	{
		OutputDebugString(TEXT("キー配列の設定値を超えたためトリガー判定を行えない"));
		return false;
	}
	if (keyNumber > 255)
	{
		OutputDebugString(TEXT("キー配列の設定値を超えたためトリガー判定を行えない"));
		return false;
	}

	//範囲内ならキー入力判定
	if (key[keyNumber])
	{
		return true;
	}
	return false;
}

bool Input::Trigger(int keyNumber)
{
	//キー配列の設定値を超えたら判定をしない
	if (keyNumber < 0)
	{
		OutputDebugString(TEXT("キー配列の設定値を超えたためトリガー判定を行えない"));
		return false;
	}
	if (keyNumber > 255)
	{
		OutputDebugString(TEXT("キー配列の設定値を超えたためトリガー判定を行えない"));
		return false;
	}

	//前回押されていない（1フレーム前）かつ今回押されている
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
