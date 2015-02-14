#include "stdafx.h"
#include "iostream"
#include "FunctionOccurrenceOfWords.h"
#include "string"
#include "map"
#include "iterator"
#include "vector"
#include "algorithm"
#include <sstream>

using namespace std;
typedef map<string, int> TypeMapping;

string occurrenceOfWords(string const str)
{
	if (!str.empty())
	{
		istringstream buf(str);
		istream_iterator<string> beg(buf), end;
		vector<string> words(beg, end);

		TypeMapping mapWords;
		for(string word : words)
		{
			transform(word.begin(), word.end(), word.begin(), tolower);
			mapWords[word]++;
		}

		string strOut = "";
		for (TypeMapping::const_iterator it = mapWords.begin();
			it != mapWords.end();
			++it
			)
		{
			strOut += it->first + " -> " + to_string(it->second) + " \n ";
		}
		return strOut;
	}
	return str;
};