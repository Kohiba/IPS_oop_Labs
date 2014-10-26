// lab2_1_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "errno.h"
#include "string"

using namespace std;

bool DoCheckParameter(int argc, char * argv[], FILE **pFile)
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
	
	errno_t err = fopen_s(pFile, pArg, "rb");
	if (err)
	{
		cout << "error! Fail specified was not found" << endl;
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

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");
	FILE *fileName = NULL;
	if (!DoCheckParameter(argc, argv, &fileName))
	{
		return 1;
	}
	
	char line[256];
	char *fStr = argv[2];
	int i = 1;
	bool stringIsFound = false;
	while (fgets(line, sizeof(line), fileName))
	{
		char *checkSearch = strstr(line, fStr);
		if (checkSearch != NULL)
		{
			cout << "Line: \"" << fStr << "\" found in line ¹ " << i << endl;
			stringIsFound = true;
		}
		i++;
	}
	if (!stringIsFound)
	{
		cout << "Text not found" << endl;
		return 1;
	}
	fclose(fileName); 
	return 0;
}

