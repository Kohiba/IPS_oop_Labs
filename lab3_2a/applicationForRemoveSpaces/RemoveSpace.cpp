#include "stdafx.h"
#include <string>

using namespace std;
string RemoveExtraSpaces(string const& arg)
{
	string str;
	str.reserve(arg.length());
	if (!arg.empty())
	{
		size_t posStart = arg.find_first_not_of(" ");
		if (posStart != string::npos)
		{
			while (posStart != string::npos)
			{
				size_t posEnd = arg.find_first_of(" ", posStart);
				str.append(arg.substr(posStart, posEnd - posStart));
				str.append(" ");
				posEnd = arg.find_first_not_of(" ", posEnd);
				posStart = posEnd;
			}
			str.pop_back();
		}
	}
	return str;
}