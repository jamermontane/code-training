#pragma once
#include <vector>
using namespace std;
class CYangHuisTriangle
{
public:
	CYangHuisTriangle();
	~CYangHuisTriangle();

	vector<vector<int>> calcByN(int n)
	{
		vector<vector<int>> aw;
		for (int i = 1;i <= n;i++)
		{
			if (i == 1)
			{
				vector<int> t;
				t.push_back(1);
				aw.push_back(t);
			}
			else if (i == 2)
			{
				vector<int> t;
				t.push_back(1);
				t.push_back(1);
				aw.push_back(t);
			}
			else
			{
				vector<int> t;
				t.push_back(1);
				for (int j = 1;j < aw[i-2].size();j++)
				{
					t.push_back(aw[i - 2][j - 1] + aw[i - 2][j]);
				}
				t.push_back(1);
				aw.push_back(t);
			}
		}
		return aw;
	}
};

