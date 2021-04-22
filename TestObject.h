#pragma once
#include"Object3d.h"
class TestObject:public Object3d
{
public:
	static TestObject* Create(int window_width, int window_height);

	void Initialize(int window_width, int window_height) override;

	void Update() override;

	void OnCollision(const CollisionInfo& info) override;
};

