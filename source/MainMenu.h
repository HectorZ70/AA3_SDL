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
		Button* playButton = new Button([]()
			{
				SM.SetNextScene("Gameplay");

				TextObject* text = new TextObject("PLAY");
			},
			400.0f, 
			300.0f 
		);
		_ui.push_back(playButton);

		Button* optionsButton = new Button([]()
			{
				SM.SetNextScene("Gameplay");

				TextObject* text = new TextObject("OPTIONS");
			},
			400.0f,
			600.0f
		);
		_ui.push_back(optionsButton);

		Button* exitButton = new Button([]()
			{
				SM.SetNextScene("Gameplay");

				TextObject* text = new TextObject("EXIT");
			},
			400.0f,
			900.0f
		);
		_ui.push_back(exitButton);
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