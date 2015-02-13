//Author: Christopher Lee Hiles
//2015-02-13
//Header file for the ToyTetragraphHash class.
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

#ifndef TOYTETRAGRAPHHASH_H
#define TOYTETRAGRAPHHASH_H
#include <string>
#include <vector>

using namespace std;

class ToyTetragraphHash
{
public:
	string hashAString(string stringToBeHashed);

private:
	//methods
	bool sterilizeString(string& dirtyString);
	bool fillChunk(string&, int maxRows, int maxCols);
	char consumeValidCharacter(string& yummyString);
	bool calculateResult(int moduloNum, int maxRows, int maxCols);
	bool isLetter(char& maybeChar);
	void leftShiftRow(int rowIndex, int numberOfShifts);
	void reverseRow(int rowIndex);
	int sumColumn(int colIndex, int maxRows);
	


	//data
	vector<int> g_result;
	vector<vector<int>> g_chunk;
};

#endif