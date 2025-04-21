#ifndef _TXT2STRING_H_
#define _TXT2STRING_H_

#include <string>

class Txt2String {

public:
	//Constructor
	Txt2String(std::string fileName);

	//getContents
	std::string getContents(void);

private:
	std::string fileName;

};

#endif