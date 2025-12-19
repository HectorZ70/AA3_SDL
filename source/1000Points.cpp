#include "1000Points.h"

void Points::Update()
{
}

bool Points::CollideWithPlayer()
{
}

bool Points::CollideWithBullet()
{
}

void Points::Change()
{

}

void Points::Effect(Player* player)
{
	player->IncreaseScore(points);
}
