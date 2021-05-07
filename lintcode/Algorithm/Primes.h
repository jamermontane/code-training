#pragma once
#include <vector>
using namespace std;
class CPrimes
{
public:
	CPrimes();
	~CPrimes();


	bool IsPrimNumber(int n)
	{
		int m = n;
		int i;
		int k;

		k = (int)sqrt((double)m);
		for (i = 2;i <= k;i++)
			if (m%i == 0)
				break;

		if (i>k)
			return true;
		else
			return false;
	}

	vector<int> primeFactorization(int num) 
	{
		// write your code here
		vector<int> aw;
		int n = num;
		while (n > 1)
		{
			for (long i = 2; i <= n; i++)
			{
				if (n % i == 0)
				{
					n = n / i;
					aw.push_back(i);
					break;
				}
			}
		}
		return aw;
	}

};

