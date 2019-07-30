#include "window.h"
#include "shapeContainer.h"

MyWindow::MyWindow() : sf::RenderWindow(sf::VideoMode(800, 600), "My window")
{
	setVerticalSyncEnabled(true);
}

MyWindow::~MyWindow()
{
}

void MyWindow::handleEvent(sf::Event& _event)
{
	switch(_event.type)
	{
		case sf::Event::Closed:
			close();
			break;
			
		case sf::Event::KeyPressed:
			switch(_event.key.code)
			{
				case sf::Keyboard::Escape:
					close();
					break;
				default:
					break;
			}
			break;
		
		default:
			;// no handling for now;
	}
}

void MyWindow::play(ShapeContainer& _container)
{
	while (isOpen())
    {
		sf::Event event;                
		while (pollEvent(event))
		{
			handleEvent(event);
			_container.handleEvent(event);
		}
		
		clear(sf::Color::Transparent);
		
		_container.draw(*this);
		_container.moveItem();
		_container.collisionManager();

		display();
		
		//_container.getStatus()
	}
}
