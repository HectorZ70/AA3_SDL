#include "ReplenishEnergyLaser.h"

void ReplenisherEnergyLaser::Update()
{

}

bool ReplenisherEnergyLaser::CollideWithPlayer()
{
	return true;
}

void ReplenisherEnergyLaser::Change()
{
}

void ReplenisherEnergyLaser::Effect(Player* player)
{
	player->energyLaser = ENERGYLASERMAX;
}
