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
#include "1000Points.h"
#include "ReplenishShield.h"
#include "IncreaseValocity.h"
#include "PowerUpFactory.h"

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
		PowerUpFactory* powerUp = new PowerUpFactory({100, 200}, 6, &player->GetScore(), &player->GetShield(), &player->GetEnergyLaserAmmunation(), &player->GetEnergyCannonAmmunation(), &player->GetVelocity(), player);

		SPAWNER.SpawnObject(powerUp->CreatePowerup());
		SPAWNER.SpawnObject(backgroundUp);
		SPAWNER.SpawnObject(backgroundDown);
		SPAWNER.SpawnObject(player);


		backgroundUp->Render();
		backgroundDown->Render();
		player->Render();
	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};