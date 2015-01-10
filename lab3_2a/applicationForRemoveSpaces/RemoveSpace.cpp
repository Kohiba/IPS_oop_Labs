#include "stdafx.h"
#include "string"

using namespace std;
string RemoveExtraSpaces(string const& arg)
{
	string str;
	if (!arg.empty())
	{
		int posStart = arg.find_first_not_of(" ");
		if (posStart != string::npos)
		{
			while (posStart != string::npos)
			{
				int posEnd = arg.find_first_of(" ", posStart);
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