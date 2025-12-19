#include "ReplenishEnergyLaser.h"

void ReplenisherEnergyLaser::Update()
{

}

bool ReplenisherEnergyLaser::CollideWithPlayer()
{
}

bool ReplenisherEnergyLaser::CollideWithBullet()
{
}

void ReplenisherEnergyLaser::Change()
{
}

void ReplenisherEnergyLaser::Effect(Player* player)
{
	player->energyLaser = ENERGYLASERMAX;
}
