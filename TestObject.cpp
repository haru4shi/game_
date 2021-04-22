#include "TestObject.h"
#include"SphereCollider.h"
#include"Input.h"


using namespace DirectX;

TestObject* TestObject::Create(int window_width, int window_height)
{
    //�C���X�^���X����
    TestObject* testObject = new TestObject();

    //������
    testObject->Initialize(window_width, window_height);
    //�����ʒu
    XMFLOAT3 position = testObject->GetPosition();
    position = {0,-20,0};
    testObject->SetPosition(position);

    return testObject;
}

void TestObject::Initialize(int window_width, int window_height)
{
    Object3d::Initialize(window_width,window_height);
    //�R���C�_�[�ǉ�
    float radius = 2;
    SetCollider(new SphereCollider(XMVECTOR({ radius,radius,0,0 }), radius));
}

void TestObject::Update()
{
    Input* input = Input::GetInstance();

    Object3d::Update();
}

void TestObject::OnCollision(const CollisionInfo& info)
{
    position.y += 10;
}

