#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "iostream"
#include "numeric"

double CalculateAmountMinimum3Elements(std::vector<double> & numbers)
{
	/*sort(numbers.begin(), numbers.end());
	numbers.resize(3);
	double sum = 0;
	for (int i = 0; i < 3; ++i)
	{
		sum += numbers[i];
	}*/
	std::vector<int> v1(3);
	std::partial_sort_copy(numbers.begin(), numbers.end(), v1.begin(), v1.end());
	double sum = 0;
	for (double a : v1)
	{
		sum += a;
	}
	return sum;
}

void VectorModificator(std::vector<double> & numbers)
{
	if (!numbers.empty())
	{
		double sumMinNumber = 0;
		std::vector<double> minElts(3);
		std::partial_sort_copy(numbers.begin(), numbers.end(), minElts.begin(), minElts.end());
		for (double elt : minElts)
		{
			sumMinNumber += elt;
		}
		transform(numbers.begin(), numbers.end(), numbers.begin(),
			[sumMinNumber](double item) {
				item += sumMinNumber;
				return item;
		});
	}
}