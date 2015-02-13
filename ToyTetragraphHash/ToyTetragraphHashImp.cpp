#include "ToyTetragraphHash.h"

//public interface for alphanumeric string hashing. 
//Default chunk size of 16 (4x4 matrix).
//returns a pointer to the alphanumeric hash
string* ToyTetragraphHash::hashAString(string inputString)
{
	int chunkSize = 16;
	const int maxRows = 4, maxCols = 4;
	bool chunkFilled = false;
	string::iterator stringPosition = inputString.begin();
	

	//start spooling up alphanumerics to be chunked
	while (!chunkFilled)
	{	
		//one whole chunk
		int chunk[maxRows][maxCols];
		for (int i = 0; i < maxRows; ++i)
		{
			for (int j = 0; j < maxCols; ++j)
			{
				if (isLetter(*stringPosition))
				{
					chunk[i][j] = digestValidCharacter(*stringPosition);
				}
				else{
					chunk[i][j] = NULL;
				}
			}
		}
		//send chunk off to be processed

		if (stringPosition != inputString.end())

	}



};

bool ToyTetragraphHash::isLetter(char& c)
{
	return isalnum(c);
};

int ToyTetragraphHash::digestValidCharacter(char& c)
{
	int v = toupper(c);
	
	
}