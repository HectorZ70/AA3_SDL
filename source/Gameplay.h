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

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		Beholder* beholder = new Beholder(1000, 100);
		KillerWhale* killerWhale = new KillerWhale(RM->WINDOW_WIDTH, RM->WINDOW_HEIGHT, FLOOR);
		Background* backgroundUp = new Background(RM->WINDOW_HEIGHT);
		Background* backgroundDown = new Background(0);
		Circler* enemy = new Circler(1000.f, 300.f);
		Player* player = new Player;

		SPAWNER.SpawnObject(backgroundUp);
		SPAWNER.SpawnObject(backgroundDown);
		SPAWNER.SpawnObject(beholder);
		SPAWNER.SpawnObject(killerWhale);
		SPAWNER.SpawnObject(enemy);
		SPAWNER.SpawnObject(player);

		backgroundUp->Render();
		backgroundDown->Render();
		beholder->Render();
		enemy->Render();
		player->Render();
		killerWhale->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};