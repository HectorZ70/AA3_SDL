#include "1000Points.h"

void Points::Update()
{
	
}

bool Points::CollideWithPlayer()
{
	return true;
}

void Points::Change()
{

}

void Points::Effect(Player* player)
{
	player->IncreaseScore(points);
}
