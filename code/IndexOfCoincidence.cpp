#include "IndexOfCoincidence.h"

IndexOfCoincidence::IndexOfCoincidence(std::string ciphertext) {

	FrequencyAnalysis m1 = FrequencyAnalysis(ciphertext);
	int* frequency = m1.getFrequency();

	//strip extra characters from ciphertext
	for (int i = 0; i < ciphertext.size(); i++) {

		if (ciphertext[i] < 65 || ciphertext[i] > 90) {

			ciphertext.erase(i, 1);
			i--;

		}

	}

	std::ofstream outFile;
	outFile.open("IoCResults.txt", std::ofstream::out | std::ofstream::trunc);

	int sum = 0;
	for (int i = 0; i < 26; i++) {

		sum += (frequency[i] * (frequency[i] - 1));

	}

	outFile << double(sum) / double(ciphertext.size() * (ciphertext.size() - 1)) << std::endl;

	//test all the way through m=10
	for (int i = 1; i < 10; i++) {

		//for each m, make the substrings and calculate IoC
		for (int j = 0; j <= i; j++) {

			//making substring
			std::string y = "";
			for (int k = j; k < ciphertext.size(); k += i + 1) {

				y += ciphertext[k];

			}

			//calculating IoC
			FrequencyAnalysis analyze = FrequencyAnalysis(y);
			frequency = analyze.getFrequency();

			sum = 0;
			for (int i = 0; i < 26; i++) {

				sum += (frequency[i] * (frequency[i] - 1));

			}

			outFile << double(sum) / double(y.size() * (y.size() - 1)) << " ";

		}

		outFile << std::endl;

	}

}