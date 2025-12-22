#include "1000Points.h"

void Points::Update()
{
	Points::Effect();
	Object::Update();
}

bool Points::CollideWithPlayer()
{
	return true;
}

void Points::Change()
{

}

void Points::Effect()
{
	*points += POINTS;
	std::cout << *points << std::endl;
}
