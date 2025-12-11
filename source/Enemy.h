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


	Enemy(float posX, float posY) : Object()
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { posX, posY };
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 0.f;
		center = { posX, posY };
		oldPosY = posY;
		radius = 100.f;
		speed = 0.05f;
		angle = 0.f;
	}

	void Update() override;
	void Render() override;

	void MoveInCircles();
	void EnterInScene(int targetPosX);
	void ExitOutScene();

};
