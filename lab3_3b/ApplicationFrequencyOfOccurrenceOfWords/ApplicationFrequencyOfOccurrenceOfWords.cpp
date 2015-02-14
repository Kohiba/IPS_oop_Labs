#include "stdafx.h"
#include "FunctionOccurrenceOfWords.h"
#include "iostream"
#include "string"

using namespace std;

void WriteString(string & inputStr)
{
	if (inputStr.empty())
	{
		cout << "You entered empty string.\n";
	}
	else
	{
		cout << "the frequency of occurrence of words in the input line you: \n " << inputStr << endl;
	}
}

int main()
{
	string strIn;
	cout << " This program calculates the frequency of the words you entered in row.\nEnter string: ";
	getline(cin, strIn);

	string strOut = occurrenceOfWords(strIn);

	WriteString(strOut);
	return 0;
}


