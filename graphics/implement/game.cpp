
#include "game.h"

#include "conversions.h"
#include "fileInput.h"
#include "dirContent.h"


Game::Game()
: m_levels(DirCont().getData("lvl", "sources/"))
{
}

Game::~Game()
{
	
}

void Game::play()
{
	MyWindow window;
	FileInput f;
	MyText score("score: 0");
	
	std::string srcDir("sources/");
	ShapeContainer_Status gameStatus = ShapeContainer_GAMEON;
	size_t i = 0;
	sf::Vector2f windowDims = Conversions::V2uToV2f(window.getSize());
	
	while(true)
	{
		int count = 0;
		ShapeContainer container(windowDims, f.read((srcDir + m_levels[i]).c_str()));
		
		while(window.isOpen())
		{
			sf::Event event;                
			while (window.pollEvent(event))
			{
				window.handleEvent(event);
				container.handleEvent(event);
			}
			
			window.clear(sf::Color::Transparent);
			container.draw(window);
			container.moveItem();
			container.collisionManager();
			window.display();
			
			//score.draw(window);
			
			gameStatus = container.getStatus();
			if(gameStatus == ShapeContainer_NEXTLEVEL)
			{
				std::cout << count++ << '\n';
				if(i < m_levels.size()) break;
			} 
		}
		++i;
	}
}

