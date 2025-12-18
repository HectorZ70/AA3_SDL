#include "ReplenishingEnergyCannon.h"

void ReplenisherEnergyCannon::Update()
{

}

void ReplenisherEnergyCannon::CollideWithPlayer()
{
}

void ReplenisherEnergyCannon::CollideWithBullet()
{
}

void ReplenisherEnergyCannon::Change()
{
}

void ReplenisherEnergyCannon::Effect(Player* player)
{
	player->energyCannon = ENERGYCANNONMAX;
}
