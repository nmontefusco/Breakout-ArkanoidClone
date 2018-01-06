#include "ball.h"
#include "Paddle.h"
#include "Collision.h"

const sf::Color Ball::defColor{ sf::Color::Red };
const sf::Color Paddle::defColor{ sf::Color::Red };

constexpr unsigned int wndWidth{ 800 }, wndHeight{ 600 };

int main()
{ 
	//we create a window in the class sf::render window
	//the constructor requires a vector2(size of the window, and a string for title)
	Paddle paddle{ wndWidth / 2, wndHeight -50 };
	Ball ball{ wndWidth / 2.f,wndHeight / 2.f };
	sf::RenderWindow window{ {wndWidth,wndHeight},"Arkanoid -1" };
	
	//we set a frame rate to ensure game logic will run at constant speed.

	window.setFramerateLimit(60);
	
	//This loop will keep the window open.

	while (true)
	{

		//Every iteration of this loop is a frame. so we begin the loops by clearing the screen.
		//and then redrawing our graphics.

		window.clear(sf::Color::Black);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))break;

		ball.update();
		paddle.update();
		
		solvePaddleBallCollision(paddle,ball);
		
		ball.draw(window);
		paddle.draw(window);

		window.display();
	}
	
	return 0;
}
