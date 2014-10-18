// lab1_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

int SumDigits(int i)
{
	int sum = 0;
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int	parameter = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return parameter;
}


int main(int argc, char *argv[])
{
	//parameter string is empty?
	if (argc <= 1)
	{
		printf("not arguments.\n");
		return 0;
	}
	//parameter is the number?
	bool err;
	int upperBound = StringToInt(argv[1], err);
	if (err)
	{
		printf("Argument is not a number\n.");
		return 1;
	}
	if (upperBound <= 1)
	{
		printf("Argument <= 1\n.");
		return 1;
	}
	for (int i = 1; i <= upperBound; ++i)
	{
		if (i % SumDigits(i) == 0)
		{
			if (i <= upperBound && i != 1)
			{
				printf(", ");
			}
			printf("%d", i);
			
		}
	}
	printf("\n");
	return 0;
}