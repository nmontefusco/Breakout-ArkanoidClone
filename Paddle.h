#pragma once
#include <SFML/Graphics.hpp>




/*Simliar to the ball, our paddle class will represent a game object
  with its own 'update' and 'draw' methods. */

class Paddle
{

public:
	static constexpr unsigned int wndHeight{ 600 }, wndWidth{ 800 };
	static const sf::Color defColor;
	static constexpr float defWidth{ 60.f };
	static constexpr float defHeight{ 20.f };
	static constexpr float defVelocity{ 8.f };

	sf::RectangleShape shape;
	sf::Vector2f velocity;

	
	Paddle(float mX, float mY);
	~Paddle();

	void update();
	void draw(sf::RenderWindow& mTarget);

	float x() const noexcept { return shape.getPosition().x; }
	float y() const noexcept { return shape.getPosition().y; }
	float width() const noexcept { return shape.getSize().x; }
	float height() const noexcept { return shape.getSize().y; }
	float left() const noexcept { return x() - width() / 2.f; }
	float right() const noexcept { return x() + width() / 2.f; }
	float top() const noexcept { return y() - height() / 2.f; }
	float bottom() const noexcept { return y() + height() / 2.f; }

	private:
		
		void processPlayerInput();
};

