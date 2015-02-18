// TestFunctionPrimeNumbersSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../PrimeNumbersSet/FunctionPrimeNumbersSet.h"
#include "set"

BOOST_AUTO_TEST_SUITE(TestFunctionPrimeNumbersSet)
BOOST_AUTO_TEST_CASE(ItsAllRight)
{
	BOOST_CHECK(2*2==4);
}


BOOST_AUTO_TEST_CASE(IfUpperBoundIsLess2)
{
	std::set<int> testSet1 = GeneratePrimeNumbersSet(1);
	std::set<int> testSet2 = {};
	BOOST_CHECK(testSet1 == testSet2);
	testSet1 = GeneratePrimeNumbersSet(0);
	BOOST_CHECK(testSet1 == testSet2);
	testSet1 = GeneratePrimeNumbersSet(-1);
	BOOST_CHECK(testSet1 == testSet2);
	testSet1 = GeneratePrimeNumbersSet(-1000);
	BOOST_CHECK(testSet1 == testSet2);
}

BOOST_AUTO_TEST_CASE(IfUpperBoundIs2)
{	
	std::set<int> testSet1 = GeneratePrimeNumbersSet(2);
	std::set<int> testSet2 = {2};
	BOOST_CHECK(testSet1 == testSet2);
}

BOOST_AUTO_TEST_CASE(IfUpperBoundAroundPrimeNumber11)
{
	std::set<int> testSet1 = GeneratePrimeNumbersSet(10);
	std::set<int> testSet2 = { 2, 3, 5, 7 };
	BOOST_CHECK(testSet1 == testSet2);
	testSet1 = GeneratePrimeNumbersSet(11);
	testSet2 = { 2, 3, 5, 7, 11 };
	BOOST_CHECK(testSet1 == testSet2);
	testSet1 = GeneratePrimeNumbersSet(12);
	testSet2 = { 2, 3, 5, 7, 11 };
	BOOST_CHECK(testSet1 == testSet2);
}
BOOST_AUTO_TEST_CASE(IfUpperBoundIs100)
{
	std::set<int> testSet1 = GeneratePrimeNumbersSet(100);
	std::set<int> testSet2 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	BOOST_CHECK(testSet1 == testSet2);
}
BOOST_AUTO_TEST_SUITE_END();