#pragma once
#include "ImageObject.h"
#include "RigidBody.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ImageRenderer.h"

#define PLAYERDOWN 1
#define PLAYERUP 2
#define PLAYERRIGHT 3
#define PLAYERLEFT 0
#define PLAYERVELOCITY 20.0f

class Bullet : public ImageObject
{
	int directionBullet;
public:
	std::string texturePath = "resources/image.png";
	Vector2 size = { 65, 65 };
	Vector2 offset = { 0, 0 };
	Bullet(Vector2 playerPosition, int direction) : ImageObject(texturePath, size, offset)
	{
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, size, offset);
		_physics = new RigidBody(_transform);
		_type = ObjectType::BULLET;
		
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { playerPosition };
		_transform->scale = Vector2(0.1f, 0.1f);
		_transform->rotation = 0.f;
		directionBullet = direction;

		_physics->AddCollider(new AABB(
			_transform->position,
			_transform->size * _transform->scale
		));

		_physics->SetVelocity({ 1000.0f, 0.0f });
	}
	
	void Update() override;
	void Render() override;
	virtual void OnCollision(Object* other);
};
