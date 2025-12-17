#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

void Bullet::Update()
{
	_transform->position = { _transform->position.x + 20.f  ,_transform->position.y };

	if (Object::GetRigidBody()->CheckCollision(_physics))
	{
		Bullet::Destroy();
		std::cout << "is destroyed" << std::endl;
	}
	Object::Update();
}

void Bullet::Render()
{
	_renderer->Render();
}



