#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Button.h"
#include "TextObject.h"

class MainMenu : public Scene
{
public:
	MainMenu() = default;

	void OnEnter() override
	{
		TextObject* text = new TextObject("PLAY", 400.f, 300.f);
		Button* playButton = new Button([]()
			{
				SM.SetNextScene("Gameplay");
			},
			400.0f, 
			300.0f 
		);
		_ui.push_back(playButton);
		_ui.push_back(text);


		TextObject* textSecond = new TextObject("SCORE", 400.f, 600.f);
		Button* optionsButton = new Button([]()
			{
				SM.SetNextScene("ScoreMenu");
			},
			400.0f,
			600.0f
		);
		_ui.push_back(optionsButton);
		_ui.push_back(textSecond);

		TextObject* textThird = new TextObject("EXIT", 400.f, 900.f);
		Button* exitButton = new Button([]()
			{
				//TODO: We need to find a way to close the game without any memory leaks!

			},
			400.0f,
			900.0f
		);
		_ui.push_back(exitButton);
		_ui.push_back(textThird);
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