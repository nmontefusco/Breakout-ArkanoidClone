#pragma once

/* 
	We define a template to detect when two game objects collide, the reference types are for 
	the member of left,right,top,bottom, making it practical for ball and paddle to use.
*/

	

template <typename T1, typename T2>
	bool isIntersecting(const T1& mA, const T2& mB) noexcept
	{
		return mA.right() >= mB.left() && mA.left() <= mB.right() &&
			mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
	}


	/*executed every game frame, this function will check if a paddle & ball are colliding,
    if they are it will resolve collision by making the ball go up in 
	the opposite direction of where its collided*/

	void solvePaddleBallCollision(const Paddle& mPaddle, Ball& mBall) noexcept
	{
		if (!isIntersecting(mPaddle, mBall))
		{
			return;
		}

		//upward direction

		mBall.velocity.y = -Ball::defVelocity;

		//if the ball's center is to the left of paddle's center, it will move left,
		//otherwise it will move right

		mBall.velocity.x = mBall.x() < mPaddle.x() ? -Ball::defVelocity : Ball::defVelocity;
	}

	/* We need to find out from what direction the ball hit the brick, and respond accordingly.
	*/
	void solveBrickBallCollision(Brick& mBrick, Ball& mBall) noexcept
	{
	
		if (!isIntersecting(mBrick, mBall))
		{
			return;
		}
		
		mBrick.Isdestroyed = true;

		float overlapLeft = mBall.right() - mBrick.left();
		float overlapRight = mBrick.right() - mBall.left();
		float overlapTop = mBall.bottom() - mBrick.top();
		float overlapBottom = mBrick.bottom() - mBall.top();

		// If  the left overlap is smaller than the
		// right  we can safely assume the ball hit the brick from the left.

		bool ballFromLeft(std::abs(overlapLeft) < std::abs(overlapRight));

		// We apply the same idea for top/bottom collisions.
		bool ballFromTop(std::abs(overlapTop) < std::abs(overlapBottom));

		//store the minimum overlaps for the X and Y axes.
		float minOverlapX = ballFromLeft ? overlapLeft : overlapRight ;
		float minOverlapY = ballFromTop ? overlapTop : overlapBottom ;
		
		//based on the response, we can simulate "realistic" reaction to collision
		if (std::abs(minOverlapX) < std::abs(minOverlapY))
		{
			mBall.velocity.x = ballFromLeft ? -Ball::defVelocity : Ball::defVelocity;
		}
		else
		{
			mBall.velocity.y = ballFromTop ? -Ball::defVelocity : Ball::defVelocity;
		}

	}

