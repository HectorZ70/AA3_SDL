#include "PowerUps.h"
#include "ReplenishEnergyLaser.h"
#include "1000Points.h"
#include "ReplenishingEnergyCannon.h"
#include "ReplenishShield.h"
#include "IncreaseValocity.h"
#include "SpawnTwinTurrets.h"


enum PowerUpType
{
	ADDPOINTS = 1,
	REPLENISHSHIELD = 2,
	REPLENISHLASER = 3,
	REPLENISHCANNON = 4,
	INCREASEVELOCITY = 5,
	TURRETWTINS = 6,
	INVALID

};

class PowerUpFactory : public Object
{
	bool hasBeenPlayed = false;
	Player* player = nullptr;
	Vector2 pos;
	int idPowerUp = 0;
	int* shield = nullptr;
	int* playerScore = nullptr;
	int* laser = nullptr;
	int* cannon = nullptr;
	float* velocity = nullptr;
public:
	PowerUpFactory(Vector2 position, int id, int* score, int* playerShield, int* laserAmmunation, int* cannonAmmunation, float* playerVelocity, Player* playerptr)
	{
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);

		pos = position;
		idPowerUp = id;
		playerScore = score;
		laser = laserAmmunation;
		cannon = cannonAmmunation;
		velocity = playerVelocity;
		player = playerptr;
	}

	PowerUp* CreatePowerup();
	void Update() override;

	void ChangePowerUp(PowerUp* powerUp);
};