#include "1000Points.h"

void Points::Change()
{

}

void Points::Effect(Player* player)
{
	player->IncreaseScore(points);
}
