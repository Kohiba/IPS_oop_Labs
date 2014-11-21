// lab2_2_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

int StrToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

bool CheckInput(int argc, char * argv[], int & numberForReverse)
{
	if (argc <= 1)
	{
		printf("Program changes the order of binary bits in the input number to the opposite. \n");
		return false;
	}

	bool isNotNum = false;
	const char * pFirstArgument = argv[1];
	numberForReverse = StrToInt(pFirstArgument, isNotNum);
	if (isNotNum)
	{
		printf("parameter - not the number \n");
		return false;
	}
	if ((numberForReverse < 0) || (numberForReverse > 255))
	{
		printf("Alert! Parameter < 0  or > 255\n");
		return false;
	}
	return true;
}
void ReversNumber(int & number)
{
	int tempNum = 0;
	for (int i = 0; i < 8; i++)
	{
		tempNum <<= 1;
		tempNum |= (number & 1);
		number >>= 1;
	}
	number = tempNum;
}

int main(int argc, char* argv[])
{
	int numberForReverse = 0;
	if (!CheckInput(argc, argv, numberForReverse))
	{
		return 1;
	}
	ReversNumber(numberForReverse);
	printf("%d", numberForReverse);
	return 0;
}