#include "calcs.h"
//#include <math>

using namespace sf;	
	
Vector2f Calcs::BallCenter(Vector2f const& _upLeftCorner, float _radius)
{	
	return Vector2f(_upLeftCorner.x + _radius, _upLeftCorner.y + _radius);
}

static void CheckCornerDistance(Vector2f& _res, Vector2f& _newCorner, float _newDistance, float _minDistance)
{
	if(_newDistance < _minDistance)
	{
		_minDistance = _newDistance;
		_res = _newCorner;
	}
}

float Calcs::Distance(Vector2f const& _v)
{
	return _v.x * _v.x + _v.y * _v.y;
}

Vector2f Calcs::NearestCorner(Vector2f _c1, Vector2f _c2, Vector2f _c3, Vector2f _c4, Vector2f _ballCenter)
{
	Vector2f res = _c1;
	float minDistance = Distance(_ballCenter - _c1);
	
	CheckCornerDistance(res, _c2, Distance(_ballCenter - _c2), minDistance);
	CheckCornerDistance(res, _c3, Distance(_ballCenter - _c3), minDistance);
	CheckCornerDistance(res, _c4, Distance(_ballCenter - _c4), minDistance);
	
	return res;
}

//bool Calcs::IsHitVertical(Vector2f& _ballCenter, Vector2f& _ballVelocity, Vector2f& _nearestCorner)
//{
	//float slope = _ballVelocity.y / _ballVelocity.x;
	
	//float yIntercept = _ballCenter.y - slope * _ballCenter.x;
	
	//if(_nearestCorner.y > _nearestCorner.x *slope + yIntercept)
	//{
		//return true;
	//}
	
	//return false;
//}

bool Calcs::IsDotOnCircle(Vector2f const& _center, float _radius, Vector2f const& _dot)
{
	float xx 	= (_center.x - _dot.x) * (_center.x - _dot.x);
	float yy 	= (_center.y - _dot.y) * (_center.y - _dot.y);
	
	return (xx + yy) - (_radius *_radius) < 1;
}

bool Calcs::IsLineXCircleIntersect(Vector2f const& _center, float _radius, float _x1, float _x2, float _y)
{
	for (float i = _x1; i < _x2; i += 0.5)
	{
		if(IsDotOnCircle(_center, _radius, Vector2f(i ,_y)))
		{
			return true;
		}
	}
	
	return false;
}

bool Calcs::IsLineYCircleIntersect(Vector2f const& _center, float _radius, float _y1, float _y2, float _x)
{
	for (float i = _y1; i < _y2; i += 0.5)
	{
		if(IsDotOnCircle(_center, _radius, Vector2f(_x ,i)))
		{
			return true;
		}
	}
	
	return false;
}

bool Calcs::CheckDistance(sf::Vector2f const& _a, sf::Vector2f const& _b)
{
	sf::Vector2f vDistance = _a - _b;
	
	float scalarDistance = vDistance.x * vDistance.x + vDistance.y * vDistance.y;
	
	return (scalarDistance < 50 * 50)? true: false; 
}

