
#include <iostream>
#include "brickNormal.h"

static const float DEFAULT_WIDTH = 20;
static const float DEFAULT_HEIGHT = 10;
static const sf::Color DEFAULT_FILL_COLOR = sf::Color::Yellow;

BrickNormal::BrickNormal(sf::Vector2f _position)
{
	setSize(sf::Vector2f(DEFAULT_WIDTH, DEFAULT_HEIGHT));
	setFillColor(DEFAULT_FILL_COLOR);
	setOutlineColor(sf::Color::Red);
	setOutlineThickness(1);
	setPosition(_position);
}

void BrickNormal::draw(MyWindow& _window)
{
	_window.draw(*this);
}
