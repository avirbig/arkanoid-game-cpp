#include <iostream>
#include <string>


#include "mu_test.h"
#include "brickBase.h"
#include "idraw.h"
#include "icollide.h"
#include "brickNormal.h"
#include "fileInput.h"
#include "dirContent.h"
#include "window.h"


UNIT(brickCollide)
	MyWindow window;
	
	BrickNormal o(sf::Vector2f(100,100));
	
	BrickNormal a(sf::Vector2f(110,110));
	BrickNormal b(sf::Vector2f(110,90));
	BrickNormal c(sf::Vector2f(90,90));
	BrickNormal d(sf::Vector2f(90,110));
	
	std::cout << "A:" << '\n';
	ASSERT_THAT(o.collideDetection(a));
	std::cout << "B:"<< '\n';
	ASSERT_THAT(o.collideDetection(b));
	std::cout << "C:"<< '\n';
	ASSERT_THAT(o.collideDetection(c));
	std::cout << "D:"<< '\n';
	ASSERT_THAT(o.collideDetection(d));
	
	while (window.isOpen())
    {
		sf::Event event;                
		while (window.pollEvent(event))
		{
			window.handleEvent(event);
		}
		
		window.clear(sf::Color::Transparent);
		o.draw(window);
		a.draw(window);
		b.draw(window);
		c.draw(window);
		d.draw(window);

		window.display();
	}
	
END_UNIT

UNIT(readFromFile)
	
	FileInput f;
	
	f.read("level1.txt");
	
	f.print();
	
END_UNIT


class FileNamePrint{
	std::ostream& m_os;
public:
	FileNamePrint(std::ostream& _os) :m_os(_os) {}
	void operator()(std::string& _str) 
	{ 
		m_os << _str << '\n';
	}
};

void print(std::vector<std::string>& _v, std::ostream& _os)
{
	std::for_each(_v.begin(), _v.end(), FileNamePrint(_os));
}

UNIT(find_files_in_dir)
	using namespace std;
	
	std::vector<std::string> _v;
	
	DirCont dirCont;
	
	_v = dirCont.getData("lvl");
	print(_v, cout);
	_v = dirCont.getData("cpp");
	print(_v, cout);
	_v = dirCont.getData("cpp", "implement/");
	print(_v, cout);
	_v = dirCont.getData();
	print(_v, cout);
	
END_UNIT

/* main macro */
TEST_SUITE(framework test)
	IGNORE_TEST(brickCollide)
	IGNORE_TEST(readFromFile)
	TEST(find_files_in_dir)
END_SUITE






