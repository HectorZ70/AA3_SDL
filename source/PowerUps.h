#pragma once
#include "Object.h"
#include "Vector2.h"
#include "TestObject.h"


class PowerUp : public Object
{
	bool change = false;
public:
	PowerUp()
	{
	}


	virtual void Update() = 0;
	virtual bool CollideWithPlayer() = 0;
	virtual bool CollideWithBullet() = 0;
	virtual void Change() = 0;
	virtual void Effect(Player* player) = 0;
	Vector2 GetPosition()
	{
		return _transform->position;
	}
};