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
	//Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	void Initialize(WinApp* win);//������
	void PreDraw();//�`��O
	void PostDraw();//�`���
	void ClearRenderTarget();//�����_�[�^�[�Q�b�g�N���A
	void ClearDepthBuffer();//�[�x�o�b�t�@�̃N���A
	//�f�o�C�X�擾
	ID3D12Device* GetDevice() { return device.Get(); }
	//�`��R�}���h�擾
	ID3D12GraphicsCommandList* GetCommandList() { return cmdList.Get(); }

	WinApp* GetWinApp(){ return winApp; }

private:
	void InitializeDXGIDevice();//�f�o�C�X������
	void CreateSwapChain();//�X���b�v�`�F�[������
	void InitializeCommand();//�R�}���h�֘A������
	void CreateDepthBuffer();//�[�x�o�b�t�@����
	void CreateFence();//�t�F���X����
	void CreateFinalRenderTargets();//�������p�����_�[�^�[�Q�b�g����

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

