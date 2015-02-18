#include "stdafx.h"
#include "FunctionPrimeNumbersSet.h"
#include "set"
#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	//set<int> numbers = {2};
	//for (int i = 3; i <= upperBound; i = i + 2)
	//{
	//	numbers.insert(i);
	//}

	//for (int i = 3; i <= upperBound; i++)
	//{
	//	if (numbers.find(i) != numbers.end())
	//	{
	//		for (int j = i; j <= upperBound / 2; j++)
	//		{
	//			if (numbers.find(i*j) != numbers.end())
	//			{
	//				numbers.erase(i*j);
	//			}
	//		}
	//	}
	//}
	//return numbers;
	if (upperBound < 2)
	{
		set<int> primeNumbers = {};
		return primeNumbers;
	}
	vector<bool> numbers(upperBound+1);
	//int lim = sqrt(upperBound);
	for (int i = 2; i*i <= upperBound; i++)
	{	
		if (!numbers[i])
		{
			for (int j = i*i; j <= upperBound; j += i)
			{
				if (!numbers[j])
				{
					numbers[j] = true;
				}
			}
		}
	}
	set<int> primeNumbers = {2};
	for (int i =2; i <= upperBound; i++)
	{
		if (!numbers[i])
		{
			primeNumbers.insert(i);
		}
	}

	return primeNumbers;
}