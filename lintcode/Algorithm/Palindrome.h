#pragma once
#include <bitset>
using namespace std;
class CPalindrome
{
public:
	CPalindrome();
	~CPalindrome();

	bool isPalindrome(int n)
	{
// 		bitset<32> t(n);
// 		string str = t.to_string();

		if (n == 0 || n == 1) return true;

		string str = DecToBinary(n);
		string str1 = str;
		//std::cout << str << endl;

		int len = str.size();
		int mid = len / 2;
		int aw = -100;
		bool IsEqual = true;
		if (len % 2 == 0)
		{
			for (int i = 0,j=str.size()-1;i < mid;i++,j--)
			{
				if (str[i] != str[j])
				{
					IsEqual = false;
					break;
				}
			}
			//aw = str.compare(0, mid, str1, mid, mid);
		}
		else
		{
			for (int i = 0, j = str.size() - 1;i < mid;i++,j--)
			{
				if (str[i] != str[j])
				{
					IsEqual = false;
					break;
				}
			}
			//aw = str.compare(0, mid, str1, mid+1, mid);
		}
		return IsEqual;
		
	}

	string DecToBinary(int n)
	{
		int m = n;
		string aw = "";
		while (m)
		{
			string t = std::to_string(m % 2);
			t += aw;
			aw = t;
			m /= 2;
		}
		return aw;
	}
};

