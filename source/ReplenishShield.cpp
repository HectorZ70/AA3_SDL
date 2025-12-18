#include "ReplenishShield.h"

void ReplenisherShield::Update()
{
}

void ReplenisherShield::CollideWithPlayer()
{
}

void ReplenisherShield::CollideWithBullet()
{
}

void ReplenisherShield::Change()
{
}

void ReplenisherShield::Effect(Player* player)
{
	player->shield = SHIELDMAX;
}
