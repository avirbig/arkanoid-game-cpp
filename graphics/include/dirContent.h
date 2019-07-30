#ifndef _DIRCONT_H_
#define _DIRCONT_H_

#include <sys/io.h>
#include <iostream>
#include <vector>
#include <string>

class DirCont{
public:
	DirCont();
	std::vector<std::string> getData(const char *_filespec = "", const char *_dirPath = ".");
	
private:
	DirCont(DirCont const&);
	DirCont operator = (DirCont const&);
};

#endif //_DIRCONT_H_
