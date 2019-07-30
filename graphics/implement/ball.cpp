
#include "ball.h"
#include "calcs.h"

const float DEFAULT_RADIUS = 10;
const float DEFAULT_OUTLINE_THICKNESS = 1;
const float DEFAULT_X_POSITION = 400;
const float DEFAULT_Y_POSITION = 510;
static const sf::Color DEFAULT_OUTLINE_COLOR = sf::Color::Green;
static const sf::Color DEFAULT_FILL_COLOR = sf::Color::Blue;

Ball::Ball(sf::Vector2f& _screenDimensions)
: m_velocity(-1,-4)
, m_screenDimensions(_screenDimensions)
, m_collisonFlag(0)
{
	setRadius(DEFAULT_RADIUS);
	setOutlineColor(DEFAULT_OUTLINE_COLOR);
	setFillColor(DEFAULT_FILL_COLOR);
	setOutlineThickness(DEFAULT_OUTLINE_THICKNESS);
	setPosition(DEFAULT_X_POSITION - DEFAULT_RADIUS, DEFAULT_Y_POSITION);
}

void Ball::draw(MyWindow& _window)
{
	_window.draw(*this);
}

void Ball::wallCollision()
{
	sf::Vector2f pos = getPosition();
	float r = getRadius();
	
	if(pos.x  >= m_screenDimensions.x - 2*r) m_velocity.x *= -1;
	//if(pos.y  >= m_screenDimensions.y - 2*r) m_velocity.y *= -1;
	if(pos.x  <= 0) m_velocity.x *= -1;
	if(pos.y  <= 0) m_velocity.y *= -1;
}

void Ball::moveItem()
{
	wallCollision();
	move(m_velocity);
}

bool Ball::collideDetection(sf::RectangleShape& _shape)
{
	sf::Vector2f sDimensions(_shape.getSize());
	sf::Vector2f sPos = _shape.getPosition();
	
	float radius = getRadius();
	sf::Vector2f bPos = getPosition();
	
	//SHAPES BOUNDARIES
	float sx1 = sPos.x;
	float sx2 = sPos.x + sDimensions.x;
	float sy1 = sPos.y;
	float sy2 = sPos.y + sDimensions.y;
	
	sf::Vector2f center = Calcs::BallCenter(bPos, radius);
	bool collision = Calcs::IsLineXCircleIntersect(center, radius, sx1, sx2, sy1);
	if(collision) 
	{
		setYVelocity();
		return true;
	}
	
	collision = Calcs::IsLineXCircleIntersect(center, radius, sx1, sx2, sy2);
	if(collision) 
	{
		setYVelocity();
		return true;
	}
	
	collision = Calcs::IsLineYCircleIntersect(center, radius, sy1, sy2, sx1);
	if(collision) 
	{
		setXVelocity();
		return true;
	}
	
	collision = Calcs::IsLineYCircleIntersect(center, radius, sy1, sy2, sx2);
	if(collision) 
	{
		setXVelocity();
		return true;
	}
	
	return false; 
}

void Ball::setXVelocity()
{
	m_velocity.x *= -1;
}

void Ball::setYVelocity()
{
	m_velocity.y *= -1;
}

bool Ball::isBallOut()
{
	return getPosition().y >= m_screenDimensions.y - 2*getRadius();
}
