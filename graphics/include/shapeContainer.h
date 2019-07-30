#ifndef _SHAPECONTAINER_H_
#define _SHAPECONTAINER_H_


#include "ball.h"
#include "paddle.h"
#include "brickBase.h"

enum ShapeContainer_Status{
	ShapeContainer_GAMEON,
	ShapeContainer_GAMEOVER,
	ShapeContainer_PENALTY,
	ShapeContainer_NEXTLEVEL
};


class ContainerExplode;

class ShapeContainer : 	public IDraw,
						public IMove,
						public IEvent{
public:
	ShapeContainer(sf::Vector2f& _screenDimensions, std::vector<std::vector<std::string> > const & _levelData);
	~ShapeContainer();

	void draw(MyWindow&);
	void moveItem();
	void handleEvent(sf::Event& _event);
	void collisionManager();
	ShapeContainer_Status getStatus();

private:
	friend class ContainerExplode;
	void initBricks();
	void GenerateLineOfBricks(int _numOfBricks, float _spacing, sf::Vector2f& _brickPos, std::string& _bricks);
	void removeSelectedBrick(BrickBase*);
	void brickRemover(std::vector<BrickBase*>::iterator& _brick);
	size_t numOfBricks();
	bool ballOutofBounds();
	
private:
	Ball m_ball;
	Paddle m_paddle;

	std::vector<BrickBase*> m_bricksVector;
	sf::Vector2f m_screenDimensions;
	std::vector<std::vector<std::string> > m_dataFromFile;
};


#endif //_SHAPECONTAINER_H_
