#pragma once
#include "Framework\GameObject.h"
#include "Framework\Animation.h"
class Zombie : public GameObject
{

	float animationSpeed = 0.1f;
	Animation walk;

public:
	Zombie();
	~Zombie();

	void update(float dt) override;

};

