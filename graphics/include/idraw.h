#ifndef _IDRAW_H_
#define _IDRAW_H_

#include "window.h"

class IDraw{
public:
	IDraw();
	virtual ~IDraw();
	virtual void draw(MyWindow&) = 0;
	
private:
	IDraw(IDraw const&);
	void operator = (IDraw const&);
};

#endif //_IDRAW_H_
