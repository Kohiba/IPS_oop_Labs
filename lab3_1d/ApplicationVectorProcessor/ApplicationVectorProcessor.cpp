// ApplicationVectorProcessor.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "VectorProcessor.h"
#include "boost/optional.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include "boost/optional.hpp"



using namespace std;
typedef vector<double> VectorOfDouble;

void ReadVector(VectorOfDouble & arr)
{
	istream_iterator<double> cinIterator(cin);
	istream_iterator<double> endOfStream;
	arr.assign(cinIterator, endOfStream);
}

void WriteVector(VectorOfDouble & arr)
{
	ostream_iterator<double> output(cout, " ");
	copy(arr.begin(), arr.end(), output);
}
int main()
{
	VectorOfDouble arr;
	ReadVector(arr);
	VectorModificator(arr);
	sort(arr.begin(), arr.end());
	WriteVector(arr);
	return 0;
}
