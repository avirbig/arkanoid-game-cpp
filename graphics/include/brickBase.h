#ifndef _IBRICK_H_
#define _IBRICK_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "idraw.h"
#include "icollide.h"

class BrickBase : 	public IDraw, 
					public ICollide,
					public sf::RectangleShape{
public:
	BrickBase();
	virtual ~BrickBase();
	void draw(MyWindow&) = 0;
	bool collideDetection(sf::RectangleShape& _shape);
	
private:
	BrickBase(BrickBase const&);
	void operator = (BrickBase const&);
};

#endif //_IBRICK_H_
