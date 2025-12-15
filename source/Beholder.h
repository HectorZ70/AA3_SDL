#include "InputManager.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

enum class Start
{
	CELLING,
	FLOOR,
	NONE
};

class Beholder : public Enemy
{
	Start onFloor = Start::NONE;
	int xMod = (std::rand() % 2 == 0) ? -1 : 1;
	int yMod = (std::rand() % 2 == 0) ? -1 : 1;
	int numberOfFrames = 0;
	int limitOfFrames = 150;
	int forceX = 3;
	int forceY = 3;
public:

	Beholder(float posX, float posY) : Enemy()
	{
		std::srand(std::time(nullptr));
		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 ofsset = { 0, 0 };
		_transform = new Transform();
		_renderer = new ImageRenderer(_transform, texturePath, ofsset, size);
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = { posX, posY };
		_transform->scale = Vector2(0.5f, 0.5f);
		_transform->rotation = 0.f;

	}

	void Update() override;
	void Render() override;

	void Move() override;

};