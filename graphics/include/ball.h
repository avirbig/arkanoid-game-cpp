#ifndef _BALL_H_
#define _BALL_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "imove.h"
#include "idraw.h"
#include "icollide.h"
#include "window.h"

class Ball : 	public IDraw, 
				public IMove, 
				public ICollide,
				public sf::CircleShape{
public:
	Ball(sf::Vector2f& _screenDimensions);
	Ball(Ball const&);
	
	void draw(MyWindow&);
	void moveItem();
	bool collideDetection(sf::RectangleShape& _shape);
	bool isBallOut();
	
	//void collision(sf::RectangleShape& _shape);
	
	void setXVelocity();
	void setYVelocity();
private:
	void wallCollision();
private:
	sf::Vector2f m_velocity; 
	sf::Vector2f m_screenDimensions;
	sf::Vector2f m_collidedShapeFormerPosition;
	int m_collisonFlag;
};


#endif //_BALL_H_
