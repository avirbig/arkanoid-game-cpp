
#include <cmath>
#include <cstdlib>

#include "brickLine.h"
#include "brickNormal.h"
#include "brickExplode.h"

BrickLine::BrickLine(float _yPosition, float _spacing, float _windowWidth)
: m_yPosition(_yPosition)
, m_windowWidth(_windowWidth)
, m_spacing(_spacing)
{
	createLine();
}

BrickLine::~BrickLine()
{
	size_t size = m_bLine.size();
	
	for(size_t i = 0; i < size; i++)
	{
		delete m_bLine[i];
	}
}

void BrickLine::createLine()
{
	int unit = m_spacing + 40;
	int numOfBricks = m_windowWidth / (unit);
	int marginWidth = (m_windowWidth - numOfBricks * unit) / 2;
	
	for (int i = 0; i < numOfBricks; ++i)
	{
		IBrick* n = new BrickNormal(sf::Vector2f(marginWidth, m_yPosition));
		marginWidth += unit;
		m_bLine.push_back(n);
	}
}

void BrickLine::draw(MyWindow& _window)
{
	size_t size = m_bLine.size();
	
	for(size_t i = 0; i < size; ++i)
	{
		m_bLine[i]->draw(_window);
	}
}
