// lab1_4_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <limits.h>

int StrToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

bool CheckUpperBound(int argc, char * argv[], int & parameter)
{
	if (argc <= 1)
	{
		printf("Program outputs the Fibonacci numbers to the number you entered.\n");
		return false;
	}

	bool isNotNum = false;
	const char * pArg = argv[1];
	parameter = StrToInt(pArg, isNotNum);
	if (isNotNum)
	{
		printf("parameter - not the number \n");
		return false;
	}
	else
	{
		if (parameter == 0)
		{
			printf("Alert! Entering parameter = 0");
			return false;
		}
	}
	return true;
}

bool CheckOverflowInSum(int arg, int nextArg)
{
	if (INT_MAX - arg <= nextArg)
	{
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	int n = 0;
	if (!CheckUpperBound(argc, argv, n))
	{
		return -1;
	}
	int preNumber = 0;
	int currNumber = 1;
	int lastNumber = 1;
	printf("%d, ", preNumber);
	int i = 1;

	while (lastNumber <= n)
	{
		printf("%d", lastNumber);
		if (CheckOverflowInSum(preNumber, currNumber))
		{
			lastNumber = preNumber + currNumber;
			preNumber = currNumber;
			currNumber = lastNumber;
			i++;
			if ((i != 5) && (lastNumber <= n))
			{
				printf(", ");
			}
			else
			{
				printf("\n");
				i = 0;
			}
		}
		else
		{
			printf("\nAlert! Overflow\n");
			return -1;
		}
	}
	printf("\n");
	return 0;
}

