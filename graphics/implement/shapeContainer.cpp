
#include <algorithm>	//find_if
#include <iostream> 	//cout
#include <cstdlib>		//rand
#include <ctime>		//srand
#include <sstream>		//istringstream
#include <string>		//size()

#include "calcs.h"
#include "shapeContainer.h"
#include "brickNormal.h"
#include "brickExplode.h"

ShapeContainer::ShapeContainer(sf::Vector2f& _screenDimensions, std::vector<std::vector<std::string> > const& _dataFromFile)
: m_ball(_screenDimensions)
, m_paddle(_screenDimensions)
, m_screenDimensions(_screenDimensions)
, m_dataFromFile(_dataFromFile)
{
	initBricks();
}

static void bricksDelete(BrickBase* _b)
{
	if(_b)
	{
		delete _b;
	}
}

ShapeContainer::~ShapeContainer()
{
	std::for_each(m_bricksVector.begin(), m_bricksVector.end(), bricksDelete);
}

class Drawer {
	MyWindow& w_;
public:
	Drawer(MyWindow& w) :w_(w) {}
	void operator()(BrickBase* p) {
		if(p)
		{
			p->draw(w_); 
		}
	}
};

void ShapeContainer::draw(MyWindow& _window)
{
	m_ball.draw(_window);
	m_paddle.draw(_window);
	
	std::for_each(m_bricksVector.begin(), m_bricksVector.end(), Drawer(_window));
}

void ShapeContainer::moveItem()
{
	m_ball.moveItem();
	m_paddle.moveItem();
}

void ShapeContainer::handleEvent(sf::Event& _event)
{
	m_paddle.handleEvent(_event);
}

void ShapeContainer::GenerateLineOfBricks(int _numOfBricks, float _spacing, sf::Vector2f& _brickPos, std::string& _bricks)
{
	for (int j = 0; j < _numOfBricks - 1 && _brickPos.x < m_screenDimensions.x - 40; ++j, _brickPos.x += _spacing + 20)
	{
		if(_bricks[j] == 'N')
		{
			BrickBase* n = new BrickNormal(_brickPos);
			m_bricksVector.push_back(n);
		}
		else if(_bricks[j] == 'E')
		{
			BrickBase* n = new BrickExplode(_brickPos);
			m_bricksVector.push_back(n);
		}
	}
}

void ShapeContainer::initBricks()
{
	using namespace std;

	int numOfLines = m_dataFromFile.size();
	
	sf::Vector2f brickPos(0, 10);
	
	istringstream ySSpacing(m_dataFromFile[0][0]);
	
	float ySpacing;
	ySSpacing >> ySpacing;
	
	for (int i = 1; i < numOfLines - 1 ; ++i, brickPos.y += ySpacing)
	{
		vector<string> line = m_dataFromFile[i];
		
		istringstream margins(line[0]);
		margins >> brickPos.x;
		istringstream sspacing(line[1]);
		float spacing;
		sspacing >> spacing;
		
		string bricks(line[2]);
		int numOfBricks = bricks.size();
		
		GenerateLineOfBricks(numOfBricks, spacing, brickPos, bricks);
	}
}

class BrickCollisionManager{
	Ball& m_ball;
public:
	BrickCollisionManager(Ball& _ball) :m_ball(_ball) {}
	bool operator()(BrickBase* p) 
	{ 
		if(p != 0 && m_ball.collideDetection(*p))
		{
			std::cout << "COLL" << '\n';
			return true;
		}
		return false;
	 }
};

void ShapeContainer::removeSelectedBrick(BrickBase* _pBrick)
{
	std::vector<BrickBase*>::iterator it = m_bricksVector.begin();
	std::vector<BrickBase*>::iterator end = m_bricksVector.end();
	
	for (;it != end; ++it)
	{
		if(*it == _pBrick)
		{
			delete _pBrick;
			*it = 0;
			return;
		}
	}
}

class ContainerExplode{
	sf::Vector2f m_pos;
	ShapeContainer& sc;
public:
	ContainerExplode(sf::Vector2f _pos, ShapeContainer& sc) :m_pos(_pos) , sc(sc) {}
	void operator()(BrickBase* pBrick) 
	{
		if(pBrick)
		{
			sf::Vector2f otherPos = pBrick->getPosition(); 
			 
			if(Calcs::CheckDistance(m_pos, otherPos))
			{
				sc.removeSelectedBrick(pBrick);
			}
		}
	}
};

void ShapeContainer::brickRemover(std::vector<BrickBase*>::iterator& _brick)
{
		BrickExplode* be = dynamic_cast<BrickExplode*>(*_brick); // IS EQUAL TO ==>if(typeid(*(*_brick)) == typeid(BrickExplode)) AKA rtti
		
		if(be)
		{
			std::cout << "EXPLODE" << '\n';
			std::for_each(m_bricksVector.begin(), m_bricksVector.end(), ContainerExplode((*_brick)->getPosition(), *this));
		}
		else
		{
			delete be;
			*_brick = 0;
		}
}

void ShapeContainer::collisionManager()
{
	m_ball.collideDetection(m_paddle);
	
	std::vector<BrickBase*>::iterator brick = std::find_if(m_bricksVector.begin(), m_bricksVector.end(), BrickCollisionManager(m_ball));
	
	if(brick != m_bricksVector.end())
	{
		brickRemover(brick);
	}
}

class ContainerGetSize{
	size_t& m_size;
public:
	ContainerGetSize(size_t& _size) :m_size(_size){}
	void operator()(BrickBase* pBrick) 
	{
		if(pBrick)
		{
			++m_size;
		}
	}
};

size_t ShapeContainer::numOfBricks()
{
	size_t size = 0;
	std::for_each(m_bricksVector.begin(), m_bricksVector.end(), ContainerGetSize(size));
	
	return size;
}

bool ShapeContainer::ballOutofBounds()
{
	return m_ball.isBallOut();
}

ShapeContainer_Status ShapeContainer::getStatus()
{
	if(numOfBricks() == 0)
	{
		return ShapeContainer_NEXTLEVEL;
	}
	else if(ballOutofBounds())
	{
		return ShapeContainer_GAMEOVER;
	}
	
	return ShapeContainer_GAMEON;
}


////////////////////////////////////////////
//			CODE GRAVEYARD				  //
////////////////////////////////////////////


// HARD CODED IMPLEMENTATION

	//int xunit = SPACING + 40;
	//int yunit = SPACING + 20;
	//int numOfBricks = m_screenDimensions.x / (xunit);
	//int marginWidth = (m_screenDimensions.x - numOfBricks * xunit) / 2;
	
	//std::srand(std::time(0));
	
	//for (int j = yunit; j < m_screenDimensions.y / 2; j += yunit)
	//{
		//for (int i = 0, Xposition = marginWidth; i < numOfBricks; ++i)
		//{
			//int rand = std::rand();
			//if(rand % 7 != 0)
			//{
				//BrickBase* n = new BrickNormal(sf::Vector2f(Xposition, j));
				//Xposition += xunit;
				//m_bricksVector.push_back(n);
			//}
			//else
			//{
				 //BrickBase* n = new BrickExplode(sf::Vector2f(Xposition, j));
				//Xposition += xunit;
				//m_bricksVector.push_back(n);
			//}
		//}
	//}
//}

