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
	void CreateGameWindow();//�E�B���h�E�쐬
	void TerminateGameWindow();//�E�B���h�E�j��

	HWND GetHwnd() { return hwnd; }

	HINSTANCE GetInstance() { return wndClass.hInstance; }

private:
	HWND hwnd = nullptr;	// �E�B���h�E�n���h��
	WNDCLASSEX wndClass{};	// �E�B���h�E�N���X
};

