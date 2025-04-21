#include "PermSolver.h"

PermSolver::PermSolver(std::string ciphertext) {

	std::cout << "Please enter the block length: ";
	int m = 0;
	std::cin >> m;

	//make vector and have user input values (function)
	std::vector<int> func = std::vector<int>();

	std::cout << "Now enter the inverse function: " << std::endl;

	for (int i = 0; i < m; i++) {

		std::cout << i + 1 << " -> ";
		int num = 0;
		std::cin >> num;
		func.push_back(num);

	}

	std::ofstream outFile;
	outFile.open("decryptedPermutation.txt", std::ofstream::out | std::ofstream::trunc);

	//runs until entire input is parsed through
	while (ciphertext.size() >= m) {

		int nonAlphaPos = 0;
		int nonAlphaLen = 0;

		for (int i = 0; i < m; i++) {

			if (ciphertext[i] < 65 || ciphertext[i] > 90) {

				nonAlphaPos = i;
				do {

					nonAlphaLen++;

				} while (ciphertext[i + nonAlphaLen] < 65 || ciphertext[i + nonAlphaLen] > 90);
				break;
			}

		}

		//swaps small segment according to current permutation
		for (int i = 0; i < m + nonAlphaLen; i++) {

			if ((ciphertext[i] < 65 || ciphertext[i] > 90)) { //during numbers

				outFile << ciphertext[i];
				continue;

			}

			if (i < nonAlphaPos) { //before numbers

				if (func[i] < nonAlphaPos) {

					outFile << char(ciphertext[func[i]] + 32);

				}
				else {

					outFile << char(ciphertext[func[i + nonAlphaLen]] + 32);

				}

			}
			else { //after numbers

				if (func[i - nonAlphaLen] < nonAlphaPos) {

					outFile << char(ciphertext[func[i - nonAlphaLen]] + 32);

				}
				else {

					outFile << char(ciphertext[func[i - nonAlphaLen] + nonAlphaLen] + 32);

				}

			}

		}

		ciphertext = ciphertext.substr(m + nonAlphaLen, ciphertext.size());

	}

	outFile.close();

}