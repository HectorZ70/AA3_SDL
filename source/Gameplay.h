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
		for (Chomper* c : chompers)
		{
			c->Render();
		}
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};