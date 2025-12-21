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
#include "Laser.h"
#include "Cannons.h"


class Gameplay : public Scene
{
	std::vector<Chomper*> chompers;

public:
	Gameplay() = default;
	void OnEnter() override
	{
		Background* backgroundUp = new Background(RM->WINDOW_HEIGHT);
		Background* backgroundDown = new Background(0);
		Player* player = new Player;
		Turret* turretsUp = new Turret(&player->GetPosition(), PositionRelative::UP);
		Turret* turretsDown = new Turret(&player->GetPosition(), PositionRelative::DOWN);
		Laser* laser = new Laser(&player->GetPosition(), &player->GetEnergyLaserAmmunation());
		Cannon* cannon = new Cannon(&player->GetPosition(), &player->GetEnergyCannonAmmunation());

		SPAWNER.SpawnObject(backgroundUp);
		SPAWNER.SpawnObject(backgroundDown);
		SPAWNER.SpawnObject(player);
		SPAWNER.SpawnObject(turretsUp);
		SPAWNER.SpawnObject(turretsDown);
		SPAWNER.SpawnObject(laser);
		SPAWNER.SpawnObject(cannon);

		backgroundUp->Render();
		backgroundDown->Render();
		turretsUp->Render();
		turretsDown->Render();
		player->Render();
		laser->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};