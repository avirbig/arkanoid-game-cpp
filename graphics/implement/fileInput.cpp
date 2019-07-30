
#include <fstream>		//ifstream
#include <sstream>		//istringstream
#include <algorithm>	//for_each

#include "fileInput.h"


FileInput::FileInput()
{
}

FileInput::~FileInput()
{
}

std::vector<std::vector<std::string> > FileInput::read(const char* _fname)
{
	using namespace std;
	
	vector<vector<string> > vData;
	
	ifstream is((const char*)_fname);
	
	if(!is.good())
	{
		cerr << "FileInput FAIL" << '\n';
		return vData;
	}
	
	string line;
	
	while(getline(is, line))
	{
		istringstream lineReader(line);
		vector<string> record;
		string item;
		
		while(getline(lineReader, item, ' '))
		{
			record.push_back(item);
		}
		
		vData.push_back(record);
	}
	
	return vData;
}

class LinePrint{
	std::ostream& m_os;
public:
	LinePrint(std::ostream& _os) :m_os(_os) {}
	void operator()(std::string& _str) 
	{ 
		m_os << _str << '\n';
	}
};

class DataPrint{
	std::ostream& m_os;
public:
	DataPrint(std::ostream& _os) :m_os(_os) {}
	void operator()(std::vector<std::string>& _line) 
	{ 
		std::for_each(_line.begin(), _line.end(), LinePrint(m_os));
	}
};

void FileInput::print(std::ostream& _os)
{
	std::for_each(m_data.begin(), m_data.end(), DataPrint(_os));
	
	return;
}

