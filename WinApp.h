#pragma once
#include<Windows.h>

class WinApp
{
public:
	const int window_width = 1280;
	const int window_height = 720;
	static const wchar_t windowClassName[];

public:
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public:
	void CreateGameWindow();//ウィンドウ作成
	void TerminateGameWindow();//ウィンドウ破棄

	HWND GetHwnd() { return hwnd; }

	HINSTANCE GetInstance() { return wndClass.hInstance; }

private:
	HWND hwnd = nullptr;	// ウィンドウハンドル
	WNDCLASSEX wndClass{};	// ウィンドウクラス
};

