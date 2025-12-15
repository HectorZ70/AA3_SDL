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

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		Amoeba* amoeba = new Amoeba(0, 100, false, 0, 0);
		Background* backgroundUp = new Background(RM->WINDOW_HEIGHT);
		Background* backgroundDown = new Background(0);
		Player* player = new Player;

		SPAWNER.SpawnObject(backgroundUp);
		SPAWNER.SpawnObject(backgroundDown);
		SPAWNER.SpawnObject(amoeba);
		SPAWNER.SpawnObject(player);

		backgroundUp->Render();
		backgroundDown->Render();
		amoeba->Render();
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};