// TestVectorProcessor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../ApplicationVectorProcessor/VectorProcessor.h"
#include "vector"

using namespace std;

BOOST_AUTO_TEST_SUITE(VectorTests)

	BOOST_AUTO_TEST_CASE(EverythingIsOk)
	{
		BOOST_CHECK_EQUAL(2 * 2, 4);
	}

	BOOST_AUTO_TEST_CASE(EmptyVector)
	{
		vector<double> v1 = {};
		VectorModificator(v1);
		BOOST_CHECK(v1.empty());
	}
	
	BOOST_AUTO_TEST_CASE(calculationOfTheMinimumElementsWhenTheVectorIsLessThan3Elements)
	{
		vector<double> v1 = { 1 };
		VectorModificator(v1);
		vector<double> v2 = { 2 };
		BOOST_CHECK(v1 == v2);
	}
	BOOST_AUTO_TEST_CASE(Less3ElementNumber)
	{
		vector<double> v1 = { 1, 0 };
		VectorModificator(v1);
		vector<double> v2 = { 2, 1 };
		BOOST_CHECK(v1 == v2);
	}
	BOOST_AUTO_TEST_CASE(calculationOfTheMinimumElementsWhenTheVectorElement3)
	{
		vector<double> v1 = { 1, 7, -5 };
		VectorModificator(v1);
		vector<double> v2 = { 4, 10, -2 };
		BOOST_CHECK(v1 == v2);
	}
	BOOST_AUTO_TEST_CASE(ElementNumber)
	{
		vector<double> v1 = { 1, 4, 2 };
		VectorModificator(v1);
		vector<double> v2 = { 8, 11, 9 };
		BOOST_CHECK(v1 == v2);
	}
	BOOST_AUTO_TEST_CASE(calculationOfTheMinimumElementsWhenTheVectorIsMoreThan3Elements)
	{
		vector<double> v1 = { 1, 4, 8, 1, 2 };
		VectorModificator(v1);
		vector<double> v2 = { 5, 8, 12, 5, 6 };
		BOOST_CHECK(v1 == v2);
	}
BOOST_AUTO_TEST_SUITE_END()