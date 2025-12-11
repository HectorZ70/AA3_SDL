#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "TestObject.h"
#include "Enemy.h"


class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{

		Enemy* enemy = new Enemy(1000.f, 300.f);
		Player* player = new Player;

		SPAWNER.SpawnObject(enemy);
		SPAWNER.SpawnObject(player);

		enemy->Render();
		player->Render();
	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};