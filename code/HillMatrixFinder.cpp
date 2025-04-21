#include "HillMatrixFinder.h"

HillMatrixFinder::HillMatrixFinder(std::string ciphertext) {

	std::string ciphertextCopy = ciphertext;

	//write all results to a file. user can scan to see if any are valid
	std::ofstream outFile;
	outFile.open("hillMatrices.txt", std::ofstream::out | std::ofstream::trunc);

	//repeat decryption for all 2x2 matrices with values 0<=x<=9 (10,000 trials)
	for (int i = 0; i <= 29; i++) {

		for (int j = 0; j <= 29; j++) {

			for (int k = 0; k <= 29; k++) {

				for (int l = 0; l <= 29; l++) {

					//this code will run for every matrix
					ciphertextCopy = ciphertext;
					outFile << "{" << i << ", " << j << ", " << k << ", " << l << "}: ";
					for (int m = 0; m < 28; m++) {

						//ignore non-alphabetic characters
						while (ciphertextCopy[0] < 65 || ciphertextCopy[0] > 90) {

							ciphertextCopy = ciphertextCopy.substr(1, ciphertextCopy.size() - 1);

						}

						char firstLetter = ciphertextCopy[0] - 65;
						ciphertextCopy = ciphertextCopy.substr(1, ciphertextCopy.size() - 1);

						//ignore non-alphabetic characters
						while (ciphertextCopy[0] < 65 || ciphertextCopy[0] > 90) {

							ciphertextCopy = ciphertextCopy.substr(1, ciphertextCopy.size() - 1);

						}

						char secondLetter = ciphertextCopy[0] - 65;
						ciphertextCopy = ciphertextCopy.substr(1, ciphertextCopy.size() - 1);

						char decrFirstLetter = (((firstLetter * i) + (secondLetter * k)) % 26) + 97;
						char decrSecondLetter = (((firstLetter * j) + (secondLetter * l)) % 26) + 97;

						outFile << decrFirstLetter << decrSecondLetter;

					}

					outFile << std::endl;

				}

			}

		}

	}

	outFile.close();

}