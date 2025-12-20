#pragma once
#include "Object.h"

#define OFFSET 100
#define UNITSTRAVELLED 100

enum PositionRelative
{
	DOWN = 2,
	UP = 1,
	INVALID
};

class Turret : public Object
{
	Vector2* currentPlayerPosition = nullptr;
	Vector2 anteriorPlayerPosition;
	bool upDown;
public:
	Turret(Vector2* positionPlayer, PositionRelative upOrDown) : Object() //DO not pass by copy, it will break it
	{
		currentPlayerPosition = positionPlayer;
		anteriorPlayerPosition = *currentPlayerPosition;
		_transform->position = *currentPlayerPosition;
		upDown = upOrDown;
		if (upDown == DOWN)
		{
			_transform->position.y += OFFSET;
		}
		else if (upDown == UP)
		{
			_transform->position.y -= OFFSET;
		}
		
	}

	void Update() override;
	void MoveAlongside();
	void Rotate();
	void Shoot();
};