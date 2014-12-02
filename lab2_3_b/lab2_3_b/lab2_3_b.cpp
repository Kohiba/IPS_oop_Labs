// Lab2_3_b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "errno.h"
#include "string"
#include "iomanip"
#include "fstream"

using namespace std;
typedef double Matrix3x3[3][3];

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

bool ReadMatrix(const char *fileName, Matrix3x3 & m)
{
	FILE *pFile = NULL;
	errno_t err = fopen_s(&pFile, fileName, "rb");
	if (err)
	{
		cout << "error! Fail specified was not found" << endl;
		return false;
	}
	char load_string[200];
	int row = 0;
	int column = 0;
	char *next = NULL;
	char* token = NULL;
	static const char delims[] = " ,\t\r\n";
	
	memset(m, 0, sizeof(m));
	while (fgets(load_string, sizeof(load_string), pFile))
	{
		token = strtok_s(load_string, delims, &next);
		while (token != NULL)
		{
			bool isNotNum = false;
			m[row][column] = StringToDouble(token, isNotNum);
			if (isNotNum)
			{
				cout << "error! Is not numeric" << endl;
				return false;
			}
			column++;
			token = strtok_s(NULL, delims, &next);
			if (column == 3)
			{
				break;
			}
		}
		row++;
		column = 0;
		if (row == 3)
		{
			break;
		}
	}
	fclose(pFile);
	return true;
}

void MatrixMultiplication(const Matrix3x3 m1, const Matrix3x3 m2, Matrix3x3 & rezm)
{
	memset(rezm, 0, sizeof(rezm));
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			for (int inner = 0; inner < 3; inner++)
			{
				rezm[row][col] = rezm[row][col] + (m1[row][inner] * m2[inner][col]);
			}
		}
	}
}

void OutputMatrix(const Matrix3x3 m)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%10.3f", m[i][j]);
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "error. NOT parameters" << endl << "for example : input1.txt input2.txt " << endl;
		return 1;
	}
	Matrix3x3 m1;
	Matrix3x3 m2;
	if (!ReadMatrix(argv[1], m1) || !ReadMatrix(argv[2], m2))
	{
		return 1;
	}
	Matrix3x3 resultMatrix;
	MatrixMultiplication(m1, m2, resultMatrix);
	OutputMatrix(resultMatrix);
    return 0;
}

