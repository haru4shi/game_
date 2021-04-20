#pragma once
#include"BaseCollider.h"
#include"CollisionPrimitive.h"

#include<DirectXMath.h>

class SphereCollider:public BaseCollider,public Sphere
{
private:
	using XMVECTOR = DirectX::XMVECTOR;
public:
	SphereCollider(XMVECTOR offset = { 0,0,0,0 }, float radius = 1.0f)
	: offset(offset),radius(radius)
	{
		//球をセット
		shapeType = COLLISIONSHAPE_SPHERE;
	}

	//更新
	void Update() override;

	inline void SetRadius(float radius) { this->radius = radius; }

private:
	//オブジェクトの中心からのオフセット
	XMVECTOR offset;
	//半径
	float radius;
};

