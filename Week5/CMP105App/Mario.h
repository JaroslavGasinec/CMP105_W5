#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Mario :
	public GameObject
{
public:
	Mario();
	~Mario();
	void handleInput(float dt) override;
	void update(float dt) override;

private:
	Animation walk;
	Animation swim;
	Animation duck;
	Animation* selection[3]{&walk,&swim,&duck};
	Animation* current;
	float animationSpeed = 0.2f;
	float movementSpeed = 600.0f;
	int selectedAnimation = 0;


};

