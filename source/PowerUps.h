#include "Object.h"



class PowerUp : public Object
{

public:
	PowerUp(){}


	virtual void Update();
	virtual void CollideWithPlayer();
	virtual void CollideWithBullet();
	virtual void Change();
	virtual void Effect(Player* player) = 0;
};