#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "TestObject.h"
#include "Enemy.h"
#include "Circler.h"
#include "Borders.h"
#include "Background.h"
#include "HorizontalMedusa.h"
#include "VerticalMedusa.h"
#include "KillerWhale.h"
#include "Beholder.h"
#include "Amoeba.h"
#include "Chomper.h"
#include "Bubble.h"


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
		Border* borderUp = new Border(0, RM->WINDOW_HEIGHT);
		Border* borderDown = new Border(0,0);
		Background* backgroundMiddle = new Background(RM->WINDOW_WIDTH / 2.0f, RM->WINDOW_HEIGHT / 2.0f);
		Player* player = new Player;

		
		SPAWNER.SpawnObject(backgroundMiddle);
		SPAWNER.SpawnObject(borderUp);
		SPAWNER.SpawnObject(borderDown);
		SPAWNER.SpawnObject(bubble);
		SPAWNER.SpawnObject(player);

		borderUp->Render();
		borderDown->Render();
		backgroundMiddle->Render();
		bubble->Render();
		for (Chomper* c : chompers)
		{
			//c->Render();
		}
		player->Render();

	}

	void OnExit() { Scene::OnExit(); }

	void Update() { Scene::Update(); }

	void Render() override { Scene::Render(); }
};