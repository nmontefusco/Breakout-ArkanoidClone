#pragma once
#include <SFML\Graphics.hpp>

class Brick
{
public:
	
	static const sf::Color defColor;
	static constexpr float defWidth = 60.f;
	static constexpr float defHeight = 20.f;
	static constexpr float defVelocity = 8.f;
	
	sf::RectangleShape shape;
	
	bool Isdestroyed = false;

	Brick(float mX, float mY);
	~Brick();

	void update() {}

	void draw(sf::RenderWindow&mTarget);

	float x() const noexcept { return shape.getPosition().x; }
	float y() const noexcept { return shape.getPosition().y; }
	float width() const noexcept { return shape.getPosition().x; }
	float height() const noexcept { return shape.getSize().y; }
	float left() const noexcept { return x() - width() / 2.f; }
	float right() const noexcept { return x() + width() / 2.f; }
	float top()  const noexcept { return y() - height() / 2.f; }
	float bottom() const noexcept { return y() + height() / 2.f; }

};

