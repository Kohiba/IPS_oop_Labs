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

bool checkInput(int argc, char * argv[], int  & temp)
{
	if (argc <= 1)
	{
		printf("Program changes the order of binary bits in the input number to the opposite. \n");
		return false;
	}

	bool isNotNum = false;
	const char * pArg = argv[1];
	temp = StrToInt(pArg, isNotNum);
	if (isNotNum)
	{
		printf("parameter - not the number \n");
		return false;
	}
	else
	{
		if ((temp < 0) || (temp > 255))
		{
			printf("Alert! Parameter < 0  or > 255\n");
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	int numberForExperiments = 0;
	if (!checkInput(argc, argv, numberForExperiments))
	{
		return 1;
	}
	int tempNum = 0;
	for (int i = 0; i < 8; i++)
	{
		tempNum <<= 1;
		tempNum |= (numberForExperiments & 1);
		numberForExperiments >>= 1;
	}
	numberForExperiments = tempNum;
	printf("%d", numberForExperiments);
	return 0;
}

 