#include "HillSolver.h"

HillSolver::HillSolver(std::string ciphertext) {

	int matrixA, matrixB, matrixC, matrixD = 0;
	std::cout << "Enter matrix element 1: ";
	std::cin >> matrixA;
	std::cout << "Enter matrix element 2: ";
	std::cin >> matrixB;
	std::cout << "Enter matrix element 3: ";
	std::cin >> matrixC;
	std::cout << "Enter matrix element 4: ";
	std::cin >> matrixD;

	std::ofstream outFile;
	outFile.open("decryptedHill.txt", std::ofstream::out | std::ofstream::trunc);

	while (ciphertext.size() > 0) {

		//immediately add all special characters to output file
		while (ciphertext[0] < 65 || ciphertext[0] > 90) {

			outFile << ciphertext[0];
			ciphertext = ciphertext.substr(1, ciphertext.size() - 1);

			if (ciphertext.size() == 0) {

				break;

			}

		}

		if (ciphertext.size() == 0) {

			break;

		}

		char firstLetter = ciphertext[0] - 65;
		ciphertext = ciphertext.substr(1, ciphertext.size() - 1);

		std::string between = "";

		//save these special characters for between char1 and char2
		while (ciphertext[0] < 65 || ciphertext[0] > 90) {

			between += ciphertext[0];
			ciphertext = ciphertext.substr(1, ciphertext.size() - 1);

		}

		char secondLetter = ciphertext[0] - 65;
		ciphertext = ciphertext.substr(1, ciphertext.size() - 1);

		char decrFirstLetter = (((firstLetter * matrixA) + (secondLetter * matrixC)) % 26) + 97;
		char decrSecondLetter = (((firstLetter * matrixB) + (secondLetter * matrixD)) % 26) + 97;

		outFile << decrFirstLetter << between << decrSecondLetter;

	}

	outFile.close();

}