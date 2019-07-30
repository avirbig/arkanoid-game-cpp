#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>

#include "window.h"
#include "shapeContainer.h"
#include "text.h"

class Game{
public:
	Game();
	~Game();
	
	void play();
	
private:
	MyWindow m_window;
	std::vector<std::string> m_levels;
};

#endif //_GAME_H_
