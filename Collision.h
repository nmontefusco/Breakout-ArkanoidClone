#pragma once

/* 
	We define a template to detect when two game objects collide, the reference types are for 
	the member of left,right,top,bottom, making it accessible for ball and paddle to use.
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
