#include "PowerUpFactory.h"
#include <cstdlib>
#include <ctime>

PowerUp* PowerUpFactory::CreatePowerup()
{
	PowerUp* powerUp = nullptr;
	switch (idPowerUp)
	{
	case ADDPOINTS:
		powerUp = new Points(pos, playerScore);
		break;
	case REPLENISHSHIELD:
		powerUp = new ReplenisherShield(pos, shield);
		break;
	case REPLENISHLASER:
		powerUp = new ReplenisherEnergyLaser(pos, laser);
		break;
	case REPLENISHCANNON:
		powerUp = new ReplenisherEnergyCannon(pos, cannon);
		break;
	case INCREASEVELOCITY:
		powerUp = new IncreaseVelocity(pos, velocity);
		break;
	case TURRETWTINS:
		// We need to finish Turret twins
		break;
	}
	return powerUp;
}

void PowerUpFactory::Update()
{
	PowerUpFactory::CreatePowerup();
	Object::Update();
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
		newPowerUp = new Points(powerUp->GetPosition(), &player->GetScore());
		break;
	case REPLENISHSHIELD:
		newPowerUp = new ReplenisherShield(powerUp->GetPosition(), &player->GetShield());
		break;
	case REPLENISHLASER:
		newPowerUp = new ReplenisherEnergyLaser(powerUp->GetPosition(), &player->GetEnergyLaserAmmunation());
		break;
	case REPLENISHCANNON:
		newPowerUp = new ReplenisherEnergyCannon(powerUp->GetPosition(), &player->GetEnergyCannonAmmunation());
		break;
	case INCREASEVELOCITY:
		newPowerUp = new IncreaseVelocity(powerUp->GetPosition(), &player->GetVelocity());
		break;
	case TURRETWTINS:
		// We need to finish Turret twins
		break;

	}
	delete powerUp;
	powerUp = newPowerUp;
}
