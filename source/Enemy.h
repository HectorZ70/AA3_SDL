#pragma once
#include "Object.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ImageRenderer.h"

class Enemy : public Object
{
	bool finishEnter = false;
	bool finishCircle = false;
	int numberOfTimes = 0;
public:
	Vector2 center;
	float radius;
	float speed;
	float angle;

	float oldPosY;


	Enemy() : Object()
	{

	}

	virtual void Move() {}
	virtual void EnterInScene(int targetPosX) {}
	virtual void ExitOutScene() {}

};
