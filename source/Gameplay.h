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
		WaveManager* waveManager;
		std::vector<Enemy*> enemies;

		public:
		Gameplay() = default;
		void OnEnter() override
		{
			waveManager = new WaveManager(0);

			Player* player = new Player;
			SPAWNER.SpawnObject(player);
			player->Render();
		}

		void OnExit() { Scene::OnExit(); }

		void Update() { 
			Scene::Update();
			waveManager->SpawnWave();
			enemies = waveManager->GetEnemyWave();


			for (Enemy* enemy : enemies)
			{
				SPAWNER.SpawnObject(enemy);
				enemy->Render();
			}
		}

		void Render() override { Scene::Render(); }
	};