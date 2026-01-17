#pragma once
#include "Scene.h"
#include "Spawner.h"
#include "TextObject.h"
#include "Button.h"
#include "SceneManager.h"
#include "fstream"

#define FIRSTPOS 300.f
#define SECONDPOS 400.f
#define THIRDPOS 500.f

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

	bool newHighScore = false; //TODO: When we finish score and make a gameover we need to ask the player to type their name, we will activate this one variable with a xml
	//For debugging porpuses we let this newHighscore in true, but normally it will be false except when player makes a new Highscore

	TextObject* createHighScore(const std::string& name, int score, int yPos)
	{
		return new TextObject(
			name + " " + std::to_string(score),
			RM->WINDOW_WIDTH / 2,
			yPos
		);
	}


	void OnEnter() override
	{

		std::ifstream scoreFile("resources/ScoreMenu.xml");
		try {
			if (!scoreFile.is_open()) {
				//std::cerr << "Couldn't open the file or doesn't exist" << std::endl;
				throw std::exception("Unable to open ScoreMenu.xml");
			}
		}
		catch(std::exception e){
			std::cout << "Error: " << e.what();
		}

		std::string line;
		while (std::getline(scoreFile, line)) {
			std::cout << line << std::endl;
		}


		TextObject* trueHighScore1 = createHighScore(name1, highScore1, FIRSTPOS);
		TextObject* trueHighScore2 = createHighScore(name2, highScore2, SECONDPOS);
		TextObject* trueHighScore3 = createHighScore(name3, highScore3, THIRDPOS);

		TextObject* text = new TextObject("HIGHSCORE", RM->WINDOW_WIDTH/2, 100.f);
		if (newHighScore)
		{
			std::string name;
			int score;
			std::cin >> name;
			std::cin >> score;

			if (score > highScore1)
			{
				trueHighScore1 = createHighScore(name, score, FIRSTPOS);
			}
			else if (score > highScore2)
			{
				trueHighScore2 = createHighScore(name, score, SECONDPOS);
			}
			else if (score > highScore3)
			{
				trueHighScore3 = createHighScore(name, score, THIRDPOS);
			}
		}

		Button* returnToMainMenu = new Button([]()
			{
				SM.SetNextScene("MainMenu");

			},
			RM->WINDOW_WIDTH/2,
			900.0f
		);
		TextObject* buttonText = new TextObject("Return", RM->WINDOW_WIDTH / 2, 900.f);

		_ui.push_back(text);
		_ui.push_back(trueHighScore1);
		_ui.push_back(trueHighScore2);
		_ui.push_back(trueHighScore3);
		_ui.push_back(returnToMainMenu);
		_ui.push_back(buttonText);

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