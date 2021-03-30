#pragma once
#define backBufferCount 2

#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <d3dx12.h>
#include <cstdlib>
#include "WinApp.h"

class DirectXCommon
{
private:
	//Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	void Initialize(WinApp* win);//初期化
	void PreDraw();//描画前
	void PostDraw();//描画後
	void ClearRenderTarget();//レンダーターゲットクリア
	void ClearDepthBuffer();//深度バッファのクリア
	//デバイス取得
	ID3D12Device* GetDevice() { return device.Get(); }
	//描画コマンド取得
	ID3D12GraphicsCommandList* GetCommandList() { return cmdList.Get(); }

	WinApp* GetWinApp(){ return winApp; }

private:
	void InitializeDXGIDevice();//デバイス初期化
	void CreateSwapChain();//スワップチェーン生成
	void InitializeCommand();//コマンド関連初期化
	void CreateDepthBuffer();//深度バッファ生成
	void CreateFence();//フェンス生成
	void CreateFinalRenderTargets();//初期化用レンダーターゲット生成

private:
	WinApp* winApp;

	ComPtr<ID3D12Device> device;
	ComPtr<ID3D12GraphicsCommandList> cmdList;
	ComPtr<IDXGIFactory6> dxgiFactory;
	ComPtr<ID3D12CommandQueue> cmdQueue;
	ComPtr<IDXGISwapChain4> swapchain;
	ComPtr<ID3D12CommandAllocator> cmdAllocator;
	ComPtr<ID3D12DescriptorHeap> rtvHeaps;
	ComPtr<ID3D12DescriptorHeap> dsvHeap;
	std::vector<ComPtr<ID3D12Resource>> backBuffers{ backBufferCount };
	ComPtr<ID3D12Resource> depthBuffer;
	ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;
};

