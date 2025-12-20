#include "PowerUpFactory.h"
#include <cstdlib>
#include <ctime>

PowerUp* PowerUpFactory::CreatePowerup(Vector2 position, int id)
{
	PowerUp* powerUp = nullptr;
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
		break;
	}
	return powerUp;
}


//GameplayLogic, if it was hit by bullet this happens
void PowerUpFactory::ChangePowerUp(PowerUp* powerUp)
{
	std::srand(std::time(nullptr));
	int newId = std::rand() % 8 + 1;
	PowerUp* newPowerUp = nullptr;
	
	switch (newId)
	{
	case ADDPOINTS:
		newPowerUp = new Points(powerUp->GetPosition());
		break;
	case REPLENISHSHIELD:
		newPowerUp = new ReplenisherShield(powerUp->GetPosition());
		break;
	case REPLENISHLASER:
		newPowerUp = new ReplenisherEnergyLaser(powerUp->GetPosition());
		break;
	case REPLENISHCANNON:
		newPowerUp = new ReplenisherEnergyCannon(powerUp->GetPosition());
		break;
	case INCREASEVELOCITY:
		newPowerUp = new IncreaseVelocity(powerUp->GetPosition());
		break;
	case TURRETWTINS:
		// We need to finish Turret twins
		break;

	}
	delete powerUp;
	powerUp = newPowerUp;
}
