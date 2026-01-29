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
	}

	virtual void Render()
	{
		for (Object* o : _objects)
			o->Render();

		for (Object* u : _ui)
			u->Render();
	}
};