#include "VigenereShifter.h"

VigenereShifter::VigenereShifter(std::string ciphertext) {

	std::cout << "What is the keyword length?: ";
	int m = 0;
	std::cin >> m;

	std::string key = "";
	std::string altKey = "";

	//strip extra characters from ciphertext
	for (int i = 0; i < ciphertext.size(); i++) {

		if (ciphertext[i] < 65 || ciphertext[i] > 90) {

			ciphertext.erase(i, 1);
			i--;

		}

	}

	//split ciphertext into m substrings, and run frequency analysis
	for (int i = 0; i < m; i++) {

		//make substring
		std::string y = "";
		for (int j = i; j < ciphertext.size(); j += m) {

			y += ciphertext[j];

		}

		FrequencyAnalysis analyze = FrequencyAnalysis(y);
		int* frequency = analyze.getFrequency();

		//find max frequency in y, and calculate distance from 'e'
		int maxLoc = 0;
		int secondMax = 0;
		for (int j = 1; j < ARRAY_SIZE; j++) {

			if (frequency[j] > frequency[maxLoc]) {

				maxLoc = j;

			}

		}

		if (maxLoc == 0) {

			secondMax = 1;

		}

		//find next best location
		for (int j = 1; j < ARRAY_SIZE; j++) {

			if ((frequency[j] > frequency[secondMax]) && (j != maxLoc)) {

				secondMax = j;

			}

		}

		key += char(((maxLoc - 4 + 26) % 26) + 97);
		altKey += char(((secondMax - 4 + 26) % 26) + 97);

	}

	std::cout << "The calculated key was \'" << key << "\'" << std::endl;
	std::cout << "The next best letter for each position was \'" << altKey << "\'";

}