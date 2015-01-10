// TestRemoveSpaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../applicationForRemoveSpaces/RemoveSpace.h"


BOOST_AUTO_TEST_SUITE(stringTests)

BOOST_AUTO_TEST_CASE(EverythingIsOk)
{
	BOOST_CHECK_EQUAL(2 * 2, 4);
}
BOOST_AUTO_TEST_CASE(IfEmptyString)
{
	string str1 = "";
	string str2 = RemoveExtraSpaces(str1);
	BOOST_CHECK_EQUAL(str2, "");
}
BOOST_AUTO_TEST_CASE(IfOnlySpaceString)
{
	string str1 = "     ";
	string str2 = RemoveExtraSpaces(str1);
	BOOST_CHECK_EQUAL(str2, "");
}
BOOST_AUTO_TEST_CASE(IfSpaceAnd1SimbolString)
{
	string str1 = "  A   ";
	string str2 = RemoveExtraSpaces(str1);
	BOOST_CHECK_EQUAL(str2, "A");
}

BOOST_AUTO_TEST_CASE(IfFirstSymbolIsNotSpace)
{
	string str1 = "Test string ";
	string str2 = RemoveExtraSpaces(str1);
	BOOST_CHECK_EQUAL(str2, "Test string");
}

BOOST_AUTO_TEST_CASE(IfLastSymbolIsNotSpace)
{
	string str1 = " Test string";
	string str2 = RemoveExtraSpaces(str1);
	BOOST_CHECK_EQUAL(str2, "Test string");
}

BOOST_AUTO_TEST_CASE(IfLongString)
{
	string str1 = "        Searches            the basic_string for the              first character             that does not match any of the                         characters specified in its arguments.        ";
	string str2 = RemoveExtraSpaces(str1);
	BOOST_CHECK_EQUAL(str2, "Searches the basic_string for the first character that does not match any of the characters specified in its arguments.");
}

BOOST_AUTO_TEST_SUITE_END()
