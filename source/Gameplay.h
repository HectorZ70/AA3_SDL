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


class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		VerticalMedusa* verticalMedusa = new VerticalMedusa(100, RM->WINDOW_HEIGHT);
		HorizontalMedusa* horizontalMedusa = new HorizontalMedusa(1000, 100);
		Background* backgroundUp = new Background(RM->WINDOW_HEIGHT);
		Background* backgroundDown = new Background(0);
		Circler* enemy = new Circler(1000.f, 300.f);
		Player* player = new Player;

		SPAWNER.SpawnObject(backgroundUp);
		SPAWNER.SpawnObject(backgroundDown);
		SPAWNER.SpawnObject(verticalMedusa);
		SPAWNER.SpawnObject(horizontalMedusa);
		SPAWNER.SpawnObject(enemy);
		SPAWNER.SpawnObject(player);

		backgroundUp->Render();
		backgroundDown->Render();
		enemy->Render();
		player->Render();
		horizontalMedusa->Render();
		verticalMedusa->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};