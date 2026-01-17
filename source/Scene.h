#pragma once
#include "Spawner.h"
#include "Object.h"
#include "CollisionSystem.h"
#include <vector>


class Scene
{
protected:
	std::vector<Object*> _objects;
	std::vector<Object*> _ui;
	CollisionSystem _collisionSystem;

public:
	Scene() = default;
	virtual void OnEnter() = 0;

	virtual void OnExit()
	{
		SPAWNER.ClearSpawner();

		for (Object* o : _objects)
		{
			delete o;
		}

		_objects.clear();

		for (Object* u : _ui)
		{
			delete u;
		}

		_ui.clear();
	}

	virtual void Update()
	{
		//SPAWNING
		while (SPAWNER.AreObjectsPendingSpawn())
		{
			_objects.push_back(SPAWNER.GetSpawnedObject());
		}

		for (Object* o : _objects)
			o->Update();

		for (Object* u : _ui)
			u->Update();

		_collisionSystem.Update(_objects);

		/*
		int size = _objects.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < _objects.size(); j++)
			{
				if ((_objects[i]->GetType() == ObjectType::BULLET && _objects[j]->GetType() == ObjectType::BULLET)
					|| (_objects[i]->GetType() == ObjectType::ENEMY && _objects[j]->GetType() == ObjectType::ENEMY))
					continue;

				if (_objects[i]->GetRigidBody()->CheckCollision(_objects[j]->GetRigidBody()))
				{
					std::cout << "COLLISION\n";
					_objects[i]->Destroy();
					_objects[j]->Destroy();
				}
			}
		}

		size = _ui.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < _ui.size(); j++)
			{
				if (_ui[i]->GetRigidBody()->CheckCollision(_ui[j]->GetRigidBody()))
				{
					_ui[i]->Destroy();
					_ui[j]->Destroy();
				}
			}
		}

		for (int i = _ui.size() - 1; i >= 0; i--)
		{
			if (_ui[i]->IsPendingDestroy())
			{
				delete _ui[i];
				_ui.erase(_ui.begin() + i);
			}
		}

		for (int i = _objects.size() - 1; i >= 0; i--)
		{
			if (_objects[i]->IsPendingDestroy())
			{
				delete _objects[i];
				_objects.erase(_objects.begin() + i);
			}
		}
		*/
	}

	virtual void Render()
	{
		for (Object* o : _objects)
			o->Render();

		for (Object* u : _ui)
			u->Render();
	}
};