#ifndef _TEXT_H_
#define _TEXT_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "idraw.h"
#include "imove.h"

class MyText : 	public IDraw, 
				public IMove,
				public sf::Text{
public:
	MyText(const char* _text, size_t _charSize = 24, sf::Color _color = sf::Color::Red);
	virtual ~MyText();
	void draw(MyWindow&);
	void moveItem();
	//void loadFont(const char* _fontFile);
	
private:
	MyText(MyText const&);
	void operator = (MyText const&);
};

#endif //_TEXT_H_
