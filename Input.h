#pragma once
#include <Windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION     0x0800          // DirectInputのバージョン指定
#include <dinput.h>

class Input
{
private:
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	Input();
	~Input();
	//初期化
	void Initialize(HWND hwnd, HINSTANCE hInstance);
	//毎フレーム更新
	void Update();
	//キーが押されているかどうかをチェックする
	bool IsPush(int keyNumber);
	//キーのトリガーチェック
	bool Trigger(int keyNumber);

private:
	ComPtr<IDirectInput8> dinput;
	ComPtr<IDirectInputDevice8> devkeyboard;
	//キーボード入力情報
	BYTE key[256] = {};
	//前回のキー情報
	BYTE keyPre[256] = {};
};

