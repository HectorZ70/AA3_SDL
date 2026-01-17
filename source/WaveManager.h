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
#include "Spawner.h"
#include <thread>
#include <chrono>


class WaveManager 
{
	int numberOfWave;
	int anteriorWave;
	std::vector<Enemy*> enemies;

public:
	WaveManager(int waveNumberStart) { numberOfWave = waveNumberStart; anteriorWave = waveNumberStart - 1; }

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
		
		switch (numberOfWave)
		{
		case 1:
			if (anteriorWave != numberOfWave)
			{
				KillerWhale* chomper = new KillerWhale(100, 300, CELLING);
				Circler* circler = new Circler(100, 400);

				enemies.push_back(chomper);
				enemies.push_back(circler);
				anteriorWave = numberOfWave;
			}
			anteriorWave = numberOfWave;
			break;
		case 2:
			if (anteriorWave != numberOfWave)
			{
				Beholder* beholder = new Beholder(100, 300);
				VerticalMedusa* vMedusa = new VerticalMedusa(700, 400);
				

				enemies.push_back(beholder);
				enemies.push_back(vMedusa);
				
				anteriorWave = numberOfWave;
			}
			anteriorWave = numberOfWave;
			break;
		case 3:

			break;
		case 4:

			break;
		}
		numberOfWave++;
	}
};