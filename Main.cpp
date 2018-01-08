#include "ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Collision.h"

const sf::Color Ball::defColor{ sf::Color::Red };
const sf::Color Paddle::defColor{ sf::Color::Red };
const sf::Color Brick::defColor{ sf::Color::Yellow };

constexpr unsigned int wndWidth{ 800 }, wndHeight{ 600 };

int main()
{ 
	
	Paddle paddle{ wndWidth / 2, wndHeight -50 };
	Ball ball{ wndWidth / 2.f,wndHeight / 2.f };
	std::vector<Brick> bricks;
	
	constexpr int brkCountX = 11;  //Row Count
	constexpr int brkCountY = 4;   //Column Count
	constexpr int brkStartColumn = 1; //Index start for column
	constexpr int brkStartRow = 2;  //Index start for row

	constexpr float brkSpacing = 3.f;  //spacing between bricks
	constexpr float brkOffsetX = 22.f; // X off set for grid pattern
//we must populate our vector to create a grid pattern

	for(int iX=0; iX<brkCountX; ++iX)
		for  (int  iY= 0; iY < brkCountY; ++iY)
		{
			float x = (iX + brkStartColumn) * (Brick::defWidth + brkSpacing);
			float y = (iY + brkStartRow) * (Brick::defHeight + brkSpacing);

			bricks.emplace_back(brkOffsetX + x, y);
		}

	//we create a window in the class sf::render window
	//the constructor requires a vector2(size of the window, and a string for title)
	sf::RenderWindow window{ { wndWidth,wndHeight },"Arkanoid -1" };
	//we set a frame rate to ensure game logic will run at constant speed.

	window.setFramerateLimit(60);
	
	//This loop will keep the window open.

	while (true)
	{
		//Every iteration of this loop is a frame. so we begin the loops by clearing the screen.
		//and then redrawing our graphics.

		window.clear(sf::Color::Black);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))break;

		ball.update();
		paddle.update();

		for (auto& brick : bricks)
		{
			brick.update();
			solveBrickBallCollision(brick, ball);
		}

		

		bricks.erase(std::remove_if(std::begin(bricks),std::end(bricks),
			[](const auto& mBrick)
			{
				return mBrick.Isdestroyed;
			}),
			std::end(bricks)
			);

		solvePaddleBallCollision(paddle, ball);

		ball.draw(window);
		paddle.draw(window);

		for (auto& brick : bricks)
		{
			brick.draw(window);
		}

		window.display();
	}
	
	return 0;
}
