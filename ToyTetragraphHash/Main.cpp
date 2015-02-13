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

using namespace std;

//entry point
void main()
{
	string testString;
	string hash;

	//example1
	testString = "ABCDEFGHIJKLMNOP";
	cout << "String to Hash: "<< testString << "\n";

	ToyTetragraphHash testHash1;

	hash = testHash1.hashAString(testString);
	
	cout << "Hash: " << hash << "\n";


	//example2
	testString = "AB!CDEFGH,IJKLmn OP;";
	cout << "String to Hash: " << testString << "\n";


	ToyTetragraphHash testHash2;

	hash = testHash2.hashAString(testString);

	cout << "Hash: " << hash << "\n";

	
	
	//example3
	testString = "ABCDEFGHIJKLMNOPQ";
	cout << "String to Hash: " << testString << "\n";


	ToyTetragraphHash testHash3;

	hash = testHash3.hashAString(testString);

	cout << "Hash: " << hash << "\n";



	//example4
	testString = "ABCDEFGHIJKLMNOPABCDEFGHIJKLMNOPABCDEFGHIJKLMNOP";
	cout << "String to Hash: " << testString << "\n";


	ToyTetragraphHash testHash4;

	hash = testHash4.hashAString(testString);

	cout << "Hash: " << hash << "\n";

	//example5
	testString = "AACDEFGHIJKLMNOP";
	cout << "String to Hash: " << testString << "\n";


	ToyTetragraphHash testHash5;

	hash = testHash5.hashAString(testString);

	cout << "Hash: " << hash << "\n";


	return;
}