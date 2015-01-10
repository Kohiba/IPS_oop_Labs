// applicationForRemoveSpaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RemoveSpace.h"
#include "boost/optional.hpp"
#include "iostream" 
#include "string"

using namespace std; 

void ReadString(string & inputStr)
{
	cout << " Program removes extra spaces.\nEnter string: ";
	getline(cin, inputStr);
}

void WriteString(string & inputStr)
{
	if (inputStr.empty())
	{
		cout << "You entered empty string.\n";
	}
	else
	{
		cout << "String before removing spaces: " << inputStr << endl;
	}
}

int main()
{
	string  inputStr;
	ReadString(inputStr);
	inputStr = RemoveExtraSpaces(inputStr);
	WriteString(inputStr);
	return 0;
}

