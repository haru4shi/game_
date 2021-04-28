#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>
#include"CollisionInfo.h"

class BaseCollider;

class Object3d
{
protected: // エイリアス
// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public:
	static Object3d* Create(int window_width, int window_height);//インスタンス生成とinitialize呼び出し
	static void StaticInitialize(ID3D12Device * device);
	void InitializeGraphicsPipeline();
	void InitializeDescriptorHeap();
	void InitializeCamera(int window_width, int window_height);
	//void Initialize(int window_width, int window_height);//デバイスを上ケトル
	void CreateModel();
	//void Update();
	static void PreDraw(ID3D12GraphicsCommandList * cmdList);
	//void Draw();
	static void PostDraw();
	void LoadMaterial(const std::string& directoryPath,const std::string& filename);
	const XMFLOAT3& GetPosition() { return position; }
	void SetPosition(XMFLOAT3 position) { this->position = position; }
	bool LoadTexture(const std::string& directoryPath, const std::string& filename);

	//コンストラクタ
	Object3d() = default;
	//仮想デストラクタ
	virtual ~Object3d();
	//初期化
	virtual void Initialize(int window_width, int window_height);
	virtual void Update();
	virtual void Draw();

	//ワールド行列取得
	const XMMATRIX& GetMatWorld() { return matWorld; }

	//コライダーのセット
	void SetCollider(BaseCollider* collider);

	//衝突時のコールバック関数
	virtual void OnCollision(const CollisionInfo& info){}

public:
	//構造体
	struct VertexPosNormalUv
	{
		XMFLOAT3 pos; // xyz座標
		XMFLOAT3 normal; // 法線ベクトル
		XMFLOAT2 uv;  // uv座標
	};

	// 定数バッファ用データ構造体BO
	struct ConstBufferDataBO
	{
		XMMATRIX mat;	// ３Ｄ変換行列
	};

	//定数バッファ用データ構造体1
	struct ConstBufferDataB1
	{
		XMFLOAT3 ambient;//アンビエント係数
		float pad1;     //パディング
		XMFLOAT3 diffuse;//ディフーズ係数
		float pad2;    //パディング
		XMFLOAT3 speculer;//スペキュラー係数
		float alpha;    //アルファ
	};
	struct Material
	{
		std::string name;//マテリアル名
		XMFLOAT3 ambient;//アンビエント影響度
		XMFLOAT3 diffuse;//ディフーズ影響度
		XMFLOAT3 specular;//スペキュラー影響度
		float alpha;//アルファ
		std::string textuerFilename;//テクスチャファイル名
		//コンストラクタ
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
	XMMATRIX matView;//ビュー変換行列
	static ComPtr<ID3D12PipelineState> pipelinestate;
	static ComPtr<ID3D12RootSignature> rootsignature;
	XMFLOAT3 eye = { 0, 0, -50.0f };
	XMFLOAT3 target = { 0, 0, 0 };
	XMFLOAT3 up = { 0, 1, 0 };
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	D3D12_INDEX_BUFFER_VIEW ibView{};
	XMMATRIX matProjection;
	static ID3D12GraphicsCommandList* cmdList;
	CD3DX12_CPU_DESCRIPTOR_HANDLE cpuDescHandleSRV;
	CD3DX12_GPU_DESCRIPTOR_HANDLE gpuDescHandleSRV;
	UINT descriptorHandleIncrementSize = 0;
	ComPtr<ID3D12DescriptorHeap> descHeap;
	ComPtr<ID3D12Resource> texbuff;

protected:
	ComPtr<ID3D12Resource> constBuffBO;// 定数バッファ
	ComPtr<ID3D12Resource> constBuffB1;// 定数バッファ
	XMFLOAT3 rotation = { 0,0,0 };
	XMFLOAT3 position = { 0,-20,0 };
	XMFLOAT4 color = { 1,1,1,1 };
	XMFLOAT3 scale = { 1,1,1 };
	XMMATRIX matWorld;
	//親オブジェクト
	Object3d* parent = nullptr;

	//クラス名(デバッグ用)
	const char* name = nullptr;
	//コライダー
	BaseCollider* collider = nullptr;
};

