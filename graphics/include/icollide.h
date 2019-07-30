#ifndef _ICOLLIDE_H_
#define _ICOLLIDE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ICollide{
public:
	ICollide();
	virtual ~ICollide();
	virtual bool collideDetection(sf::RectangleShape& _shape) = 0;
	
private:
	ICollide(ICollide const&);
	void operator = (ICollide const&);
};

#endif //_ICOLLIDE_H_
