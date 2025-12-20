#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "TestObject.h"
#include "Enemy.h"
#include "Circler.h"
#include "Background.h"
#include "HorizontalMedusa.h"
#include "VerticalMedusa.h"
#include "KillerWhale.h"
#include "Beholder.h"
#include "Amoeba.h"
#include "Chomper.h"
#include "Bubble.h"
#include "Turrets.h"


class Gameplay : public Scene
{
	std::vector<Chomper*> chompers;

public:
	Gameplay() = default;
	void OnEnter() override
	{

		for (int i = 0; i < 8; i++)
		{
			Chomper* chomper = new Chomper(1000, 500 + i * 50.f);
			chompers.push_back(chomper);
			SPAWNER.SpawnObject(chomper);
		}
		Bubble* bubble = new Bubble(1024, 300);
		Amoeba* amoeba = new Amoeba(0, 100, false, 0, 0);
		Background* backgroundUp = new Background(RM->WINDOW_HEIGHT);
		Background* backgroundDown = new Background(0);
		Player* player = new Player;
		Turret* turretsUp = new Turret(&player->GetPosition(), PositionRelative::UP);
		Turret* turretsDown = new Turret(&player->GetPosition(), PositionRelative::DOWN);

		SPAWNER.SpawnObject(backgroundUp);
		SPAWNER.SpawnObject(backgroundDown);
		SPAWNER.SpawnObject(bubble);
		SPAWNER.SpawnObject(player);
		SPAWNER.SpawnObject(turretsUp);
		SPAWNER.SpawnObject(turretsDown);

		backgroundUp->Render();
		backgroundDown->Render();
		bubble->Render();
		turretsUp->Render();
		turretsDown->Render();
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};