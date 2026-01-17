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
#include "BioTitan.h"
#include "Spawner.h"
#include <thread>
#include <chrono>
#include <fstream>

#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"

class WaveManager 
{
	int numberOfWave;
	int anteriorWave;
	std::vector<Enemy*> enemies;
	rapidxml::xml_document<> wave;
	std::ifstream file;
	std::string xmlContent;

public:
	WaveManager(int waveNumberStart) 
	{	
		numberOfWave = waveNumberStart;
		anteriorWave = waveNumberStart - 1; 
		std::ifstream file("resources/Waves.xml");
		try
		{
			if (!file.is_open()) {
				throw std::exception("Unable to open Waves.xml");
			}
		}
		catch(std::exception c)
		{
			std::cout << "Error: " << c.what() << std::endl;
		}

		xmlContent.assign((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());

		wave.parse<0>(&xmlContent[0]);
	}

	std::vector<Enemy*>& GetEnemyWave() { return enemies; }

	int WaveSize() { return enemies.size(); }

	void SpawnWave()
	{
		std::thread waveThread([this]() {
			std::this_thread::sleep_for(std::chrono::seconds(3));
			UpdateNumberOfWave();
			});
		waveThread.detach();
	}

	void CleanEnemies()
	{
		for (Enemy* e : enemies) {
			delete e;
		}
		enemies.clear();
	}

	void UpdateNumberOfWave()
	{
		
		rapidxml::xml_node<>* rootNode = wave.first_node("waves");
		if (!rootNode) return;

		for (rapidxml::xml_node<>* waveNode = rootNode->first_node("wave");
			waveNode;
			waveNode = waveNode->next_sibling("wave"))
		{
			if (std::stoi(waveNode->first_attribute("number")->value()) == numberOfWave) {
				SpawnEnemiesFromWave(waveNode);
				break;
			}
		}

		numberOfWave++;
	}

	void SpawnEnemiesFromWave(rapidxml::xml_node<>* waveNode) {
		for (rapidxml::xml_node<>* enemyNode = waveNode->first_node("Enemy");
			enemyNode;
			enemyNode = enemyNode->next_sibling("Enemy"))
		{
			std::string type = enemyNode->first_attribute("type")->value();
			int x = std::stoi(enemyNode->first_attribute("x")->value());
			int y = std::stoi(enemyNode->first_attribute("y")->value());

			Enemy* e = nullptr;

			if (type == "KillerWhale")
				e = new KillerWhale(x, y, CELLING);
			else if (type == "VerticalMedusa")
				e = new VerticalMedusa(x, y);
			else if (type == "HorizontalMedusa")
				e = new HorizontalMedusa(x, y);
			else if (type == "Beholder")
				e = new Beholder(x, y);
			else if (type == "Circler")
				e = new Circler(x, y);
			else if (type == "Bubble")
				e = new Bubble(x, y);
			else if (type == "BioTitan")
				e = new BioTitan();
			//TODO: Figure out why the boss aparently breaks the game

			if (e) enemies.push_back(e);
		}
	}
};