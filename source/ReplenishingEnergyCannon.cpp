#include "ReplenishingEnergyCannon.h"

void ReplenisherEnergyCannon::Update()
{

}

bool ReplenisherEnergyCannon::CollideWithPlayer()
{
}

bool ReplenisherEnergyCannon::CollideWithBullet()
{
}

void ReplenisherEnergyCannon::Change()
{
}

void ReplenisherEnergyCannon::Effect(Player* player)
{
	player->energyCannon = ENERGYCANNONMAX;
}
