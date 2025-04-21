#include "Txt2String.h"
#include <fstream>

Txt2String::Txt2String(std::string fileName) {

	this->fileName = fileName;

}

std::string Txt2String::getContents(void) {

	//open the file
	std::ifstream inFile;
	inFile.open(this->fileName);

	std::string curLine;
	std::string composite;

	while (!inFile.eof()) {

		getline(inFile, curLine);
		composite += curLine + "\n";

	}

	inFile.close();

	return composite;

}