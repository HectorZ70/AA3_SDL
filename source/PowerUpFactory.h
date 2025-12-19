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

class PowerUpFactory
{
	PowerUpFactory();

	PowerUp* CreatePowerup(Vector2 position, int id);

	void ChangePowerUp(PowerUp* powerUp);
};