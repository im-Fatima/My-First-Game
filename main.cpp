#include <iostream>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>


class Game
{
public: 
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
private: 
	sf::RenderWindow myWindow;
	sf::RectangleShape myPlayer;
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	bool myIsMovingUp;
	bool myIsMovingDown;
	bool myIsMovingLeft;
	bool myIsMovingRight;

};

int main()
{
	Game game;
	game.run();

	return 0;
}




Game::Game()
:myWindow(sf::VideoMode(800, 600), "First Game")
, myIsMovingUp(false)
, myIsMovingDown(false)
, myIsMovingRight(false)
, myIsMovingLeft(false)
, myPlayer()

{
	

	myPlayer.setSize(sf::Vector2f(100, 50));

	//set initial position of the shape
	myPlayer.setPosition(100.f, 100.f);

	//Fills the color
	myPlayer.setFillColor(sf::Color::Red);

	
}

void Game::run()				//defines the run function
{
	while (myWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}

}


void Game::processEvents()		//Process all the events (basically all the input we get from te use)
{
	sf::Event event;
	while (myWindow.pollEvent(event))
	{
		switch (event.type)
		{

		case sf::Event::Closed:
			myWindow.close();
			break;

		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		}
	}
}

void Game::update()				//constantly updates the game
{
	sf::Vector2f movement(0.f, 0.f);
	
		if (myIsMovingUp)
			movement.y -= 1.f;
		if (myIsMovingDown)
			movement.y += 1.f;
		if (myIsMovingRight)
			movement.x += 1.f;
		if (myIsMovingLeft)
			movement.x -= 1.f;

		myPlayer.move(movement);

}

void Game::render()
{
	myWindow.clear();
	myWindow.draw(myPlayer);
	myWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)

{
	if (key == sf::Keyboard::W)
		myIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		myIsMovingDown = isPressed;
	else if (key == sf::Keyboard::D)
		myIsMovingRight = isPressed;
	else if (key == sf::Keyboard::A)
		myIsMovingLeft = isPressed;


}