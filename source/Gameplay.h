#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "Player.h"
#include "Enemy.h"
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
		waveManager = new WaveManager();
		Border* borderUp = new Border(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT);
		Border* borderUp2 = new Border(RM->WINDOW_WIDTH * 1.5f, RM->WINDOW_HEIGHT);
		Border* borderDown = new Border(RM->WINDOW_WIDTH / 2.0f, 0);
		Border* borderDown2 = new Border(RM->WINDOW_WIDTH * 1.5f, 0);
		Background* background = new Background(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);
		Background* background2 = new Background(RM->WINDOW_WIDTH * 1.5f, RM->WINDOW_HEIGHT / 2.0f);
		Player* player = new Player;
		background->SetBackground(background2);
		background2->SetBackground(background);

		borderUp->SetBorders(borderUp2);
		borderUp2->SetBorders(borderUp);

		borderDown->SetBorders(borderDown2);
		borderDown2->SetBorders(borderDown);
		SPAWNER.SpawnObject(background);
		SPAWNER.SpawnObject(background2);
		SPAWNER.SpawnObject(borderUp);
		SPAWNER.SpawnObject(borderUp2);
		SPAWNER.SpawnObject(borderDown);
		SPAWNER.SpawnObject(borderDown2);

		SPAWNER.SpawnObject(player);


		borderUp->Render();
		borderDown->Render();
		background->Render();
		background2->Render();
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() {
		Scene::Update();



		for (Enemy* enemy : enemies)
		{
			SPAWNER.SpawnObject(enemy);
			enemy->Render();
		}
	}

	void Render() override { Scene::Render(); }
};