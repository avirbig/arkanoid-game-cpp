#ifndef _BRICKNORMAL_H_
#define _BRICKNORMAL_H_

#include "brickBase.h"

class BrickNormal : public BrickBase{
	public:
	BrickNormal(sf::Vector2f _position = sf::Vector2f(20,40));
	
	void draw(MyWindow&);
};

#endif //_BRICKNORMAL_H_
