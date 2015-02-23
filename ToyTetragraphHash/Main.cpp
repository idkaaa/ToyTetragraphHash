//Author: Christopher Lee Hiles
//2015-02-13
//Entry point example for the ToyTetragraphHash class.
//Hashes a string and returns the hash.
//Basically:
//The idea is to use consume a string to repeatedly fill in a set sized grid with characters that are converted to ints.
//round 1:
//A vector takes the running total result which is initially filled with 0's. 
//vector[i] = sum of column % 26. (26 is # of letters in alphabet)
//round 2: 
//Each row in the original grid is shifted left by a different amount.
//vector[i] = sum of column % 26. (again)
//repeat the process until all characters in string have been consumed.
//convert back to characters and output hash.


#include "ToyTetragraphHash.h"
#include <iostream>
#include <fstream>

using namespace std;

//entry point
void main()
{

	string inputFile = "strings.txt";

	//loop through each line of strings in strings.txt
	std::ifstream input(inputFile);

	cout << "Reading " << inputFile << "...\n\n";

	for (std::string line; getline(input, line);)
	{
		ToyTetragraphHash m_hasher;

		m_hasher.hashAString(line);

		m_hasher.printHash();

	}


	cout << "press any key to exit...";

	cin.get();

	return;
}