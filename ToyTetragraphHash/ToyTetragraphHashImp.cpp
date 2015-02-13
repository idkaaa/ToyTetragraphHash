//Author: Christopher Lee Hiles
//2015-02-13
//Implementation file for the ToyTetragraphHash class


#include "ToyTetragraphHash.h"

//public interface for alpha string hashing. 
//Default chunk size of 16 (4x4 matrix).
//returns a pointer to the alpha hash
string ToyTetragraphHash::hashAString(string inputString)
{
	int chunkSize = 16;
	const int maxRows = 4, maxCols = 4;
	bool chunkFilled = false;
	int moduloNumber = 26;
	string hash;



	//init
	sterilizeString(inputString);
	g_result = { 0, 0, 0, 0 };

	while (!inputString.empty())
	{
		//round1
		fillChunk(inputString, maxRows, maxCols);
		calculateResult(moduloNumber, maxRows, maxCols);
		

		//round2
		for (int i = 0; i < maxRows-1; ++i)
		{
			leftShiftRow(i, i + 1);
		}
		//reverse the last row
		reverseRow(maxRows-1);
		calculateResult(moduloNumber, maxRows, maxCols);
	}

	//finish up by converting resulting hash back to alphas
	for (int i = 0; i < maxCols; ++i)
	{
		char c = (g_result.back() + 65);//coerce back to ASCII uppercase so A=0;
		g_result.pop_back();

		hash.insert(hash.begin(), c);
	}


	
	

	return hash;

};


void ToyTetragraphHash::reverseRow(int rowIndex)
{
	reverse(g_chunk[rowIndex].begin(), g_chunk[rowIndex].end());
	return;
}


void ToyTetragraphHash::leftShiftRow(int rowIndex, int numOfShifts)
{ 
	rotate(g_chunk[rowIndex].begin(), g_chunk[rowIndex].begin() + numOfShifts, g_chunk[rowIndex].end());
	return;
}

//sums column then calculates remainder after modulo and places in vector location
bool ToyTetragraphHash::calculateResult(int modulo, int maxRows, int maxCols)
{
	for (int i = 0; i < maxCols; i++)
	{
		int sum = sumColumn(i, maxRows);
		g_result[i] = ((g_result[i] + sum) % modulo);
	}

	return true;
}

int ToyTetragraphHash::sumColumn(int colIndex, int maxRows)
{
	int sum = 0;
	for (int i = 0; i < maxRows; ++i)
	{
		sum += g_chunk[i][colIndex];
	}

	return sum;
}

bool ToyTetragraphHash::sterilizeString(string& dirtyString)
{

	string cleanString;

	string::iterator lastPosition = dirtyString.end();
	
	for (string::iterator it = dirtyString.begin(); it != dirtyString.end(); ++it)
	{
		if (isalpha(*it))
		{
			cleanString.push_back(*it);
		}
	}

	dirtyString.clear();
	dirtyString = cleanString;
	return true;
}

//fills chunk. inserts NULLS if string is empty.
bool ToyTetragraphHash::fillChunk(string& validChars, int maxRows, int maxCols)
{	
	//clear chunk
	g_chunk.clear();

	for (int i = 0; i < maxRows; ++i)
	{
		g_chunk.push_back(vector<int>());
		for (int j = 0; j < maxCols; ++j)
		{
			g_chunk[i].push_back( consumeValidCharacter(validChars));
		}
	}
	return true;
}

//returns NULL if string is empty
char ToyTetragraphHash::consumeValidCharacter(string& validChars)
{
	if (!validChars.empty())
	{
		char v = validChars.front();

		validChars.erase(validChars.begin());

		return toupper(v);
	}
	else{
		return NULL;
	}
	
}

bool ToyTetragraphHash::isLetter(char& c)
{
	return isalnum(c);
};

