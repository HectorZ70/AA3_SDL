#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "TestObject.h"
#include "Enemy.h"
#include "Background.h"


class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		Background* backgroundUp = new Background(RM->WINDOW_HEIGHT);
		Background* backgroundDown = new Background(0);
		Enemy* enemy = new Enemy(1000.f, 300.f);
		Player* player = new Player;

		SPAWNER.SpawnObject(backgroundUp);
		SPAWNER.SpawnObject(backgroundDown);
		SPAWNER.SpawnObject(enemy);
		SPAWNER.SpawnObject(player);

		backgroundUp->Render();
		backgroundDown->Render();
		enemy->Render();
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};