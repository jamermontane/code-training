#pragma once
#include <vector>
#include <string>
using namespace std;
class CFizzBuff
{
public:
	CFizzBuff();
	~CFizzBuff();


	vector<string> fizzBuzz(int n) 
	{
		vector<string> aw;
		for (int i = 1;i <= n;i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				aw.push_back("fizz buzz");
			}
			else if (i % 3 == 0)
			{
				aw.push_back("fizz");
			}
			else if (i % 5 == 0)
			{
				aw.push_back("buzz");
			}
			
			else
			{
				aw.push_back(to_string(i));
			}
		}
		return aw;
		// write your code here
	}
};

