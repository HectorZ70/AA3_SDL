#pragma once
#include "Scene.h"
#include "Bullet.h"
#include "Spawner.h"
#include "TextObject.h"
#include "TestObject.h"






class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		Bullet* bullet = new Bullet;
		Player* player = new Player;
		SPAWNER.SpawnObject(bullet);
		SPAWNER.SpawnObject(player);
		bullet->Render();
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};