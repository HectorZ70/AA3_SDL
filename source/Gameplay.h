#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "TestObject.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		Player* player = new Player;
		SPAWNER.SpawnObject(player);
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};