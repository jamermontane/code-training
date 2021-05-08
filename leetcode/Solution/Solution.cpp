// Solution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <list>
#include <stack>
#include <algorithm>
#include <numeric>

#include "ParkingSystem.h"

using namespace std;



void PrintIntVector(vector<int> vec)
{
	for (int i = 0;i < vec.size();i++)
	{
		cout << vec[i] << "  ";
	}
	cout << endl;
}

void PrintStringVector(vector<string> vec)
{
	for (int i = 0;i < vec.size();i++)
	{
		cout << vec[i] << "  ";
	}
	cout << endl;
}

void PrintIntList(list<int> lst)
{
	if (lst.size() == 0)
	{
		cout << "Empty";
		return;
	}
	for (list<int>::iterator itr = lst.begin();itr != lst.end();itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;
}



int minimumTimeRequired(vector<int>& jobs, int k) 
{
	return 0;
}

vector<int> runningSum(vector<int>& nums) 
{
	int size = nums.size();
	vector<int>::iterator begin = nums.begin();
	vector<int> ans;
	for (int i = 1;i <= size;i++)
	{
		int end = i;
		int t = accumulate(begin, begin + i, 0);
		ans.push_back(t);
	}
	return ans;
}

string reverseLeftWords(string s, int n) 
{
	int size = s.size();
	s.insert(size,s.substr(0, n));
	s.erase(0,n);
	return s;
// 	string sub = s.substr(0, n);
// 	string t = s.substr(n, size - n);
// 	return t + sub;
}

int numIdenticalPairs(vector<int>& nums) 
{
	int size = nums.size();
	int ans = 0;
	for (int i = 0;i < size - 1;i++)
	{
		for (int j = i+1 ;j < size;j++)
		{
			if (nums[i] == nums[j])
			{
				ans++;
			}
		}
	}
	return ans;
}

#pragma region Solutions

void S771()
{
	string jewels = "ZZ";
	string stones = "z";
	int size = jewels.size();
	int ans = 0;
	string::iterator begin = stones.begin();
	string::iterator end = stones.end();
	for (int i = 0;i < size;i++)
	{
		ans += count(begin, end, jewels[i]);
	}
	cout << ans;
}

void S1486()
{
	int n = 5;
	int start = 0;
	int ans = start;
	for (int i = 1;i < n;i++)
	{
		ans ^= (start + 2 * i);
	}
	cout << ans;
}

void S1480()
{
	vector<int> nums = { 1,2,3,4 };
	PrintIntVector(runningSum(nums));
}

void S1512()
{
	vector<int> nums = { 1,2,3};
	cout << numIdenticalPairs(nums);
}

void S1603()
{
	ParkingSystem ps(1, 1, 0);
	cout << ps.addCar(1) << endl;
	cout << ps.addCar(2) << endl;
	cout << ps.addCar(3) << endl;
	cout << ps.addCar(1) << endl;
}

void S1672()
{
	vector<vector<int>> accounts = { {2,8,7},{7,1,3},{1,9,5} };
	int size = accounts.size();
	int max = INT_MIN;
	for (int i = 0;i < size;i++)
	{
		int t = accumulate(accounts[i].begin(), accounts[i].end(), 0);
		if (t >= max) max = t;
	}
	cout << max;
}

void S1720()
{
	vector<int> encoded = { 1,2,3 };
	int first = 1;
	encoded.emplace(encoded.begin(), first);
	int size = encoded.size();
	for (int i = 1;i < size;i++)
	{
// 		int m = encoded[i - 1];
// 		int n = encoded[i];
// 		n ^= m;

		encoded[i] ^= encoded[i - 1];
	}
	PrintIntVector(encoded);

}

void S1723()
{
	vector<int> jobs = { 1,2,4,7,8 };
	int k = 2;
}

#pragma endregion

#pragma region ½£Ö¸ Offer 58

void Offer58_II()
{
	string s = "abcdefg";
	int k = 2;
	cout << reverseLeftWords(s, k);
}


#pragma endregion




int main()
{
	clock_t start = clock();
	S1603();
	cout << endl;
	cout << "TotalTime: " << (double)(clock() - start) / CLOCKS_PER_SEC;
    return 0;
}

