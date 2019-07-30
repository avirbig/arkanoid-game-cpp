#include "conversions.h"

	
sf::Vector2f Conversions::V2uToV2f(sf::Vector2u const& _vu)
{
	float fx = (float) _vu.x;
	float fy = (float) _vu.y;
	
	return sf::Vector2f(fx, fy);
}

