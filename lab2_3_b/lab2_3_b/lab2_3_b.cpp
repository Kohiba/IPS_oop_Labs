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
typedef double matrix[3][3];

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}
bool ReadMatrix(const char *fileName, matrix & m)
{
	FILE *pFile = NULL;
	errno_t err = fopen_s(&pFile, fileName, "rb");
	if (err)
	{
		cout << "error! Fail specified was not found" << endl;
		return false;
	}
	char load_string[200];
	int i = 0;
	int j = 0;
	char *next = NULL;
	char* token = NULL;
	char delims[] = " ,\t\r\n";
	bool isNotNum = false;

	while (fgets(load_string, sizeof(load_string), pFile))
	{
		token = strtok_s(load_string, delims, &next);
		while (token != NULL)
		{
			m[i][j] = StringToDouble(token, isNotNum);
			if (isNotNum)
			{
				cout << "error! Is not numeric" << endl;
				return false;
			}
			j++;
			token = strtok_s(NULL, delims, &next);
		};		
		i++;
		j = 0;
	}
	fclose(pFile);
	return true;
}
void MatrixMultiplication(const matrix m1, const matrix m2, matrix & rezm)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			for (int inner = 0; inner < 3; inner++)
			{
				//cout << rezm[row][col] << " + ";
				rezm[row][col] = rezm[row][col] + (m1[row][inner] * m2[inner][col]);
				//cout << m1[row][inner] << " * " << m2[inner][col] << " = " << rezm[row][col] << endl;
			}
		}
	}
}
void OutputMatrix(const matrix m)
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			printf("%10.3f", m[i][j]);
			//cout << setw(6) << setprecision(3) << m[i][j] << " ";
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
	matrix m1 = {0};
	matrix m2 = {0};
	if (!ReadMatrix(argv[1], m1) || !ReadMatrix(argv[2], m2))
	{
		return 1;
	}
	matrix resultMatrix = {0};
	MatrixMultiplication(m1, m2, resultMatrix);
	OutputMatrix(resultMatrix);
    return 0;
}

