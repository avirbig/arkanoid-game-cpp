#ifndef _BRICKLINE_H_
#define _BRICKLINE_H_


#include <vector>

#include "brickBase.h"

class BrickLine : public IDraw{
public:
	BrickLine(float _yPosition, float _spacing = 2, float _windowWidth = 800);
	~BrickLine();

	void draw(MyWindow&);
	
private:
	void createLine();
private:
	float m_yPosition;
	float m_windowWidth;
	float m_spacing;
	std::vector<BrickBase*> m_bLine;
};


#endif //_BRICKLINE_H_
