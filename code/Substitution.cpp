#include "Substitution.h"

Substitution::Substitution(std::string ciphertext) {

	while (true) {

		std::cout << ciphertext << std::endl;
		std::cout << "Enter a letter to change or type \'DONE\' to exit and write to file: ";

		std::string input1 = "";
		std::cin >> input1;

		//user wants to exit
		if (input1 == "DONE") {

			break;

		}

		std::cout << "Enter a letter to replace with: ";

		std::string input2 = "";
		std::cin >> input2;

		//replace characters
		for (int i = 0; i < ciphertext.size(); i++) {

			if (ciphertext[i] == input1[0]) {

				ciphertext[i] = input2[0];

			}

		}

	}

	std::ofstream outFile;
	outFile.open("decryptedSubstitution.txt", std::ofstream::out | std::ofstream::trunc);
	outFile << ciphertext;
	outFile.close();

}