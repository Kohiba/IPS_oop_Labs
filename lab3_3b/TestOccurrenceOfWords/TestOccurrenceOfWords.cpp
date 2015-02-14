#include "stdafx.h"
#include "../ApplicationFrequencyOfOccurrenceOfWords/FunctionOccurrenceOfWords.h"
#include "string"

BOOST_AUTO_TEST_SUITE(OccurrenceOfWords)
BOOST_AUTO_TEST_CASE(IsAllRight)
{
	BOOST_CHECK(8 == 8);
}

BOOST_AUTO_TEST_CASE(IfInputIsEmpty )
{
	BOOST_CHECK_EQUAL(occurrenceOfWords(""), "");
}
BOOST_AUTO_TEST_CASE(IfInputIsOneWord)
{
	BOOST_CHECK_EQUAL(occurrenceOfWords("one"), "one -> 1 \n ");
}
BOOST_AUTO_TEST_CASE(IfInputIsTwoIdenticalWords)
{
	BOOST_CHECK_EQUAL(occurrenceOfWords("one one"), "one -> 2 \n ");
}
BOOST_AUTO_TEST_CASE(IfInputIsTwoDifferentWords)
{
	std::string out2 = occurrenceOfWords("one two");
	std::string out1 = "one -> 1 \n two -> 1 \n ";
	BOOST_CHECK_EQUAL(out2, out1);
}
BOOST_AUTO_TEST_CASE(IfInputIsManyWords)
{
	std::string out2 = occurrenceOfWords("one two one three four three four");
	std::string out1 = "four -> 2 \n one -> 2 \n three -> 2 \n two -> 1 \n ";
	BOOST_CHECK_EQUAL(out2, out1);
}
BOOST_AUTO_TEST_CASE(IfInputIsManyWordsDifferentCases)
{
	std::string out2 = occurrenceOfWords("oNe two one tHree four three Four");
	std::string out1 = "four -> 2 \n one -> 2 \n three -> 2 \n two -> 1 \n ";
	BOOST_CHECK_EQUAL(out2, out1);
}
BOOST_AUTO_TEST_CASE(IfInputIsManyWordsDifferentCasesAndlanguage)
{
	std::string out2 = occurrenceOfWords("oNe один two one tHree один four three Four два");
	std::string out1 = "four -> 2 \n one -> 2 \n three -> 2 \n two -> 1 \n два -> 1 \n один -> 2 \n ";
	BOOST_CHECK_EQUAL(out2, out1);
}
BOOST_AUTO_TEST_SUITE_END();