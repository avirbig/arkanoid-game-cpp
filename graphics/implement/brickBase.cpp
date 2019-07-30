#include "brickBase.h"


BrickBase::BrickBase()
{
}

BrickBase::~BrickBase()
{
}

static bool doOverlap(sf::Vector2f& bCorner, float minX, float maxX, float minY, float maxY) 
{
	if((bCorner.x >= minX && bCorner.x <= maxX) && (bCorner.y >= minY && bCorner.y <= maxY))
	{
		return true;
	}

	return false; 
} 

bool BrickBase::collideDetection(sf::RectangleShape& _ball)
{
	sf::Vector2f sDimensions(_ball.getSize());
	sf::Vector2f sPos = _ball.getPosition();
	sf::Vector2f bDimensions(getSize());
	sf::Vector2f bPos = getPosition();

	//SHAPES BOUNDARIES
	float sx1 = sPos.x;
	float sx2 = sPos.x + sDimensions.x;
	float sy1 = sPos.y;
	float sy2 = sPos.y + sDimensions.y;
	//BRICK CORNERS
	sf::Vector2f brickUpperLeft = bPos;
	sf::Vector2f brickLowerLeft = bPos + sf::Vector2f(0, bDimensions.y);
	sf::Vector2f brickLowerRight = bPos + bDimensions;
	sf::Vector2f brickUpperRight = bPos + sf::Vector2f(bDimensions.x, 0);
	
	if(doOverlap(brickUpperLeft, sx1, sx2, sy1, sy2)) return true;
	if(doOverlap(brickLowerLeft, sx1, sx2, sy1, sy2)) return true;
	if(doOverlap(brickLowerRight, sx1, sx2, sy1, sy2)) return true;
	if(doOverlap(brickUpperRight, sx1, sx2, sy1, sy2)) return true;
	
	return false; 
}
