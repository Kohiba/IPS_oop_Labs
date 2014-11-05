// Lab2_3_b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "errno.h"
#include "string"
//#include "iostream.h"
#include "iomanip" 
using namespace std;

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}
bool DoCheckParameter(int argc, int i, char * argv[], FILE **pFile)
{
	if (argc <= i)
	{
		cout << "error. NOT parameters" << endl << "for example : input1.txt input2.txt " << endl;
		return false;
	}
	char *pArg = argv[i];
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
	return true;
}
void ParseFileIntoArray(FILE **fileName, double matr1[3][3])
{
	char load_string[250];
	int i = 0;
	int j = 0;
	char *next;
	bool isNotNum = false;
	while (fgets(load_string, sizeof(load_string), *fileName))
	{
		char *str = strtok_s(load_string, "	", &next);
		do
		{
			matr1[i][j] = StringToDouble(str, isNotNum);
			j++;
		} while (str = strtok_s(NULL, "	", &next));
		i++;
		j = 0;
	}
}
void MatrixMultiplication(double matr1[3][3], double matr2[3][3], double resultMatr[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			for (int inner = 0; inner < 3; inner++)
			{
				resultMatr[row][col] += matr1[row][inner] * matr2[inner][col];
			}
		}
	}
}
void OutputMatrix(double matr[3][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			printf("%10.3f", matr[i][j]);
			//cout << setw(6) << setprecision(3) << resultMatr[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	FILE *matrix = NULL;
	int parameterCount = 1;
	double matr1[3][3] = { 0 };
	if (!DoCheckParameter(argc, parameterCount, argv, &matrix))
	{
		return 1;
	}
	ParseFileIntoArray(&matrix, matr1);
	double matr2[3][3] = { 0 };
	parameterCount++;
	if (!DoCheckParameter(argc, parameterCount, argv, &matrix))
	{
		return 1;
	}
	ParseFileIntoArray(&matrix, matr2);
	double resultMatr[3][3] = {0};
	MatrixMultiplication(matr1, matr2, resultMatr);
	OutputMatrix(resultMatr);
	return 0;
}

