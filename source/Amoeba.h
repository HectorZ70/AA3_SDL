#include "InputManager.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>


class Amoeba : public Enemy
{
	int divideNumber = 8;
	bool copy = false;
	float distance = 0;
	bool finishCopy = false;
	bool finishStart = false;

	Vector2 center;
	float radius;
	float speed;
	float angle;

	float oldPosY;
	bool finishCircle = false;
	int numberOfTimes = 0;
public:

	Amoeba(float posX, float posY, bool isCopy, float offsetX, float offsetY) : Enemy()
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
		copy = isCopy;

		center = { posX, posY };
		oldPosY = posY;
		radius = 100.f;
		speed = 0.05f;
		angle = 0.f;
	}

	void Update() override;
	void Render() override;

	void Move() override;
	void CreateCopy();
	void StartingMove();
	void MoveInCircle();
	void FinishMove();
};