#include "Brick.h"


Brick::Brick(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setSize({ defWidth,defHeight });
	shape.setFillColor(defColor);
	shape.setOrigin({ defWidth / 2.f, defHeight /2.f });
}

Brick::~Brick()
{
}

void Brick::draw(sf::RenderWindow& mTarget)
{
	mTarget.draw(shape);
}
