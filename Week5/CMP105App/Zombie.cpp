#include "Zombie.h"

Zombie::Zombie()
{
	int x = 55;
	for(int i = 0; i < 8; i++){
		walk.addFrame(sf::IntRect(0 + i*x, 0, 55, 108));
	}
	walk.setFrameSpeed(animationSpeed);
}

Zombie::~Zombie()
{
}

void Zombie::handleInput(float dt)
{
	velocity = sf::Vector2f(0.0f,0.0f);
	if (input->isKeyDown(sf::Keyboard::W)) {
		velocity += sf::Vector2f(0.0f,-movementSpeed);
		input->setKeyUp(sf::Keyboard::W);
	}
	if (input->isKeyDown(sf::Keyboard::D)) {
		walk.setFlipped(false);
		velocity += sf::Vector2f(movementSpeed, 0.0f);
		input->setKeyUp(sf::Keyboard::D);
	}
	if (input->isKeyDown(sf::Keyboard::S)) {
		velocity += sf::Vector2f(0.0f,movementSpeed);
		input->setKeyUp(sf::Keyboard::S);
	}
	if (input->isKeyDown(sf::Keyboard::A)) {
		walk.setFlipped(true);
		velocity += sf::Vector2f(-movementSpeed, 0.0f);
		input->setKeyUp(sf::Keyboard::A);
	}
	velocity *= dt;
}

void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
	setPosition(getPosition() + velocity);
}