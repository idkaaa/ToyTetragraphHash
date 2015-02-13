#include "ToyTetragraphHash.h"

using namespace std;

//entry point
void main()
{
	string testString = "ABCDEFGHIJKLMNOP";
	string* hash;
	ToyTetragraphHash testHash;

	hash = testHash.hashAString(testString);

	return;
}