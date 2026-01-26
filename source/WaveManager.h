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
#include <sstream>

#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"

class Wave
{
	std::vector<Enemy*> enemies;
public:
	void PushNewEnemy(Enemy* enemy)
	{
		enemies.push_back(enemy);
	}

	void SpawnWave()
	{
		for (int i = 0; i < enemies.size(); i++)
		{

		}
	}

	~Wave()
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}
};

struct enemyWave
{
	Enemy* enemy;
};

class WaveManager
{
	std::ifstream file;
	std::stringstream buffer;
	std::vector<Wave*> waves;
	
public:
	WaveManager()
	{
		file.open("resources/Waves.xml");

		try
		{
			if (!file.is_open()) {
				throw std::exception("Unable to open Waves.xml");
			}
		}
		catch (std::exception c)
		{
			std::cout << "Error: " << c.what() << std::endl;
		}

		buffer << file.rdbuf();
		file.close();

		// --- Parsear XML ---
		std::string content = buffer.str();
		std::vector<char> xml_copy(content.begin(), content.end());
		xml_copy.push_back('\0'); // RapidXML necesita null-terminated

		rapidxml::xml_document<> doc;
		doc.parse<0>(&xml_copy[0]);

		rapidxml::xml_node<>* root = doc.first_node("waves");
		if (!root) return;

		for (rapidxml::xml_node<>* waveNode = root->first_node("wave"); waveNode; waveNode = waveNode->next_sibling("wave"))
		{
			Wave* wave = new Wave();

			for (rapidxml::xml_node<>* enemyNode = waveNode->first_node("Enemy"); enemyNode; enemyNode = enemyNode->next_sibling("Enemy"))
			{
				std::string type = enemyNode->first_attribute("type")->value();
				int x = std::stoi(enemyNode->first_attribute("x")->value());
				int y = std::stoi(enemyNode->first_attribute("y")->value());

				Enemy* enemy = nullptr;

				if (type == "VerticalMedusa") enemy = new VerticalMedusa(x, y);
				else if (type == "HorizontalMedusa") enemy = new HorizontalMedusa(x, y);
				else if (type == "Circler") enemy = new Circler(x, y);
				else if (type == "Beholder") enemy = new Beholder(x, y);
				else if (type == "Chomper") enemy = new Chomper(x, y);
				else if (type == "Bubble") enemy = new Bubble(x, y);
				else if (type == "KillerWhale") {
					// Leer atributo opcional "start"
					StartState startState = StartState::CELLING;

					if (auto attr = enemyNode->first_attribute("start")) {
						std::string val = attr->value(); // obtener el string
						if (val == "CELLING") startState = StartState::CELLING;
						else if (val == "FLOOR") startState = StartState::FLOOR;

						enemy = new KillerWhale(x, y, startState);
					}
					else if (type == "Amoeba") {
						// Leer atributos opcionales
						bool isCopy = false;
						float offsetX = 0.0f;
						float offsetY = 0.0f;

						if (auto attr = enemyNode->first_attribute("copy")) {
							std::string val = attr->value();
							isCopy = (val == "true");
						}
						if (auto attr = enemyNode->first_attribute("offsetX")) offsetX = std::stof(attr->value());
						if (auto attr = enemyNode->first_attribute("offsetY")) offsetY = std::stof(attr->value());

						enemy = new Amoeba(x, y, isCopy, offsetX, offsetY);
					}
					else if (type == "VerticalMedusa") enemy = new VerticalMedusa(x, y);
					//else if (type == "BioTitan") enemy = new BioTitan(x, y);

					if (enemy)
						wave->PushNewEnemy(enemy);
				}

				waves.push_back(wave);
			}
		}
	}


};