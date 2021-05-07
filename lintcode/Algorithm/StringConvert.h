#pragma once

#include <vector>
#include <string>
using namespace std;

class CStringConvert
{
public:
	CStringConvert();
	~CStringConvert();

	int ConvertToInt(string str)
	{
		return stoi(str);
	}
};

