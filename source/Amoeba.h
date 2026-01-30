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
		_type = ObjectType::ENEMY;

		std::string texturePath = "resources/image.png";
		Vector2 size = { 1000, 1000 };
		Vector2 offset = { 0, 0 };

		_renderer = new ImageRenderer(_transform, texturePath, offset, size);

		_transform->position = { posX, posY };
		_transform->scale = Vector2(.5f, .5f);
		_transform->rotation = 0.f;

		_physics->AddCollider(new AABB(
			_transform->position,
			_transform->size * _transform->scale
		));

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