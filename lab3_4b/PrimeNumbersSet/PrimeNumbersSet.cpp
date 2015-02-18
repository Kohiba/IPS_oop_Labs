// PrimeNumbersSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FunctionPrimeNumbersSet.h"
#include "iostream"
#include "iterator"
#include "set"

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		cout << "Program finds prime numbers in the range from 2 to N." << endl 
			 << "N Specify the parameters start the program." << endl 
			 << "N = Maximum 100 000 000" << endl;
		return 1;
	}
	bool err;
	int upperBound = StringToInt(argv[1], err);
	if (err)
	{
		cout << "Argument not a number\n.";
		return 1;
	}
	
	set<int> primeNumber = GeneratePrimeNumbersSet(upperBound);

	cout << "Prime numbers are:\n";
	copy(primeNumber.begin(), primeNumber.end(), ostream_iterator<int>(cout, ", "));
	cout << "\n";
	
	return 0;
}

