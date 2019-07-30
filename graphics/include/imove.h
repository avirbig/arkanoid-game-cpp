#ifndef _IMOVE_H_
#define _IMOVE_H_

#include <SFML/Window.hpp>

class IMove{
public:
	IMove();
	virtual ~IMove();
	
	virtual void moveItem() = 0;
	
private:
	IMove(IMove const&);
	void operator = (IMove const&);
};

#endif //_IMOVE_H_
