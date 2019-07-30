
#include "paddle.h"

static const float DEFAULT_WIDTH = 80;
static const float DEFAULT_HEIGHT = 10;
static const float DEFAULT_OUTLINE_THICKNESS = 2;
static const float DEFAULT_X_POSITION = 400;
static const float DEFAULT_Y_POSITION = 520;
static const sf::Color DEFAULT_OUTLINE_COLOR = sf::Color::Green;
static const sf::Color DEFAULT_FILL_COLOR = sf::Color::Magenta;


Paddle::Paddle(sf::Vector2f& _screenDimensions)
: m_screenDimensions(_screenDimensions)
, m_position(0.5 *_screenDimensions.x - 0.5 * DEFAULT_WIDTH, _screenDimensions.y - 2 * DEFAULT_HEIGHT)
{
	setSize(sf::Vector2f(DEFAULT_WIDTH, DEFAULT_HEIGHT));
	setOutlineColor(DEFAULT_OUTLINE_COLOR);
	setFillColor(DEFAULT_FILL_COLOR);
	setPosition(m_position);
}

void Paddle::draw(MyWindow& _window)
{
	_window.draw(*this);
}

void Paddle::moveItem()
{
	setPosition(m_position);
}

void Paddle::handleEvent(sf::Event& _event)
{
	switch(_event.key.code)
	{
		case sf::Keyboard::Right:
			if(m_position.x <= m_screenDimensions.x - DEFAULT_WIDTH - 5)
			{
				m_position.x += 5;
			}
			break;
		case sf::Keyboard::Left:
			if(m_position.x >= 5)
			{
				m_position.x -= 5;
			}
			break;
		default:
			break;
	}
	
	moveItem();
}


bool Paddle::collideDetection(sf::RectangleShape& _shape)
{
	return false; 
}
