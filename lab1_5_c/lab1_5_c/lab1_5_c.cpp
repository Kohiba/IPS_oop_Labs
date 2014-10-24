// lab1_5_c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "iostream"
#include "math.h"
using namespace std;
#define M_PI 3.14159265358979323846

bool DoEnteringParameters(int &v0, int &a0)
{
	string exit("exit");
	string exitMessage("goodbye");
	string parametr;
	do
	{
		cout << "input v0 (or type ‘exit’) > ";
		cin >> parametr;
		if (parametr == exit)
		{
			cout << exitMessage << endl;
			return false;
		}
		v0 = atoi(parametr.c_str());
	} while (v0 == 0);
	do
	{
		cout << "input a0 (or type ‘exit’) > ";
		cin >> parametr;
		if (parametr == exit)
		{
			cout << exitMessage << endl;
			return false;
		}
		a0 = atoi(parametr.c_str());
	} while (a0 == 0);
	return true;
}

int main(int argc, char* argv[])
{
	int initVelocity = 0;
	int initAngle = 0;
	double g = 9.8;
	double flightRange;
	while (DoEnteringParameters(initVelocity, initAngle))
	{
		flightRange = (pow(initVelocity, 2) * sin(2 * ((initAngle * M_PI) / 180))) / g;
		cout << "Distance is:" << flightRange << endl;
	}
	return 0;
}

