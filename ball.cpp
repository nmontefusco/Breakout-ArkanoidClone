#include "ball.h"



//Ball constructor: takes the starting position of
//ball as two float parameters.

Ball::Ball(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setRadius(defRadius);
	shape.setFillColor(defColor);
	shape.setOrigin(defRadius,defRadius);
}


Ball::~Ball()
{
}

//SFML's shape classes have a 'move' method that takes
//a velocity float vector as a parameter.
// The update method will update the game's logic


 void Ball::update()
{
	 shape.move(velocity);
	 solveBoundCollisions();
}

 //in the draw method we ask the window to draw the shape for us

 void Ball::draw(sf::RenderWindow& mTarget) 
 {
	 mTarget.draw(shape);
 }


 /* After the ball has moved, it may be out of bounds, We must check every direction and respond by changing the velocity.
 If it's leaving towards the left, we need to set horizontal velocity to a positive value(to the right)
 Otherwise if its leaving to the right, we need to set horizontal velocity to a negative value
 (towards the left)*/

 void Ball::solveBoundCollisions() 
 {
	 if (left() < 0)
	 {
		 velocity.x = defVelocity;
	 }
	 else if (right() > wndWidth)
	 {
		 velocity.x = -defVelocity;
	 }

	 //We apply the same collision principles to top/bottom

	 if (top() < 0)
	 {
		 velocity.y = defVelocity;
	 }
	 else if (bottom() > wndHeight)
	 {
		 velocity.y = -defVelocity;
	 }
 }
 