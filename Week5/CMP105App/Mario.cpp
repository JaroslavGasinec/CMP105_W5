#include "Mario.h"
#include <iostream>

Mario::Mario()
{
	current = selection[selectedAnimation];
	int x = 15;
	int y = 21;
		for (int i = 0; i < 4; i++) {
			selection[0]->addFrame(sf::IntRect(0 + i * x, 0, x, y));
		}
		selection[0]->setFrameSpeed(animationSpeed);

		x = 16;
		y = 20;
		for (int i = 0; i < 3; i++) {
			selection[1]->addFrame(sf::IntRect(0 + i * x, 21, x, y));
		}
		selection[1]->setFrameSpeed(animationSpeed);

		x = 16;
		y = 20;
		for (int i = 0; i < 2; i++) {
			selection[2]->addFrame(sf::IntRect(0 + i * x, 41, x, y));
		}
		selection[2]->setFrameSpeed(animationSpeed);
		current->animate(0);
		setTextureRect(current->getCurrentFrame());
}

Mario::~Mario()
{
}

void Mario::handleInput(float dt)
{
	
	velocity = sf::Vector2f(0.0f, 0.0f);
	if (isMoving && 
		!(input->isKeyDown(sf::Keyboard::Up)) &&
		!(input->isKeyDown(sf::Keyboard::Down)) &&
		!(input->isKeyDown(sf::Keyboard::Left)) &&
		!(input->isKeyDown(sf::Keyboard::Right))) 
	{
		isMoving = false;
		current->reset();
		setTextureRect(current->getCurrentFrame());
		
	}

	

	if (input->isKeyDown(sf::Keyboard::Up)) {
		isMoving = true;
		velocity += sf::Vector2f(0.0f, -movementSpeed);
	}
	if (input->isKeyDown(sf::Keyboard::Right)) {
		isMoving = true;
		current->setFlipped(false);
		velocity += sf::Vector2f(movementSpeed, 0.0f);
	}
	if (input->isKeyDown(sf::Keyboard::Down)) {
		isMoving = true;
		velocity += sf::Vector2f(0.0f, movementSpeed);
	}
	if (input->isKeyDown(sf::Keyboard::Left)) {
		isMoving = true;
		current->setFlipped(true);
		velocity += sf::Vector2f(-movementSpeed, 0.0f);
	}
	
	if (input->isKeyDown(sf::Keyboard::Space)) {
		input->setKeyUp(sf::Keyboard::Space);
		selectedAnimation++;
		selectedAnimation %= 3;
		current = selection[selectedAnimation];
	}
	velocity *= dt;
}

void Mario::update(float dt)
{
	if (isMoving) {
		current->animate(dt);
		setTextureRect(current->getCurrentFrame());
		setPosition(getPosition() + velocity);
	}
}
