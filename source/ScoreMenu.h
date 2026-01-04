#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "Button.h"
#include "SceneManager.h"

class ScoreMenu : public Scene
{
public:
	ScoreMenu() = default;
	std::string name1 = "Hector ";
	std::string name2 = "Gerard ";
	std::string name3 = "JIJIJIJA ";

	int highScore1 = 1093;
	int highScore2 = 570;
	int highScore3 = 15;

	std::string score1 = std::to_string(highScore1);
	std::string score2 = std::to_string(highScore2);
	std::string score3 = std::to_string(highScore3);

	void OnEnter() override
	{
		TextObject* text = new TextObject("SCORE", RM->WINDOW_WIDTH/2, 100.f);

		TextObject* highScore1 = new TextObject(name1 + score1, RM->WINDOW_WIDTH / 2, 300.f);
		TextObject* highScore2 = new TextObject(name2 + score2, RM->WINDOW_WIDTH / 2, 400.f);
		TextObject* highScore3 = new TextObject(name3 + score3, RM->WINDOW_WIDTH / 2, 500.f);

		_ui.push_back(text);
		_ui.push_back(highScore1);
		_ui.push_back(highScore2);
		_ui.push_back(highScore3);
	}

	void OnExit() override
	{
		Scene::OnExit();
	}

	void Update() override
	{
		Scene::Update();
	}

	void Render() override
	{
		Scene::Render();
	}
};