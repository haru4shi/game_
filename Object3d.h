#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>

class Object3d
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public:
	static Object3d* Create(int window_width, int window_height);//�C���X�^���X������initialize�Ăяo��
	static void StaticInitialize(ID3D12Device * device);
	void InitializeGraphicsPipeline();
	void InitializeDescriptorHeap();
	void InitializeCamera(int window_width, int window_height);
	void Initialize(int window_width, int window_height);//�f�o�C�X����P�g��
	void CreateModel();
	void Update();
	//void PreDraw(ID3D12GraphicsCommandList * cmdList);
	void Draw(ID3D12GraphicsCommandList * cmdList);
	//void PostDraw();
	void LoadMaterial(const std::string& directoryPath,const std::string& filename);
	//void LoadTexture(const std::string& directoryPath, const std::string& filename);
	const XMFLOAT3& GetPosition() { return position; }
	void SetPosition(XMFLOAT3 position) { this->position = position; }
	bool LoadTexture(const std::string& directoryPath, const std::string& filename);


public:
	//�\����
	struct VertexPosNormalUv
	{
		XMFLOAT3 pos; // xyz���W
		XMFLOAT3 normal; // �@���x�N�g��
		XMFLOAT2 uv;  // uv���W
	};

	// �萔�o�b�t�@�p�f�[�^�\����BO
	struct ConstBufferDataBO
	{
		XMMATRIX mat;	// �R�c�ϊ��s��
	};

	//�萔�o�b�t�@�p�f�[�^�\����1
	struct ConstBufferDataB1
	{
		XMFLOAT3 ambient;//�A���r�G���g�W��
		float pad1;     //�p�f�B���O
		XMFLOAT3 diffuse;//�f�B�t�[�Y�W��
		float pad2;    //�p�f�B���O
		XMFLOAT3 speculer;//�X�y�L�����[�W��
		float alpha;    //�A���t�@
	};
	struct Material
	{
		std::string name;//�}�e���A����
		XMFLOAT3 ambient;//�A���r�G���g�e���x
		XMFLOAT3 diffuse;//�f�B�t�[�Y�e���x
		XMFLOAT3 specular;//�X�y�L�����[�e���x
		float alpha;//�A���t�@
		std::string textuerFilename;//�e�N�X�`���t�@�C����
		//�R���X�g���N�^
		Material()
		{
			ambient = { 0.3f,0.3f,0.3f };
			diffuse = { 0.0f,0.0f,0.0f };
			specular = { 0.0f,0.0f,0.0f };
			alpha = 1.0f;
		}
	};
private:
	std::vector<VertexPosNormalUv> vertices;
	std::vector<unsigned short> indices;
	Material material;
	ComPtr<ID3D12Resource> vertBuff;
	ComPtr<ID3D12Resource> indexBuff;
	static ID3D12Device* device;
	XMMATRIX matView;//�r���[�ϊ��s��
	ComPtr<ID3D12PipelineState> pipelinestate;
	ComPtr<ID3D12RootSignature> rootsignature;
	XMFLOAT3 eye = { 0, 0, -50.0f };
	XMFLOAT3 target = { 0, 0, 0 };
	XMFLOAT3 up = { 0, 1, 0 };
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	D3D12_INDEX_BUFFER_VIEW ibView{};
	XMMATRIX matProjection;
	ID3D12GraphicsCommandList* cmdList = nullptr;
	//ComPtr<ID3D12DescriptorHeap> basicDescHeap;
	CD3DX12_CPU_DESCRIPTOR_HANDLE cpuDescHandleSRV;
	CD3DX12_GPU_DESCRIPTOR_HANDLE gpuDescHandleSRV;
	UINT descriptorHandleIncrementSize = 0;
	ComPtr<ID3D12DescriptorHeap> descHeap;
	ComPtr<ID3D12Resource> texbuff;

private:
	ComPtr<ID3D12Resource> constBuffBO;// �萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuffB1;// �萔�o�b�t�@
	XMFLOAT3 rotation = { 0,0,0 };
	XMFLOAT3 position = { -40,-20,0 };
	XMFLOAT4 color = { 1,1,1,1 };
	XMFLOAT3 scale = { 1,1,1 };
	XMMATRIX matWorld;
	//�e�I�u�W�F�N�g
	Object3d* parent = nullptr;
};

