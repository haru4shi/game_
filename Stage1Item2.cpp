#include "Stage1Item2.h"
#include"SphereCollider.h"
#include"Input.h"

using namespace DirectX;

Stage1Item2* Stage1Item2::Create(int window_width, int window_height)
{
    //�C���X�^���X����
    Stage1Item2* stage1Item2 = new Stage1Item2();

    //������
    stage1Item2->Initialize(window_width, window_height);

    //�����ʒu
    XMFLOAT3 position = stage1Item2->GetPosition();
    position.x = -40;
    position.y = 10;
    stage1Item2->SetPosition(position);

    return stage1Item2;
}

void Stage1Item2::Initialize(int window_width, int window_height)
{
    Stage1Item1::Initialize(window_width, window_height);
    //�R���C�_�[�ǉ�
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
