#include "Object.h"

Object::Object()
{
	_transform = new Transform();
	_physics = new RigidBody(_transform);
}

Object::~Object()
{
	delete _transform;
	delete _renderer;
	delete _physics;
}

void Object::Update()
{
	if (_physics != nullptr)
		_physics->Update(0.02f);

	_renderer->Update(0.02f);
}

RigidBody* Object::GetRigidBody()
{
	return _physics;
}

void Object::Render()
{
	_renderer->Render();
}

Transform* Object::GetTransform()
{
	return _transform;
}

bool Object::IsPendingDestroy() const
{
	return _isPendingDestroy;
}

void Object::Destroy()
{
	_isPendingDestroy = true;
}
