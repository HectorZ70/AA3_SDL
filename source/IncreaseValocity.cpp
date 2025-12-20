#include "IncreaseValocity.h"

void IncreaseVelocity::Update()
{



}

bool IncreaseVelocity::CollideWithPlayer()
{
	return true;
}

void IncreaseVelocity::Change()
{
}

void IncreaseVelocity::Effect(Player* player)
{
	player->velocity += VELOCITY;
}
