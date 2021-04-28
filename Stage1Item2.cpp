#include "Stage1Item2.h"
#include"SphereCollider.h"
#include"Input.h"

using namespace DirectX;

Stage1Item2* Stage1Item2::Create(int window_width, int window_height)
{
    //インスタンス生成
    Stage1Item2* stage1Item2 = new Stage1Item2();

    //初期化
    stage1Item2->Initialize(window_width, window_height);

    //初期位置
    XMFLOAT3 position = stage1Item2->GetPosition();
    position.x = -40;
    position.y = 10;
    stage1Item2->SetPosition(position);

    return stage1Item2;
}

void Stage1Item2::Initialize(int window_width, int window_height)
{
    Stage1Item1::Initialize(window_width, window_height);
    //コライダー追加
    //float radius = 2;
    //SetCollider(new SphereCollider(XMVECTOR({ radius,radius,0,0 }), radius));
}

void Stage1Item2::Update()
{
    Input* input = Input::GetInstance();

    Stage1Item1::Update();
}

void Stage1Item2::OnCollision(const CollisionInfo& info)
{
}
