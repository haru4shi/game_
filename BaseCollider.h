#pragma once

#include"CollisionTypes.h"
#include"Object3d.h"


class BaseCollider
{
public:
	BaseCollider() = default;
	//���z�f�X�g���N�^
	virtual~BaseCollider() = default;

	inline void SetObject(Object3d* object)
	{
		this->object3d = object;
	}

	inline Object3d* GetObject3d()
	{
		return object3d;
	}

	//�X�V
	virtual void Update() = 0;
	//�`��^�C�v�擾
	inline CollisionShapeType GetShapeType()
	{
		return shapeType;
	}

protected:
	Object3d* object3d = nullptr;

	//�`��^�C�v
	CollisionShapeType shapeType = SHAPE_UNKNOWN;
};

