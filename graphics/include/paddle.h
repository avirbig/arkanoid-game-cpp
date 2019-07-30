#ifndef _PADDLE_H_
#define _PADDLE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "imove.h"
#include "idraw.h"
#include "ievent.h"
#include "icollide.h"
#include "window.h"

class Paddle : 	public IDraw,
				public IMove, 
				public IEvent,
				public ICollide,
				public sf::RectangleShape{
public:
	Paddle(sf::Vector2f& _screenDimensions);
	
	void draw(MyWindow&);
	void moveItem();
	void handleEvent(sf::Event& _event);
	bool collideDetection(sf::RectangleShape& _shape);
	
private:
	sf::Vector2f m_screenDimensions;
	sf::Vector2f m_position;
};

#endif //_PADDLE_H_
