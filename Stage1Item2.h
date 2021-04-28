#pragma once
#include"Stage1Item1.h"
class Stage1Item2:public Stage1Item1
{
public:
	static Stage1Item2* Create(int window_width, int window_height);

	void Initialize(int window_width, int window_height) override;

	void Update() override;

	void OnCollision(const CollisionInfo& info) override;
};

