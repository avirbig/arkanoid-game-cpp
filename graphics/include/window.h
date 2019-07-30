#ifndef _MYWINDOW_H_
#define _MYWINDOW_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "ievent.h"

class ShapeContainer;

class MyWindow : 	public IEvent, 
					public sf::RenderWindow{
public:
	MyWindow();
	~MyWindow();
	
	void handleEvent(sf::Event& _event);
	void play(ShapeContainer& _container);
};

#endif //_MYWINDOW_H_
