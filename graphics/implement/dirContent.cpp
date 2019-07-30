
#include "dirContent.h"
#include <dirent.h> 	// scandir 
#include <stdlib.h> 	// free 
#include <algorithm> 	// for_each
#include <string.h> 	// strstr


DirCont::DirCont()
{
}

static void DeAllocateScandDir(struct dirent **_fileList,int _numOfFiles)
{
	for(int i = 0; i < _numOfFiles; ++i)
	{
	  free(_fileList[i]);
	}
	
	free(_fileList);
}

std::vector<std::string> DirCont::getData(const char *_filespec, const char *_dirPath)
{
	using namespace std;
	
	vector<string> dirContent;
	
	struct dirent **fileList = 0;
	int numOfFiles = scandir(_dirPath, &fileList, 0, alphasort); /* fm must be in initial dir ?? */
	if(numOfFiles < 2)
	{
		cout << "numOfFiles: " << numOfFiles << " ,No *.lvl files in current directory/n";
	}
	
	for(int i = 2; i < numOfFiles; ++i)  /* FIRST TWO ARE . .. (IRRELEVANT) */
	{
		char* specOccurence = strstr(fileList[i]->d_name, _filespec); /* ONLY CDR FILES */
		if(specOccurence) 
		{ 
			dirContent.push_back(string(fileList[i]->d_name));
		}
	}
	
	DeAllocateScandDir(fileList,numOfFiles);
	
	return dirContent;
}

