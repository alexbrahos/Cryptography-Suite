#include "FrequencyAnalysis.h"

FrequencyAnalysis::FrequencyAnalysis(std::string ciphertext) {

	//initialize frequency array to 0
	for (int i = 0; i < ARRAY_SIZE; i++) {

		frequency[i] = 0;

	}

	int numValid = 0;

	//go through ciphertext and count each letter
	for (int i = 0; i < ciphertext.size(); i++) {

		//only consider capital letters
		if ((ciphertext[i] < 65) || (ciphertext[i] > 90)) {

			//not valid character, skip
			continue;

		}

		//if we are here, it was a valid character, add to count
		frequency[ciphertext[i] - 65]++;
		numValid++;

	}

	//deep copy the frequencies
	int frequencyCopy[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {

		frequencyCopy[i] = frequency[i];

	}

	//we want to print frequencies in descending order, so we need to figure out which ones were most frequent
	int frequencyOrder[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {

		int maxLoc = 0;
		//find highest remaining value
		for (int j = 1; j < ARRAY_SIZE; j++) {

			if (frequencyCopy[j] > frequencyCopy[maxLoc]) {

				maxLoc = j;

			}

		}

		frequencyOrder[i] = maxLoc;

		//make it so this will never be most frequent again
		frequencyCopy[maxLoc] = -1;

	}

	//print results
	for (int i = 0; i < ARRAY_SIZE; i++) {

		double percent = (double(frequency[frequencyOrder[i]]) / double(numValid)) * 100.0;
		std::cout << char(frequencyOrder[i] + 65) << ": " << frequency[frequencyOrder[i]] << " at " << percent << "%" << std::endl;

	}

}

int* FrequencyAnalysis::getFrequency(void) {

	return frequency;

}