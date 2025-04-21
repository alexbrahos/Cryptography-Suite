#ifndef _MASSPERMUTATOR_H_
#define _MASSPERMUTATOR_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

class MassPermutator {

public:
	MassPermutator(std::string ciphertext);

private:
	bool isValidText(std::string decryptedText);

};

#endif