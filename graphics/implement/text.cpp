#include "text.h"
#include <iostream>

MyText::MyText(const char* _text, size_t _charSize,sf::Color _color)
{
	sf::Font font;
	if(font.loadFromFile("/sources/arial.ttf"))
	{
		std::cout << "Error loading font" << '\n';
	}
	setFont(font);
	setString(_text);
	setCharacterSize(_charSize);
	setFillColor(_color);
	setStyle(sf::Text::Bold | sf::Text::Underlined);
}

MyText::~MyText()
{
}

void MyText::draw(MyWindow& _w)
{
	_w.draw(*this);
}

void MyText::moveItem()
{
}

