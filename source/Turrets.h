#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "ImageRenderer.h"
#include "InputManager.h"

#define OFFSET 50
#define UNITSTRAVELLED 100
#define ROTATION 45

enum class PositionRelative
{
	DOWN = 0,
	UP = 1,
	INVALID
};

enum class Rotation
{
	LEFT = 0,
	UP = 1,
	DOWN = 2,
	RIGHT = 3
};

class Turret : public Object
{
	Vector2* currentPlayerPosition = nullptr;
	Vector2 anteriorPlayerPosition;
	PositionRelative upDown;
	int rotation = 0;
public:
	Turret(Vector2* positionPlayer, PositionRelative upOrDown) : Object() //DO not pass by copy, it will break it
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 100, 100 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		_transform->scale = Vector2(0.3f, 0.3f);


		currentPlayerPosition = positionPlayer;
		anteriorPlayerPosition = *currentPlayerPosition;
		_transform->position = *currentPlayerPosition;
		_transform->rotation = 90;
		upDown = upOrDown;
		if (upDown == PositionRelative::DOWN)
		{
			_transform->position.y += OFFSET;
		}
		else if (upDown == PositionRelative::UP)
		{
			_transform->position.y -= OFFSET;
		}


		
	}

	void Update() override;
	void Render() override;
	void MoveAlongSide();
	void Rotate();
	void Shoot();
	int GetRotation();
};