#pragma once
#include "CollisionPrimitive.h"

class Collision
{
public:
	static bool CheckSphere2Sphere(const Sphere& sphereA, const Sphere& sphereB, DirectX::XMVECTOR* inter = nullptr);

};

