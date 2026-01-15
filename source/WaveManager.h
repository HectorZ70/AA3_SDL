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


class WaveManager 
{
	int numberOfWave;
	int anteriorWave;
	std::vector<Enemy*> enemies;

public:
	WaveManager(int waveNumberStart) { numberOfWave = waveNumberStart; anteriorWave = waveNumberStart - 1; }

	std::vector<Enemy*>& GetEnemyWave() { return enemies; }

	int WaveSize() { return enemies.size(); }

	void UpdateNumberOfWave()
	{

		switch (numberOfWave)
		{
		case 1:
			if (anteriorWave != numberOfWave)
			{
				KillerWhale* chomper = new KillerWhale(100, 300, CELLING);
				VerticalMedusa* vMedusa = new VerticalMedusa(100, 400);
				HorizontalMedusa* hMedusa = new HorizontalMedusa(300, 400);

				enemies.push_back(chomper);
				enemies.push_back(vMedusa);
				enemies.push_back(hMedusa);
				anteriorWave = numberOfWave;
			}
			anteriorWave = numberOfWave;
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		}
	}
};