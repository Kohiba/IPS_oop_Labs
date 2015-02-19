// Car.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "ClassCar.h"
#include "string"
#include "iostream"
#include "Handler.h"

int main()
{
	CCar car;
	CHandler handler(car);
	std::string command;
	while (std::cin >> command)
	{
		handler.ExecuteCommand(command);
	}
	return 0;
}

