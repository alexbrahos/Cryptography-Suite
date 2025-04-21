#ifndef _FREQUENCYANALYSIS_H_
#define _FREQUENCYANALYSIS_H_

#include <iostream>
#include <string>
#include "Txt2String.h"

#define ARRAY_SIZE 26

class FrequencyAnalysis {

public:
	FrequencyAnalysis(std::string ciphertext);
	int* getFrequency(void);

private:
	int frequency[ARRAY_SIZE];

};

#endif