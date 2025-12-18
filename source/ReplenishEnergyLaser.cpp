#include "ReplenishEnergyLaser.h"

void ReplenisherEnergyLaser::Update()
{

}

void ReplenisherEnergyLaser::CollideWithPlayer()
{
}

void ReplenisherEnergyLaser::CollideWithBullet()
{
}

void ReplenisherEnergyLaser::Change()
{
}

void ReplenisherEnergyLaser::Effect(Player* player)
{
	player->energyLaser = ENERGYLASERMAX;
}
