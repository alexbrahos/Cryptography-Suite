#include "MassPermutator.h"

MassPermutator::MassPermutator(std::string ciphertext) {

	std::cout << "Please enter the block length: ";
	int m = 0;
	std::cin >> m;

	//make vector and add all numbers 0 through m-1
	std::vector<int> perms = std::vector<int>();
	for (int i = 0; i < m; i++) {

		perms.push_back(i);

	}

	for (int i = 0; i < ciphertext.size(); i++) {

		if (ciphertext[i] < 65 || ciphertext[i] > 90) {

			ciphertext.erase(i, 1);
			i--;

		}

	}

	std::ofstream outFile;
	outFile.open("MassPerms.txt", std::ofstream::out | std::ofstream::trunc);

	int lastPos1 = 0;

	//runs for each permutation of the vector
	do {

		//progress indicator
		if (perms[0] != lastPos1) {

			std::cout << double(perms[0]) / double(m) << std::endl;
			lastPos1 = perms[0];

		}

		std::string ciphertextCopy = ciphertext;
		std::string decrText = "";
		
		//runs until entire input is parsed through
		while (ciphertextCopy.size() >= m) {

			//swaps small segment according to current permutation
			for (int i = 0; i < m; i++) {

				decrText += ciphertextCopy[perms[i]];

			}

			ciphertextCopy = ciphertextCopy.substr(m, ciphertextCopy.size());

		}

		if (isValidText(decrText)) {
		//if (true) {

			//show permutation
			outFile << "{";
			for (int i = 0; i < m; i++) {

				outFile << perms[i];

				if (i != m - 1) {

					outFile << ", ";

				}

			}
			outFile << "}" << std::endl;

			outFile << decrText << std::endl << std::endl;
		}

	} while (std::next_permutation(perms.begin(), perms.end()));

	outFile.close();

}

bool MassPermutator::isValidText(std::string decryptedText) {

	//conditon 1: must contain 'THE'
	//conditon 2: every 'Q' must be followed by 'U'
	//must meet both conditions

	bool cond1 = false;
	bool cond2 = true;

	//condition 1
	for (int i = 0; i < decryptedText.size() - 2; i++) {

		if (decryptedText[i] == 'T') {

			if (decryptedText[i + 1] == 'H' && decryptedText[i + 2] == 'E') {

				cond1 = true;

			}

		}

	}

	//condition 2 -- will turn to false if q is found without a following u
	for (int i = 0; i < decryptedText.size() - 1; i++) {

		if (decryptedText[i] == 'Q' && decryptedText[i + 1] != 'U') {

			cond2 = false;

		}

	}

	if (cond1 && cond2) {

		return true;
	}

	return false;

}