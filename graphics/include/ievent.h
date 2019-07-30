#ifndef _IEVENT_H_
#define _IEVENT_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class IEvent{
public:
	IEvent();
	virtual ~IEvent();
	virtual void handleEvent(sf::Event& _event) = 0;
	
private:
	IEvent(IEvent const&);
	void operator = (IEvent const&);
};

#endif //_IEVENT_H_
