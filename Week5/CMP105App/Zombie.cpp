#include "Zombie.h"

Zombie::Zombie()
{
	int x = 0;
	for(int i = 0; i < 8; i++){
		walk.addFrame(sf::IntRect(0 + i*55, 0, 55, 108));
	}
	walk.setFrameSpeed(animationSpeed);
}

Zombie::~Zombie()
{
}

void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}
