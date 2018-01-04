#include "Paddle.h"



/* as with the ball, we construct the paddle with the arguments for the
inital position and initialize the sfml rectangle shape*/

Paddle::Paddle(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setSize({defWidth, defHeight});
	shape.setFillColor(defColor);
	shape.setOrigin(defWidth / 2.f, defHeight / 2.f);
}


Paddle::~Paddle()
{
}

void Paddle::update()
{
	processPlayerInput();
	shape.move(velocity);
}

void Paddle::draw(sf::RenderWindow & mTarget)
{
	mTarget.draw(shape);
}

void Paddle::processPlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
	{
		velocity.x = -defVelocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < wndWidth)
	{
		velocity.x = defVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}
