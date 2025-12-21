#include "PowerUps.h"
#include "TestObject.h"
#include "Spawner.h"
#include "TestObject.h"
#define POINTS 1000

class Points : public PowerUp
{
	int points;
public:

	Points(Vector2 position)
	{
		_transform->position = position;
		points = POINTS;
	}

	void Update() override;
	bool CollideWithPlayer() override;
	void Change() override;
	void Effect(Player* player) override;
};