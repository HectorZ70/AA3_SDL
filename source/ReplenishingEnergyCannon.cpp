#include "ReplenishingEnergyCannon.h"

void ReplenisherEnergyCannon::Update()
{

}

bool ReplenisherEnergyCannon::CollideWithPlayer()
{
}

void ReplenisherEnergyCannon::Change()
{
}

void ReplenisherEnergyCannon::Effect(Player* player)
{
	player->energyCannon = ENERGYCANNONMAX;
}
