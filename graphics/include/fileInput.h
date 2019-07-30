#ifndef _FILEINPUT_H_
#define _FILEINPUT_H_

#include <iostream>
#include <vector>
#include <string>

class DataPrint;
class LinePrint;

class FileInput{
public:
	FileInput();
	~FileInput();
	std::vector<std::vector<std::string> > read(const char* _fname);
	void print(std::ostream& _os = std::cout);
	
private:
	friend class DataPrint;
	friend class LinePrint;
	std::vector<std::vector<std::string> > m_data;
};

#endif //_FILEINPUT_H_
