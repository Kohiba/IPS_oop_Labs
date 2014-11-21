// lab2_1_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream"
#include "stdio.h"
#include "iostream"
#include "errno.h"
#include "string"

using namespace std;

bool DoCheckParameter(int argc, char * argv[])
{
	if (argc <= 1)
	{
		cout << "This program searches for specified string in the specified file." << endl
		     << "for example : \"input.txt\" \"search line\" " << endl;
		return false;
	}
	char *pArg = argv[1];

	char *point = strchr(pArg, '.');
	if (point == NULL)
	{
		cout << "error! Filename incorrectly. Enter a file name such as \"input.txt\"" << endl;
		return false;
	}
	
	pArg = argv[2];
	if ((pArg == NULL) || strcmp(pArg, "") == 0)
	{
		cout << "error! Not enter the search string" << endl;
		return false;
	}
	return true;
}
bool SearchStringInFile(const string & searchString, char * fileName)
{
	ifstream strm(fileName);
	string line;
	int i = 1;
	bool stringIsFound = false;
	while (getline(strm, line))
	{
		if (line.find(searchString) != string::npos)
		{
			cout << "Line: \"" << searchString << "\" found in line ¹ " << i << endl;
			stringIsFound = true;
		}
		i++;
	}
	if (!stringIsFound)
	{
		cout << "Text not found" << endl;
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (!DoCheckParameter(argc, argv))
	{
		return 1;
	}
	if (!SearchStringInFile(argv[2], argv[1]))
	{
		return 1;
	}
	return 0;
}