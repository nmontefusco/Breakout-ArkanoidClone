
#include <SFML/Graphics.hpp>




class Ball
{
	
public:
	
	//constants for default values
	static constexpr unsigned int wndHeight{ 600 }, wndWidth{ 800 };
	static const sf::Color defColor;
	static constexpr float defRadius{ 10.0f };
	static constexpr float defVelocity{ 8.0f };
	
	//this is an sfml class that represents a circle shape.
	//we specify a radius and position to draw it
	
	sf::CircleShape shape;

	//We require a vector to store the current ball velocity.
	//it will be initilized with the default values
	
	sf::Vector2f velocity{ -defVelocity, -defVelocity };


	//Ball consturctor: it takes the starting position of ball as the parameters.
	
	Ball(float mX, float my);
	~Ball();

	//description in ball.cpp
	void update();
	void draw(sf::RenderWindow& mTarget);


	//We will need to get the ball's left/right/top/bottom bounds.
	//We define inline functions to help get some getters

	float x() const noexcept { return shape.getPosition().x; }
	float y() const noexcept { return shape.getPosition().y; }
	float left() const noexcept { return x() - shape.getRadius(); }
	float right() const noexcept { return x() + shape.getRadius(); }
	float top() const noexcept { return y() - shape.getRadius(); }
	float bottom() const noexcept { return y() + shape.getRadius(); }

private:

	void solveBoundCollisions();
};

