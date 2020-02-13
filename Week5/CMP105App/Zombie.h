#pragma once
#include "Framework\GameObject.h"
#include "Framework\Animation.h"
class Zombie : public GameObject
{

	float animationSpeed = 0.1f;
	Animation walk;
	float movementSpeed = 600.0f;

public:
	Zombie();
	~Zombie();

	void handleInput(float dt) override;
	void update(float dt) override;
	

};

