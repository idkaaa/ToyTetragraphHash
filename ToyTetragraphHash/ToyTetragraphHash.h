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
	int digestCharacter(char& yummyChar);
	char regurgitateCharacter(int& nastyInt);
	bool isLetter(char& maybeChar);
	void leftShiftRow(int rowIndex, int numberOfShifts);
	int sumColumn(int colIndex);
	string* padString(string& stringToPad, int padLength);


	//data
	vector<int> result;
};

#endif