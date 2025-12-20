#include "ReplenishEnergyLaser.h"

void ReplenisherEnergyLaser::Update()
{

}

bool ReplenisherEnergyLaser::CollideWithPlayer()
{
}

void ReplenisherEnergyLaser::Change()
{
}

void ReplenisherEnergyLaser::Effect(Player* player)
{
	player->energyLaser = ENERGYLASERMAX;
}
