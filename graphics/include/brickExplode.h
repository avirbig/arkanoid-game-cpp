#ifndef _BRICKEXPLODE_H_
#define _BRICKEXPLODE_H_

#include "brickBase.h"

class BrickExplode : public BrickBase{
public:
	BrickExplode(sf::Vector2f _position);
	
	void draw(MyWindow&);
};

#endif //_BRICKEXPLODE_H_
