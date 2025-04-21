#include <iostream>
#include <string>
#include "Txt2String.h"
#include "FrequencyAnalysis.h"
#include "Substitution.h"
#include "HillMatrixFinder.h"
#include "HillSolver.h"
#include "IndexOfCoincidence.h"
#include "VigenereShifter.h"
#include "VigenereSolver.h"
#include "MassPermutator.h"
#include "PermSolver.h"

int main(int argc, char** argv) {

	Txt2String stringMaker = Txt2String(argv[1]);
	std::string ciphertext = stringMaker.getContents();

	std::cout << "[1] Frequency Analysis" << std::endl;
	std::cout << "[2] Substitution Solver" << std::endl;
	std::cout << "[3] Hill Matrix Finder" << std::endl;
	std::cout << "[4] Hill Solver (known inverse matrix)" << std::endl;
	std::cout << "[5] Index of Coincidence" << std::endl;
	std::cout << "[6] Vigenere Shifter" << std::endl;
	std::cout << "[7] Vigenere Solver (known keyword)" << std::endl;
	std::cout << "[8] Mass Permutator" << std::endl;
	std::cout << "[9] Permutator (known permutation function)" << std::endl;
	std::cout << "Enter the number of your selection: ";

	std::string input = "";
	std::cin >> input;
	int result = std::stoi(input);

	switch (result) {

		case 1:
		{

			FrequencyAnalysis analyze = FrequencyAnalysis(ciphertext);
			break;

		}

		case 2:
		{
			Substitution substitute = Substitution(ciphertext);
			break;
		}

		case 3:
		{
			HillMatrixFinder hillFinder = HillMatrixFinder(ciphertext);
			break;
		}

		case 4:
		{
			HillSolver hill = HillSolver(ciphertext);
			break;
		}

		case 5:
		{
			IndexOfCoincidence ioc = IndexOfCoincidence(ciphertext);
			break;
		}

		case 6:
		{
			VigenereShifter shifter = VigenereShifter(ciphertext);
			break;

		}

		case 7:
		{
			VigenereSolver vigenere = VigenereSolver(ciphertext);
			break;
		}

		case 8:
		{
			MassPermutator mass = MassPermutator(ciphertext);
			break;
		}

		case 9:
		{
			PermSolver perm = PermSolver(ciphertext);
			break;
		}

	}

	return 0;
}