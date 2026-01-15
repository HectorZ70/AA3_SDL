#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "PowerUpFactory.h"

#include "WaveManager.h"

class Gameplay : public Scene
{

public:
	Gameplay() = default;
	void OnEnter() override
	{

		WaveManager waveManager(1);
		std::vector<Enemy*> enemies;

		Player* player = new Player;
		SPAWNER.SpawnObject(player);
		player->Render();

		waveManager.UpdateNumberOfWave();
		enemies = waveManager.GetEnemyWave();


		for (Enemy* enemy : enemies)
		{
			SPAWNER.SpawnObject(enemy);
			enemy->Render();
		}

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};