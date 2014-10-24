// lab1_5_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "iostream"

int StrToInt(char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

bool DoEnterParameter()
{
	char *value1;
	char *value2;
	do
		printf("Enter v0 (or type ‘exit’)> ");
		scanf("%s", &value1);
		if (value1 == "exit")
		{
			printf("\nGoodbye\n");
			return false;
		}
		printf("\n");
	while (value1 == );
	
	do
	printf("Enter v0 (or type ‘exit’)> ");
	scanf_s("%d", &value2);
	if (value1 == "exit")
	{
		printf("\nGoodbye\n");
		return false;
	}
	printf("\n");
	while (value1 == 0);
}
int main(int argc, char *argv[])
{
	int value1 = 0;
	int value2 = 0;
	
	printf("Enter v0 (or type ‘exit’)> ");
	scanf_s("%d", &value1);
	printf("\n");

	//bool isNotNum = false;
	//int initVelocity = StrToInt(value1, isNotNum);
	//if (!isNotNum)
	//{
	//	printf("Entering not number");
	//	return -1;
	//}
	
	printf("Enter a0 (or type ‘exit’)> ");
	scanf_s("%d", &value2);

	/*int initDegree = StrToInt(value2, isNotNum);
	if (!isNotNum)
	{
		printf("Entering not number");
		return -1;
	}
	*/

	printf("v0 - %d \na0 - %d", value1, value2);
	return 0;
}

