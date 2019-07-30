#ifndef _CALCS_H_
#define _CALCS_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Calcs{
	
	using namespace sf;
	
	Vector2f BallCenter(Vector2f const& _upLeftCorner, float _radius);

	float Distance(Vector2f const& _v);

	Vector2f NearestCorner(Vector2f _c1, Vector2f _c2, Vector2f _c3, Vector2f _c4, Vector2f _ballCenter);
	
	bool IsDotOnCircle(Vector2f const& _center, float _radius, Vector2f const& _dot);

	bool IsLineXCircleIntersect(Vector2f const& _center, float _radius, float _x1, float _x2, float _y);

	bool IsLineYCircleIntersect(Vector2f const& _center, float _radius, float _y1, float _y2, float _x);
	
	bool CheckDistance(sf::Vector2f const& _a, sf::Vector2f const& _b);

}

#endif //_CALCS_H_
