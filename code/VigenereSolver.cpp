#include "VigenereSolver.h"

VigenereSolver::VigenereSolver(std::string ciphertext) {

	std::cout << "Please enter the keyword (ALL CAPS): ";
	std::string keyword = "";
	std::cin >> keyword;

	std::ofstream outFile;
	outFile.open("decryptedVigenere.txt", std::ofstream::out | std::ofstream::trunc);

	int keyCounter = 0;

	for (int i = 0; i < ciphertext.size(); i++) {

		//skip non-alphabet characters
		if (ciphertext[i] < 65 || ciphertext[i] > 90) {

			outFile << ciphertext[i];
			continue;

		}

		//shift
		char decrLetter = (((ciphertext[i] - keyword[keyCounter]) + 26) % 26) + 97;
		keyCounter = (keyCounter + 1) % keyword.size();
		outFile << decrLetter;

	}

	outFile.close();

}