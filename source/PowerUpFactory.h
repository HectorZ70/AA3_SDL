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

	PowerUp* CreatePowerup(Vector2 position, int id)
	{
		PowerUp* powerUp;
		switch (id)
		{
		case ADDPOINTS:
			powerUp = new Points(position);
			break;
		case REPLENISHSHIELD:
			powerUp = new ReplenisherShield(position);
			break;
		case REPLENISHLASER:
			powerUp = new ReplenisherEnergyLaser(position);
			break;
		case REPLENISHCANNON:
			powerUp = new ReplenisherEnergyCannon(position);
			break;
		case INCREASEVELOCITY:
			powerUp = new IncreaseVelocity(position);
			break;
		case TURRETWTINS:
			// We need to finish Turret twins

		}
		return powerUp;
	}
};