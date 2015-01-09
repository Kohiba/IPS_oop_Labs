#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "iostream"
#include "numeric"

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