#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

void Bullet::Update()
{
	// Usar RigidBody no transforms.
	_physics->AddForce({ 100.0f,0.0f });

	Object::Update();
}

void Bullet::Render()
{
	_renderer->Render();
}



