// lab1_3_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

enum OperationCode
{
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	NONE
};
enum ArgumentType
{
	BEGIN,
	NUMBER,
	OPERATION	
};

OperationCode GetOperation(const char * element)
{
	OperationCode code = NONE;
	switch (*element)
	{
	case '+':
		code = ADDITION;
		break;
	case '-':
		code = SUBTRACTION;
		break;
	case '*':
		code = MULTIPLICATION;
		break;
	case '/':
		code = DIVISION;
		break;
	default:
		code = NONE;
		break;
	}
	return code;
}

// applies operation operation to lhs and rhs operands. the result is stored in lhs
// returns true if operation was applied successfully, false otherwise
bool ApplyOperation(double &lhs, OperationCode operation, double rhs)
{
	switch (operation)
	{
	case ADDITION:
		lhs += rhs;
		break;
	case SUBTRACTION:
		lhs -= rhs;
		break;
	case MULTIPLICATION:
		lhs *= rhs;
		break;
	case DIVISION:
		if (rhs != 0) lhs /= rhs;
		else return false;
		break;
	default:
		lhs = rhs;
		break;
	}
	return true;
}
double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}
bool RememberOperation(ArgumentType & prevArg, OperationCode & operation, const char * pArg)
{
	if (prevArg == OPERATION)
	{
		printf("alert! duplicate operation\n");
		return false;
	}
	else
	{
		operation = GetOperation(pArg);
		if (operation == NONE)
		{
			printf("entering uncorrect operand\n");
			return false;
		}
		printf("%c", *pArg);
		prevArg = OPERATION;
	}
	return true;
}
bool CalculateSubResult(ArgumentType & prevArg, OperationCode operation, double & resultExp, double operand)
{
	if (prevArg == NUMBER)
	{
		printf("alert! duplicate number\n");
		return false;
	}
	else
	{
		if (!ApplyOperation(resultExp, operation, operand))
		{
			printf("alert! Division by zero\n");
			return false;
		}
		printf("%.1f", operand);
		prevArg = NUMBER;
	}
	return true;
}


int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates expression of its command line arguments.\n");
		return -1;
	}
	OperationCode operation = NONE;
	ArgumentType prevArg = BEGIN;
	double resultExp = 0;
	bool isNotNum = false;

	for (int i = 1; i < argc; ++i)
	{
		const char * pArg = argv[i];
		double operand = StringToDouble(pArg, isNotNum);
		if (isNotNum)
		{
			if (!RememberOperation(prevArg, operation, pArg))
			{
				return -1;
			}
		}
		else
		{
			if (!CalculateSubResult(prevArg, operation, resultExp, operand))
			{
				return -1;
			}
		}
	}

	if (prevArg == NUMBER)
	{
		printf(" = %.3f\n", resultExp);
	}
	else
	{
		printf("alert! incorrectly expression\n");
		return -1;
	}
	return 0;
}

