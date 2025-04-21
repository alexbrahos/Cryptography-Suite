All the software I wrote for this assignment was combined into one large cipher-cracking suite. The main menu is in crypto.cpp.
To select the text file to use with the program, include it as a command-line argument. e.g. './a.out cipher1.txt'

All ciphertext is assumed to be all caps. Non capital letters are never changed, and simply re-added to plaintext. All plaintext results are all lowercase.

---Crypto.cpp---
This is the main menu of the program. Select an option by entering the number only. Any other entry will close the program.

---[1] Frequency Analysis---
This class saves an array of integers (size 26). The array contains the frequency of each letter, starting from A=0.
The frequency and percentage of each letter is printed to the console upon construction, and the frequency array can be used by other programs with <objName>.getFrequency()

---[2] Substitution Solver---
Upon selecting this option, the entire ciphertext will be displayed. Enter a letter you wish to replace, then enter the letter that will replace it.
This lets you manually solve monoalphabetic substituion ciphers. Automation was not necessary, as this is an easy cipher to crack by hand.
Upon exiting, whatever was last printed to the console is saved to a file called 'decryptedSubstitution.txt'.

---[3] Hill Matrix Finder---
This program is a brute-force approach to cracking a hill cipher with a 2x2 matrix.
All 2x2 matrices with values 0-29 are tested and output to a file named 'hillMatrices.txt'.
Only the first several characters are saved for each cipher to save time. This is all that is necessary to see if the result is gibberish or not.

---[4] Hill Solver---
This program requires the user to input a known 2x2 inverse key matrix by entering the values one at a time (k11, k12, k21, k22).
The inputted matrix is used to decrypt, and the result is saved to a file called 'decryptedHill.txt'.

---[5] Index of Coincidence---
This program calculates the index of coincidence for a ciphertext split into up to 10 substrings.
The index of coincidence for each substring is saved to a file called 'IoCResults.txt'.

---[6] Vigenere Shifter---
This program takes a ciphertext and outputs the most likely keyword for a vigenere cipher of this text.
The user is asked to input the length of the keyword. A keyword of that length is output.
An alternate but also somewhat likely letter for each position is also suggested.

---[7] Vigenere Solver---
This program solves a vigenere cipher with a given keyword. The user must input the keyword in all caps.
The decrypted text is output to a file called 'decryptedVigenere.txt'.

---[8] Mass Permutator---
This program takes a ciphertext and generates all permutations of the text with a given block size (input by user).
It is likely the plaintext will contain the word 'the', so all results without this word are tossed and not saved.
The letter q is also very likely to be followed by the letter u, so results with a q not followed by u are tossed.
All remaining/valid results are saved to a file called 'MassPerms.txt'.

---[9] Permutator----
This program takes a ciphertext asks the user to input the block size, and then permutation function one value at a time.
The program then decrypts the cipher with these inputs, stripping then re-adding non alphabetic characters.
The result is saved to a file called 'decryptedPermutation.txt'.

---Txt2String---
This is not an option in the menu, but rather a tool I made to easily convert txt files to strings without having to mess around with file streams.