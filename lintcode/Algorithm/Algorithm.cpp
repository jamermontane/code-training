// Algorithm.cpp : Defines the entry point for the console application.
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

#include "Solution37.h"
#include "Solution463.h"
#include "Solution.h"

#include "Palindrome.h"
#include "YangHuisTriangle.h"
#include "Primes.h"
#include "FizzBuff.h"
#include "StringConvert.h"
#include "stack.h"
#include "MyQueue.h"

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
		cout << *itr<<" ";
	}
	cout << endl;
}


string GetAnotherCase(char c)
{
	char b;
	if (c >= 65 && c <= 90) b = c + 32;
	else if (c >= 97 && c <= 122) b = c - 32;

	stringstream stm;
	stm << b;

	return stm.str();
}

char ToLowerCase(char c)
{
	if (c >= 65 && c <= 90) return c += 32;
	else return c;
}

char ToUpperCase(char c)
{
	if (c >= 97 && c <= 122) return  c -= 32;
	else return c;
}

long long Factorial(int n) 
{
	// Write your code here
	long long aw = 1;
	for (int i = 1, j = n;i < j;i++, j--)
	{
		aw *= i;
		aw *= j;
	}
	if (n % 2 != 0)
	{
		int t = n / 2 + 1;
		aw *= t;
	}
	
	return aw;
}

long long doubleFactorial(int n)
{
	// Write your code here
	if (n == 1 || n == 2)
		return n;
	long long aw = 1;
	bool IsOdd = ((n % 2) != 0);
	for (int i = 1, j = n;i < j;i++, j--)
	{
		if (  (IsOdd && (i % 2 != 0))
			||(!IsOdd && (i % 2 == 0))  )
		{
			aw *= i;
		}
		if ((IsOdd && (j % 2 != 0))
			|| (!IsOdd && (j % 2 == 0)))
		{
			aw *= j;
		}
	}
	if (n % 2 != 0)
	{
		int t = n / 2 + 1;
		if ((IsOdd && (t % 2 != 0))
			|| (!IsOdd && (t % 2 == 0)))
		{
			aw *= t;
		}
	}
	return aw;
}


bool isPalindrome(int n)
{
	// Write your code here
	if (n == 0 || n == 1) return true;

	string str = to_string(n);
	string str1 = str;
	//std::cout << str << endl;

	int len = str.size();
	int mid = len / 2;
	int aw = -100;
	bool IsEqual = true;
	if (len % 2 == 0)
	{
		for (int i = 0, j = str.size() - 1; i < mid; i++, j--)
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
		for (int i = 0, j = str.size() - 1; i < mid; i++, j--)
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

//是否为有效的括号
bool isValidParentheses(string &s) 
{
	// write your code here
	if (s.size() <= 1) return false;
	stack<char> stP;
	int size = s.size();
	bool IsValid = true;
	for (int i = 0;i < size;i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			char c = s[i];
			stP.push(c);
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			char c;
			if (stP.size() == 0)
			{
				c = 0;
				IsValid = false;
			}
			else
			{
				c = stP.top();
				stP.pop();
			}
			char b = s[i];
			if (c == '(' && b != ')')
			{
				IsValid = false;
			}
			if (c == '{' && b != '}')
			{
				IsValid = false;
			}
			if (c == '[' && b != ']')
			{
				IsValid = false;
			}
			if (IsValid == false) break;
		}
	}
	if (stP.size() != 0) IsValid = false;
	return IsValid;
}

bool matchParentheses(string &string) 
{
	// write your code here
	int matched = 0;
	for (int i = 0; i < string.size(); i++) {
		if (string[i] == '(') {
			matched++;
		}
		else {
			matched--;
		}
		if (matched < 0) {
			return false;
		}
	}

	return matched == 0;
}

int fibonacci(int n) 
{
	// write your code here
	if (n == 1) return 0;
	if (n == 2) return 1;
//	return fibonacci(n - 1) + fibonacci(n - 2);
	int sum = 0;
	int* ary = new int[n+1];
	ary[1] = 0;
	ary[2] = 1;
	for (int i = 3;i <= n;i++)
	{
		if (i == 3)
		{
			sum = ary[1] + ary[2];
			
		}
		else
		{
			sum = ary[i - 2] + ary[i-1];
		}
		ary[i] = sum;
	}
	return sum;
	
}

string highestFrequency(vector<string> &ipLines)
{
	map<string, int> mp;
	int max = -1;
	string elem;
	int size = ipLines.size();
	if (size == 1)
	{
		elem = ipLines[0];
	}
	else
	{
		for (int i = 0;i < size;i++)
		{
			if (mp.find(ipLines[i]) != mp.end())
			{
				mp[ipLines[i]]++;
				if (mp[ipLines[i]] >= max)
				{
					max = mp[ipLines[i]];
					elem = ipLines[i];
				}

			}
			else
			{
				mp.insert(pair<string, int>(ipLines[i], 1));
			}
		}
	}

	return elem;
}

char longestLightingTime(vector<vector<int>> &operation) 
{
	// write your code here
	//map<int, int> ans;
	int size = operation.size();
	int lastTm = 0;
	int MaxTm = -1;
	int MaxEl = 0;
	for (int i = 0;i < size;i++)
	{
		vector<int> vc = operation[i];
		int curTm = vc[1];
		if (i == 0)
		{
			lastTm = 0;
			MaxTm = vc[1];
			MaxEl = vc[0];
		}
		else
		{
			if (vc[1] - lastTm > MaxTm)
			{
				MaxTm = vc[1] - lastTm;
				MaxEl = vc[0];
			}
			
		}
		lastTm = curTm;
	}
	char t = 'a' + MaxEl;
	return t;
}

vector<vector<int>> highpoints(vector<vector<int>> &grid) 
{
	// write your code here
	int size = grid.size();
	vector<vector<int>> ans;
	for (int i = 0;i < size;i++)
	{
		vector<int> vc;
		for (int j = 0;j < size;j++)
		{
			int s1 = i - 1 >= 0 ? i - 1 : 0;
			int e1 = i + 1 >= size - 1 ? size - 1 : i + 1;
			int s2 = j - 1 >= 0 ? j - 1 : 0;
			int e2 = j + 1 >= size - 1 ? size - 1 : j + 1;
			bool IsBig = true;
			for (int m = s1;m <= e1;m++)
			{
				for (int n = s2;n <= e2;n++)
				{
					if (m != i || n != j)
					{
						int self = grid[i][j];
						int others = grid[m][n];
						if (self <= others)
						{
							IsBig = false;
							break;
						}
					}
				}
				if (IsBig == false)
				{
					break;
				}
			}
			vc.push_back(IsBig);
		}
		ans.push_back(vc);
	}
	return ans;
}

string CharacterDeletion(string &str, string &sub) 
{
	// write your code here
	int sizeOfstr = str.size();
	int sizeOfsub = sub.size();
	for (int i = 0;i < sizeOfsub;i++)
	{
		int pos = str.find(sub[i]);
		while (pos != -1)
		{
			str.erase(pos,1);
			pos = str.find(sub[i]);
		}
	}
	return str;
}

vector<string> departmentStatistics(vector<string> &employees, vector<string> &friendships) 
{
	// write your code here.
	map<string, int> depCnt;
	map<string, int> ans;
	map<string, bool> hasFlag;
	map<string, string> emlys;
	int size = employees.size();
	for (int i = 0; i < size; i++)
	{
		string t = employees[i];
		int pos = t.find(" ");
		string s1 = t.substr(0, pos-1);
		pos = t.rfind(" ");
		string s2 = t.substr(pos+1, pos - t.size()-1);
		if (depCnt.find(s2) == depCnt.end())
		{
			depCnt.insert(pair<string, int>(s2, 1));
			ans.insert(pair<string, int>(s2, 0));
		}
		else
		{
			depCnt[s2]++;
		}
		emlys.insert(pair<string, string>(s1, s2));
		hasFlag.insert(pair<string, bool>(s1, false));
	}

	size = friendships.size();

	for (int i = 0; i < size; i++)
	{
		string t = friendships[i];
		int pos = t.find(",");
		string s1 = t.substr(0, pos);
		pos = t.find(" ");
		string s2 = t.substr(pos + 1, t.size() - pos - 1);

		string s4 = emlys[s1];
		string s5 = emlys[s2];
		if (s4 != s5)
		{
			
			if (ans[s4] < depCnt[s4] && !hasFlag[s1])
				ans[s4]++;
			if (ans[s5] < depCnt[s5] && !hasFlag[s2])
				ans[s5]++;

			hasFlag[s1] = true;
			hasFlag[s2] = true;

	/*		if (ans.find(emlys[s1]) == ans.end())
			{
				ans.insert(pair<string, int>(emlys[s1], 1));
			}
			else
			{
				
			}
			if (ans.find(emlys[s2]) == ans.end())
			{
				ans.insert(pair<string, int>(emlys[s2], 1));
			}
			else
			{
				ans[emlys[s2]]++;
			}  */
		}
	}


	vector<string> vcStr;
	for (map<string, int>::iterator itr = ans.begin(); itr != ans.end(); itr++)
	{
		string str = itr->first;
		str += ": ";
		str += to_string(itr->second);
		str += " of";
		str += " ";
		str += to_string(depCnt[itr->first]);
		vcStr.push_back(str);
	}
	return vcStr;
}


int FindSubStr(string& source, string& target)
{
	int sizeOfSource = source.size();
	int sizeOfTarget = target.size();
	bool Find = false;
	int FindPos = -1;

	if (sizeOfTarget >= sizeOfSource)
	{
		if (target == source)
		{
			FindPos = 0;
			Find = true;
		}
	}
	else
	{
		if (sizeOfTarget == 0)
		{
			FindPos = 0;
			Find = true;
		}
		else
		{
			if (sizeOfTarget == 0)
			{
				FindPos = 0;
				Find = true;
			}
			else
			{
				for (int i = 0;i < sizeOfSource;i++)
				{

					int pos = source.substr(i, sizeOfSource - i).find(target[0]);
					if (pos + i + sizeOfTarget > sizeOfSource) break;
					if (source.substr(pos + i, sizeOfTarget) == target)
					{
						Find = true;
						FindPos = pos + i;
						break;
					}
				}
			}
		}
	}
	return FindPos;
}

void BinaryIntSort(int* data, int dataSize, int elm)
{
	int left = 0;
	int right = dataSize - 1;
	int mid = left + ((right - left) >> 1);
	while (left <= right)
	{
		if (data[mid] > elm)
			right = mid - 1;
		else if (data[mid] < elm)
			left = mid + 1;
		else
			break;
		mid = left + ((right - left) >> 1);
	}
	mid++;
	if (mid > dataSize - 1)
	{
		data[dataSize] = elm;
	}
	else
	{
		const int size = (dataSize - mid) * sizeof(int);
		int* tmp = new int[size];
		memcpy(tmp, data + mid, size);
		memcpy(data + mid + 1, tmp, size);
		delete[] tmp;
		//memcpy(data + mid, data + mid - 1, size);


		/*delete[] elmTemp;*/
		// 			for (int i = dataSize; i > mid;i--)
		// 			{
		// 				data[i] = data[i - 1];
		// 			}
		data[mid] = elm;
	}
// 	int left = 0;
// 	int right = dataSize - 1;
// 	int mid = left + ((right - left) >> 1);
// 	int FindPos = -1;
// 	while (left <= right)
// 	{
// 		if (data[mid] > elm)
// 			right = mid - 1;
// 		else if (data[mid] < elm)
// 			left = mid + 1;
// 		else if (data[mid] == elm)
// 		{
// 			FindPos = mid;
// 			return FindPos;
// 		}
// 		else
// 			break;
// 		mid = left + ((right - left) >> 1);
// 	}
// 	mid++;
// 	if (mid > dataSize - 1)
// 	{
// 		data[dataSize] = elm;
// 	}
// 	else
// 	{
// 		const int size = (dataSize - mid) * sizeof(int);
// 		int* tmp = new int[size];
// 		memcpy(tmp, data + mid, size);
// 		memcpy(data + mid + 1, tmp, size);
// 		delete[] tmp;
// 		//memcpy(data + mid, data + mid - 1, size);
// 
// 
// 		/*delete[] elmTemp;*/
// 		// 			for (int i = dataSize; i > mid;i--)
// 		// 			{
// 		// 				data[i] = data[i - 1];
// 		// 			}
// 		data[mid] = elm;
// 	}
// 	return FindPos;
}


vector<vector<int>> Mine_sweeping(vector<vector<int>> &Mine_map, vector<int> &Start) 
{
	// write your code here
// 	[[1, 0, 0, 0], [1, 0, 0, 0], [0, 1, 1, 1], [0, 1, 0, 0]]
// 	[1, 0]


	vector<vector<int>> ans;

	if (Mine_map[Start[0]][Start[1]] == 0 || Mine_map.size() == 1)
	{
		ans.push_back(Start);
		return ans;
	}

	int size = Mine_map.size();
	int size2 = Mine_map[0].size();
	int** flag = new int*[size];
	for (int i = 0;i < size;i++)
	{
		flag[i] = new int[size2];
		memset(flag[i], 0, sizeof(int)*size2);
	}
	
	stack<vector<int>> stkTemp;
	
	

	

	stkTemp.push(Start);

	while (stkTemp.size() > 0)
	{
		vector<int> vc = stkTemp.top();
		stkTemp.pop();

		int vc0 = vc[0];
		int vc1 = vc[1];

		int s1 = vc0 - 1 >= 0 ? vc0 - 1 : 0;
		int e1 = vc0 + 1 >= size - 1 ? size - 1 : vc0 + 1;
		int s2 = vc1 - 1 >= 0 ? vc1 - 1 : 0;
		int e2 = vc1 + 1 >= size2 - 1 ? size2 - 1 : vc1 + 1;

		

		for (int m = s1;m <= e1;m++)
		{
			if (flag[m][vc1] == 1) continue;;
			if (m != vc0)
			{
				vector<int> pt;
				pt.push_back(m);
				pt.push_back(vc1);

				ans.push_back(pt);
				if (Mine_map[m][vc1] == 1)
				{
					stkTemp.push(pt);
				}
				flag[m][vc1] = 1;
				int t = stkTemp.size();
			}
		}
		for (int m = s2;m <= e2;m++)
		{
			if (flag[vc0][m] == 1) continue;;
			if (m != vc1)
			{
				vector<int> pt;
				pt.push_back(vc0);
				pt.push_back(m);

				ans.push_back(pt);
				if (Mine_map[vc0][m] == 1)
				{
					stkTemp.push(pt);
				}
				flag[vc0][m] = 1;
				int t = stkTemp.size();
			}
		}
	}
	
	for (int i = 0;i < size;i++)
	{
		delete[] flag[i];
	}
	delete[] flag;

	return ans;

}

void S8()
{
	string str = "";
	string t;
	int size = str.size();
	int offset = 10;
	
	
	if (size != 0)
	{
		int TOffset = offset % size;
		if (TOffset == size)
		{
			t = str;
		}
		else
		{
			t = str.substr(size - TOffset, TOffset);
			int st = t.size();
			t += str.substr(0, size - TOffset);
		}
	}
}

void Solution9()
{
	CFizzBuff fb;
	int n = 15;
	PrintStringVector(fb.fizzBuzz(n));
}

void Solution13()
{
	string source = "afjkshdfkjahsdfkhasdlkfhalkwfalkjhsdflkjhkjwehfkjahsdklfjhaskldjfhaskljdhfalkjsdhfkljahsdf";
	string target = "*&^&$%&*(^&*&$<S-F6><S-F5>$%*($#^$&%^)*&%$^%*^()^(&*%";

	FindSubStr(source, target);

// 
// 	int sizeOfSource = source.size();
// 	int sizeOfTarget = target.size();
// 	bool Find = false;
// 	int FindPos = -1;
// 
// 	if (sizeOfTarget >= sizeOfSource)
// 	{
// 		if (target == source)
// 		{
// 			FindPos = 0;
// 			Find = true;
// 		}
// 	}
// 	else
// 	{
// 		if (sizeOfTarget == 0)
// 		{
// 			FindPos = 0;
// 			Find = true;
// 		}
// 		else
// 		{
// 			for (int i = 0; i < sizeOfSource; i++)
// 			{
// 				int pos = source.substr(i, sizeOfSource - i).find(target[0]);
// 				if (pos == -1) break;
// 				if (pos + i + sizeOfTarget > sizeOfSource) break;
// 				if (source.substr(pos + i, sizeOfTarget) == target)
// 				{
// 					Find = true;
// 					FindPos = pos + i;
// 					break;
// 				}
// 			}
// 		}
// 	}
}

void Solution25()
{
	int n = 1;
	vector<string> aw;
	vector<string> vct;
	if (n == 1)
	{
		aw.push_back("X");
	}
	else if (n == 2)
	{
		aw.push_back("XX");
		aw.push_back("XX");
	}
	else if (n == 3)
	{
		aw.push_back("X X");
		aw.push_back(" X ");
		aw.push_back("X X");
	}
	else if (n == 4)
	{
		aw.push_back("X  X");
		aw.push_back(" XX ");
		aw.push_back(" XX ");
		aw.push_back("X  X");
	}
	else if (n == 5)
	{
		aw.push_back("X   X");
		aw.push_back(" X X ");
		aw.push_back("  X  ");
		aw.push_back(" X X ");
		aw.push_back("X   X");
	}
	else
	{
		int Cnt = 0;
		string t = "";
		if (n % 2 == 0)
		{
			Cnt = n - 2;
			int Before = 0;
			while (Cnt > 0)
			{
				t = "";
				for (int i = 0;i < Before;i++)
				{
					t += " ";
				}
				t += "X";
				for (int i = 0;i < Cnt;i++)
				{
					t += " ";
				}
				t += "X";
				for (int i = 0;i < Before;i++)
				{
					t += " ";
				}
				
				vct.push_back(t);
				Cnt -= 2;
				Before += 1;
			}
			t = "";
			for (int i = 0;i < Before;i++)
			{
				t += " ";
			}
			t += "XX";
			for (int i = 0;i < Before;i++)
			{
				t += " ";
			}
			vct.push_back(t);
			aw.assign(vct.begin(), vct.end());
// 			vector<string> tt;
// 			tt.assign(vct.end(), vct.begin());
			for (int i = vct.size() - 1;i >= 0;i--)
			{
				aw.push_back(vct[i]);
			}
//			aw.insert(aw.end(), tt.begin(), tt.end());
			
		}
		else
		{
			Cnt = n - 2;
			int Before = 0;
			while (Cnt > 0)
			{
				t = "";
				for (int i = 0;i < Before;i++)
				{
					t += " ";
				}
				t += "X";
				for (int i = 0;i < Cnt;i++)
				{
					t += " ";
				}
				t += "X";
				for (int i = 0;i < Before;i++)
				{
					t += " ";
				}

				vct.push_back(t);
				Cnt -= 2;
				Before += 1;
			}
			t = "";
			for (int i = 0;i < Before;i++)
			{
				t += " ";
			}
			t += "X";
			for (int i = 0;i < Before;i++)
			{
				t += " ";
			}
			vct.push_back(t);
			aw.assign(vct.begin(), vct.end());
			// 			vector<string> tt;
			// 			tt.assign(vct.end(), vct.begin());
			for (int i = vct.size() - 2;i >= 0;i--)
			{
				aw.push_back(vct[i]);
			}
			//			aw.insert(aw.end(), tt.begin(), tt.end());
		}

	

// 		aw.push_back("X    X");
// 		aw.push_back(" X  X ");
// 		aw.push_back("  XX ");
// 		aw.push_back("  XX ");
// 		aw.push_back(" X  X ");
// 		aw.push_back("X    X");
	}
	for (int i = 0;i < aw.size();i++)
	{
		cout << aw[i] << endl;
	}
}

void Solution37()
{
	CSolution37 cs;
	int Input = 900;
	cout << Input << ":" << cs.reverseInteger(Input) << endl;
}

void Solution46()
{
	vector<int> nums = { 1, 1, 1, 2, 2, 2, 2 };
	
	map<int, int> mp;
	int max = -1;
	int elem;
	if (nums.size() == 1)
	{
		elem = nums[0];
	}
	else
	{
		for (int i = 0;i < nums.size();i++)
		{
			if (mp.find(nums[i]) != mp.end())
			{
				mp[nums[i]]++;
				if (mp[nums[i]] >= max)
				{
					max = mp[nums[i]];
					elem = nums[i];
				}

			}
			else
			{
				mp.insert(pair<int, int>(nums[i], 1));
			}
		}
	}
	
	cout << elem;
}

void Solution50()
{
	vector<int> nums = { 1,2,3 };
	vector<long long> aw;
	if (nums.size() == 1)
		aw.push_back(1);
	else
	{
		for (int i = 0;i < nums.size();i++)
		{
			long long mul = 1;
			for (int j = 0;j < nums.size();j++)
			{
				if (i != j)
				{
					mul *= nums[j];
				}
			}
			aw.push_back(mul);
		}
	}
}

void Solution53()
{
	string words = "How are you?";//"  Life  doesn't  always    give     us  the       joys we want.";
	string aw = "";
	while(words.size()>0)
	{
		int t = words.rfind(' ');
		if (t != -1)
		{
			string str = words.substr(t, words.size() - t);
			int pos = str.find(' ');
			while (pos != -1)
			{
				str.erase(pos, 1);
				pos = str.find(' ');
			}
			if (str.size() > 0)
			{
				aw += str;
				aw += " ";
			}
			words.erase(t, words.size() - t);
		}
		else
		{
			//aw += " ";
			aw += words;
			words.clear();
		}
	}
	if (aw.find(' ') == 0)
	{
		aw.erase(0, 1);
	}
	cout << aw<<"!";
}

void S133()
{
	vector<string> dictionary = {
		"dog",
		"google",
		"facebook",
		"internationalization",
		"blabla"
	};
	int len = dictionary.size();
	int maxNo = -1;
	//map<int, vector<string>> aw;

	map<int, int> mp;
	vector<string> aw;


	for (int i = 0; i < len; i++)
	{
		int tlen = dictionary[i].size();
		if (tlen > maxNo)
		{
			maxNo = tlen;
			aw.clear();
			aw.push_back(dictionary[i]);
		}
		else if (tlen == maxNo)
		{
			aw.push_back(dictionary[i]);
		}
	}

	// 	for (int i = 0; i < len; i++)
	// 	{
	// 		int tlen = dictionary[i].size();
	// 		if (mp.find(tlen) == mp.end())
	// 		{
	// 			if (tlen > maxNo)
	// 			{
	// 				mp.clear();
	// 				mp.insert(pair<int, int>(tlen, 1));
	// 				maxNo = tlen;
	// 				aw.clear();
	// 				aw.push_back(dictionary[i]);
	// 			}
	// 		}
	// 		else
	// 		{
	// 			aw.push_back(dictionary[i]);
	// 		}
	// 	}
}

void Solution146()
{
	string str = "abc";
	for (int i = 0;i < str.size();i++)
	{
		if (str[i] >= 97)
			str[i] -= 32;
		//else
//			str[i] += 32;
	}
}

void Solution220()
{
	int num = 4;
	int cnt = 0;
	int temp = num;
	while(temp!=1)
	{
		if (temp % 2 == 0)
		{
			temp /= 2;
		}
		else
		{
			temp = 3 * temp + 1;
		}
		cnt++;
	}
	cout << cnt;
}

void Solution235()
{
	CPrimes p;
	vector<int> aw;
	int n = 1000000007;
	if (p.IsPrimNumber(n))
	{
		aw.push_back(n);
	}
	else
	{
		aw = p.primeFactorization(n);
	}
	PrintIntVector(aw);
}

void Solution241()
{
	CStringConvert sc;
	cout << sc.ConvertToInt("-123");
}

void Solution283()
{
	int num1, num2, num3;
	num1 = 100, num2 = 99, num3 = 87;

	int result = num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);
}

void S353()
{
	ifstream myfile("testdatav2_353_data_5.in");
	string s;
	while (!myfile.eof())
	{
		myfile >> s;
	}
	int size = s.size();
	string aw = "NO";
	char c = 0;
	for (int i = 0, j = size - 1; i < j; i++, j--)
	{
		bool B1 = (s.find(GetAnotherCase(s[i])) != -1);
		bool B2 = (s.find(GetAnotherCase(s[j])) != -1);
		char c1 = ToUpperCase(s[i]);
		char c2 = ToUpperCase(s[j]);
		char uc = ToUpperCase(c);

		if (B1 && B2)
		{
			if (c1 > c2)
			{
				if (c1 >= uc)
					c = c1;
			}
			else
			{
				if (c2 >= uc)
					c = c2;
			}
		}
		else if (B1 && !B2)
		{
			if (c1 >= c2)
				c = uc;
		}
		else if (!B1 && B2)
		{
			if (c2 >= uc)
				c = c2;
		}
		else
		{
			int pos = s.find(s[i]);
			char ct1 = s[i];
			char ct2 = s[j];
			while (pos != -1)
			{
				s.erase(pos, 1);
				pos = s.find(ct1);
			}
			pos = s.find(ct2);
			while (pos != -1)
			{
				s.erase(pos, 1);
				pos = s.find(ct2);
			}
			size = s.size();
			i = 0;
			j = size - 1;
		}
		if (c == 'Z') break;
	}
	if (c != 0)
	{
		aw = c;
	}
	cout << aw;
}

void S366()
{
	int n = 4;
	cout << fibonacci(n);
}

void Solution407()
{
	vector<int> vc = { 9,9,9,9 };
	int plus = 0;
	for (int i = vc.size() - 1;i >= 0;i--)
	{
		if (i == vc.size() - 1)
		{
			if (vc[i] + 1 >= 10)
			{
				plus = 1;
				vc[i] = (vc[i] + 1) % 10;
			}
			else
			{
				vc[i] += 1;
				plus = 0;
			}
		}
		else
		{
			if (vc[i] + plus >= 10)
			{
				plus = 1;
				vc[i] = (vc[i] + plus) % 10;
			}
			else
			{
				vc[i] += plus;
				plus = 0;
			}
		}
	}
	if (plus == 1)
	{
		vc.insert(vc.begin(), 1);
	}
	PrintIntVector(vc);
}

void s422()
{
	string s = "Hello LintCode    ";
	int ss = s.size();
	int flag = -1;
	int cnt = 0;
	for (int i = ss - 1; i >= 0; i--)
	{
		if (s[i] != ' ')
		{
			//			if (flag == -1 || flag == 0)
			{
				flag = 1;
				cnt++;
			}
		}
		else
		{
			if (flag == 1)
			{
				break;
			}
			flag = 0;
		}
	}
}

void S423()
{
	string s = "[])";
	cout << isValidParentheses(s);
}
// 归并排序
void Solution463()
{
	vector<int> a1 = { 1, 1, 2, 1, 1 };// { 3, 2, 1, 4, 5 };
	CSolution463 cs;
	cs.sortIntegers(a1);

	for (int i = 0;i < a1.size();i++)
	{
		cout << a1[i];
	}
}

void Solution479()
{
	vector<int> nums = { 1,-1,-2 };
	int m1 = INT_MIN;
	int m2 = INT_MIN;
	for (int i = 0;i<nums.size();i++)
	{
		if (nums[i]>=m1)
		{
			if (m1 != -1)
			{
				m2 = m1;
			}
			m1 = nums[i];
		}
		else
		{
			if (nums[i] >= m2) m2 = nums[i];
		}
	}
}

void Solution484(vector<int> &A, int index1, int index2)
{
	swap(A[index1], A[index2]);
}

void S492()
{
	CMyQueue mq;
	mq.enqueue(1);
	mq.enqueue(2);
	mq.enqueue(3);
	cout << mq.dequeue() << endl;
	mq.enqueue(4);
	cout << mq.dequeue() << endl;
}

void S495()
{
	CStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.isEmpty() << endl;
	s.pop();
	cout << s.isEmpty() << endl;
	
}

void S491()
{
	cout << isPalindrome(11);
}

void Solution539()
{
	vector<int> nums = { 1,2,30,0,0,4 };
	vector<int>::iterator iter = find(nums.begin(), nums.end(), 0);;
	vector<int> zeros;
	while (iter != nums.end())
	{
		zeros.push_back(0);
		nums.erase(iter);
		iter = find(nums.begin(), nums.end(), 0);
	}
	nums.insert(nums.end(), zeros.begin(), zeros.end());
}

void Solution764()
{
	vector<double> result;

	int r = 14;
	// 	vector<int> rDiff;
	// 	int T = r;
	// 	int Cnt = 1;
	// 	while (T >= 2)
	// 	{
	// 		T -= pow(2, Cnt);
	// 		rDiff.push_back(pow(2, Cnt));
	// 		Cnt++;
	// 	}
	// 	if (T != 0)
	// 	{
	// 		rDiff.push_back(T);
	// 	}

	double PI = 3.14;
	double dr = 2 * PI * r;
	result.push_back(dr);
	dr = PI * pow(r, 2);
	result.push_back(dr);
}

void Solution768()
{
	CYangHuisTriangle yt;
	int n = 14;
	vector<vector<int>> aw = yt.calcByN(n);
	for (int i = 0;i < aw.size();i++)
	{
		for (int j = 0;j < aw[i].size();j++)
		{
			cout << aw[i][j] << ":";
		}
		cout << endl;
	}
}

void S771()
{
	int n = 4;
	cout << doubleFactorial(n);
}

void Solution807()
{
	CPalindrome cp;
	for(int n=0;n<100;n++)
		cout << n <<":" <<cp.isPalindrome(n)<<endl;
}

void S936()
{
	string s = "i jidls    mdijf  i  lsidj  i p l   ";
	int ss = s.size();
	int cnt = 0;

	for (int i = 0; i < ss; i++)
	{
		if (cnt == 0)
		{
			if (s[i] >= 65 && s[i] <= 90
				|| s[i] >= 97 && s[i] <= 122)
			{
				if (s[i] >= 97 && s[i] <= 122)
					s[i] -= 32;
				cnt = 1;
			}
		}
		else
		{
			if (s[i] == ' ')
			{
				cnt = 0;
			}
		}
	}
}

int Solution1141(int year,int month)
{

	if (year < 1 || year >10000) return -1;
	if (month < 1 || month >12) return -1;


	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 29;
		}
		else
			return 28;
		
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	}
}

void Solution1300()
{
	int n = 40000000;

	bool CanWin = false;

	if (n <= 3) CanWin = true;
	else if (n == 4) CanWin = false;
	else if (n == 5) CanWin = true;
	else
	{
		for (int i = 0;i < 3;i++)
		{
			double t = (double)(n - 5 - i) / 4;

			if (t - (int)t == 0)
			{
				CanWin = true;
				break;
			}
		}
	}
}

void S1343()
{
	string A = "99";
	string B = "111";
	string C = "";

	int sA = A.size();
	int sB = B.size();
	int sBig = sA > sB ? sA : sB;

	for (int i = 0; i < abs(sB - sA); i++)
	{
		if (sBig > sA)
		{
			A.insert(0, "0");
		}
		if (sBig > sB)
		{
			B.insert(0, "0");
		}
	}
	for (int i = sBig - 1; i >= 0; i--)
	{
		int r = (int)(A[i] - '0') + (int)(B[i] - '0');
		C.insert(0, to_string(r));
	}

}

void S1613()
{
	vector<string> ipLines = { "192.168.1.1","192.118.2.1","192.168.1.1","192.118.2.1","192.118.2.1" };
	cout << highestFrequency(ipLines);
}

void S1892()
{
	/*vector<vector<int>> Mine_map = { {1,0,0,0},{1,0,0,0},{0,1,1,1},{0,1,0,0} };*/
	/*vector<vector<int>> Mine_map = { { 1 } };*/
	vector<vector<int>> Mine_map = { {1, 1},{1, 1},{1, 1} };
	vector<int> Start = { 2,0 };
	vector<vector<int>> ans = Mine_sweeping(Mine_map, Start);

	for (int i = 0;i < ans.size();i++)
	{
		for (int j = 0;j < ans[i].size();j++)
		{
			cout << ans[i][j]<<",";
		}
		cout << endl;
	}
}

//非递归排列组合
void S1895()
{
	vector<vector<int>> cost = { {5,4},{3,6},{1,8},{3,9} };
	int size = cost.size();

	clock_t start = clock();
	double TotalTime = (double)(clock() - start) / CLOCKS_PER_SEC;

	ifstream myfile("testdatav2_1895_data_3.in");
	string s;
	while (!myfile.eof())
	{
		myfile >> s;
	}
	size = s.size();
	s.erase(0,1);
	s.erase(size - 1,1);
	
	size = s.size();

	int pos = s.find('[');
	int pos1 = s.find(']');
	cost.clear();
	while (pos != -1 && pos1 != -1)
	{
		vector<int> vc;
		string str = s.substr(pos+1, pos1 - pos-1);
		int pos3 = str.find(',');
		string str2 = str.substr(0, pos3);
		string str3 = str.substr(pos3+1, str.size() - pos3-1);

		vc.push_back(stoi(str2));
		vc.push_back(stoi(str3));
		cost.push_back(vc);

		s.erase(pos, pos1-pos+1);
		pos = s.find('[');
		pos1 = s.find(']');
	}
	
	cout << "total time:" << (double)(clock() - start) / CLOCKS_PER_SEC;

	size = cost.size();
	int* flag = new int[size];
	vector<int> ans;
	int mincost = INT_MAX;
	memset(flag, 0, sizeof(int)*size);
	int MoveFlag = size - 1;
	int MoveFlag2 = MoveFlag;

	for (int i = size / 2;i < size;i++)
	{
		flag[i] = 1;
	}


	int FirstPos = size / 2;
	while (flag[0] <=1 )
	{
		int t = 0;
		vector<int> vc;
		int cityACnt = 0;
		int cityBCnt = 0;
		for (int i = 0;i < size;i++)
		{
			t += cost[i][flag[i]];
			vc.push_back(flag[i]);
			if (t > mincost)
			{
				vc.clear();
				break;
			}
			if (flag[i] == 0)
				cityACnt++;
			else
				cityBCnt++;
			if (cityACnt > (size / 2 + 1))
			{
				vc.clear();
				break;
			}
			if (cityBCnt > (size / 2 + 1))
			{
				vc.clear();
				break;
			}
			
		}
		
		if (vc.size() != 0)
		{
			//不能都去同一个城市
			int other = (vc[0] == 0 ? 1 : 0);
			if (find(vc.begin(), vc.end(), other) == vc.end())
			{
				vc.clear();
			}
			//要求均分
			if (cityACnt != cityBCnt)
			{
				vc.clear();
			}
			
		}
		if(vc.size()!=0 )
		{
			if (t < mincost)
			{
				ans.assign(vc.begin(), vc.end());
				mincost = t;
			}
		}
		
		bool IsEnd = false;
		for (int i = size - 1;i >= 0;i--)
		{
			int zeroCnt = size - 1 - i;
			if (IsEnd || i == size - 1)
			{
				flag[i]++;

				if (i < FirstPos) 
					FirstPos = i - 1;
				


// 				int TotalZero = size - FirstPos - 1;
// 				TotalZero += zeroCnt;
// 				
// 				if (TotalZero > size / 2 && IsEnd == false)
// 				{
// 					IsEnd != true;
// 					//continue;
// 				}
// 				else
				{
					if (i + 1 < size)
						memset(flag + i + 1, 0, sizeof(int)*(zeroCnt));
				}
			}
			if (flag[i] > 1)
			{
				IsEnd |= true;
			}
			else
			{

				IsEnd &= false;
				
				break;
			}
		}


		int TotalZero = size - FirstPos - 1;
		int LeftZeros = size / 2 - TotalZero;
		if(LeftZeros>0)
			memset(flag +  size - LeftZeros, 0, sizeof(int)*(LeftZeros));
		



// 		flag[MoveFlag2]++;
// 		if (flag[MoveFlag] >1)
// 		{
// 			MoveFlag--;
// 			for (int k = MoveFlag;k < size;k++)
// 			{
// 				flag[k] = 0;
// 			}
// 			flag[MoveFlag]++;
// 		}
	}

	delete[] flag;

	PrintIntVector(ans);
	cout << "min cost: " << mincost;

	
}

void S1895_2()
{
	vector<vector<int>> cost = { { 5,4 },{ 3,6 },{ 1,8 },{ 3,9 } };
	int size = cost.size();

	clock_t start = clock();
	double TotalTime = (double)(clock() - start) / CLOCKS_PER_SEC;

	ifstream myfile("testdatav2_1895_data_3.in");
	string s;
	while (!myfile.eof())
	{
		myfile >> s;
	}
	size = s.size();
	s.erase(0, 1);
	s.erase(size - 1, 1);

	size = s.size();

	int pos = s.find('[');
	int pos1 = s.find(']');
	cost.clear();
	while (pos != -1 && pos1 != -1)
	{
		vector<int> vc;
		string str = s.substr(pos + 1, pos1 - pos - 1);
		int pos3 = str.find(',');
		string str2 = str.substr(0, pos3);
		string str3 = str.substr(pos3 + 1, str.size() - pos3 - 1);

		vc.push_back(stoi(str2));
		vc.push_back(stoi(str3));
		cost.push_back(vc);

		s.erase(pos, pos1 - pos + 1);
		pos = s.find('[');
		pos1 = s.find(']');
	}

	cout << "total time:" << (double)(clock() - start) / CLOCKS_PER_SEC;

	size = cost.size();
	//int* flag = new int[size];
	vector<int> flag(size,0);
	int sizeT = flag.size();
	vector<int> ans;
	int mincost = INT_MAX;
	//memset(flag, 0, sizeof(int)*size);
	int MoveFlag = size - 1;
	int MoveFlag2 = MoveFlag;

	for (int i = size / 2;i < size;i++)
	{
		flag[i] = 1;
	}


	int FirstPos = size / 2;
	while (flag[0] <= 1)
	{
		int t = 0;
		vector<int> vc;
		int cityACnt = 0;
		int cityBCnt = 0;
		for (int i = 0;i < size;i++)
		{
			int temp = flag[i];
			t += cost[i][flag[i]];
			vc.push_back(flag[i]);
			if (t > mincost)
			{
				vc.clear();
				break;
			}
			if (flag[i] == 0)
				cityACnt++;
			else
				cityBCnt++;
			if (cityACnt > (size / 2 + 1))
			{
				vc.clear();
				break;
			}
			if (cityBCnt > (size / 2 + 1))
			{
				vc.clear();
				break;
			}

		}

		if (vc.size() != 0)
		{
			//不能都去同一个城市
			int other = (vc[0] == 0 ? 1 : 0);
			if (find(vc.begin(), vc.end(), other) == vc.end())
			{
				vc.clear();
			}
			//要求均分
			if (cityACnt != cityBCnt)
			{
				vc.clear();
			}

		}
		if (vc.size() != 0)
		{
			if (t < mincost)
			{
				ans.assign(vc.begin(), vc.end());
				mincost = t;
			}
		}

		bool IsEnd = false;
		for (int i = size - 1;i >= 0;i--)
		{
			int temp = flag[i];
			int zeroCnt = size - 1 - i;
			if (IsEnd || i == size - 1)
			{
				flag[i]++;

// 				if (i + 1 < size)
// 					memset(flag + i + 1, 0, sizeof(int)*(zeroCnt));
				for (int j = i + 1;j < i + 1 + zeroCnt;j++)
				{
					flag[j] = 0;
				}
			}
			if (flag[i] > 1)
			{
				IsEnd |= true;
			}
			else
			{
				int zeronum = count(flag.begin(), flag.end(), 0);
				if (zeronum > size / 2)
				{
					i = size - 1;
					continue;
				}
				IsEnd &= false;
				break;
			}
		}
	}


	PrintIntVector(ans);
	cout << "min cost: " << mincost;


}

void S1896()
{
// 	vector<vector<int>> carrot = {  { 5, 3, 7, 1, 7 },
// 									{ 4, 6, 5, 2, 8 },
// 									{ 2, 1, 1, 4, 6} };
// 	vector<vector<int>> carrot = { {5, 7, 6, 3},
// 									{2,  4, 8, 12},
// 									{3, 5, 10, 7},
// 									{4, 16, 4, 17} };

	vector<vector<int>> carrot = { { 2,0,2 },
								   { 0,2,0 },
								   { 2,0,2} };


	int sizeM = carrot.size();
	int sizeN = carrot[0].size();
	bool** flag = new bool*[sizeM];
	vector<vector<int>> vecAns;
	for (int i = 0;i < sizeM;i++)
	{
		flag[i] = new bool[sizeN];
		for (int j = 0;j < sizeN;j++)
		{
			flag[i][j] = false;
		}
	}

	int startM = (sizeM-1) / 2;
	int startN = (sizeN - 1) / 2;

	bool Has = true;
	int CurPosM = startM;
	int CurPosN = startN;

	int m1, m2, n1, n2;
	
	vector<int> vec;
	vec.push_back(startM);
	vec.push_back(startN);
	vecAns.push_back(vec);

	int MaxSum = carrot[startM][startN];

	while (true)
	{
		bool Has = false;
		int max = -1;
		int MaxMPos = -1;
		int MaxNPos = -1;

		m1 = CurPosM - 1 < 0 ? -1 : CurPosM - 1;
		m2 = CurPosM + 1 > sizeM - 1 ? -1 : CurPosM + 1;
		n1 = CurPosN - 1 < 0 ? -1 : CurPosN - 1;
		n2 = CurPosN + 1 > sizeN - 1 ? -1 : CurPosN + 1;

		if (m1 != -1 && !flag[m1][CurPosN])
		{
			if (carrot[m1][CurPosN] > max)
			{
				max = carrot[m1][CurPosN];
				MaxMPos = m1;
				MaxNPos = CurPosN;
				Has = true;
			}
		}
		if (m2 != -1 && !flag[m2][CurPosN])
		{
			if (carrot[m2][CurPosN] > max)
			{
				max = carrot[m2][CurPosN];
				MaxMPos = m2;
				MaxNPos = CurPosN;
				Has = true;
			}
		}
		if (n1 != -1 && !flag[CurPosM][n1])
		{
			if (carrot[CurPosM][n1] > max)
			{
				max = carrot[CurPosM][n1];
				MaxMPos = CurPosM;
				MaxNPos = n1;
				Has = true;
			}
		}
		if (n2 != -1 && !flag[CurPosM][n2])
		{
			if (carrot[CurPosM][n2] > max)
			{
				max = carrot[CurPosM][n2];
				MaxMPos = CurPosM;
				MaxNPos = n2;
				Has = true;
			}
		}

		if (Has == false || max == 0) break;

		flag[CurPosM][CurPosN] = true;
		CurPosM = MaxMPos;
		CurPosN = MaxNPos;
		MaxSum += carrot[CurPosM][CurPosN];
		vector<int> vec;
		vec.push_back(MaxMPos);
		vec.push_back(MaxNPos);
		vecAns.push_back(vec);
		
	}

	for (int i = 0;i < sizeM;i++)
	{
		delete[] flag[i];
	}
	delete[] flag;

	sizeM = vecAns.size();

	for (int i = 0;i < sizeM;i++)
	{
		cout << carrot[vecAns[i][0]][vecAns[i][1]];
		if( i != sizeM -1)
		{
			cout << " ->";
			cout << " ";
		}
	}
	cout << endl << MaxSum;
}

void S1901()
{
	vector<int> A = { -7,-3,2,3,11 };
	//使用std
	list<int> ansT;
	vector<int> ans;
	int size = A.size();
	int* data = new int[size];
	for (int i = 0;i < size;i++)
	{
		int t = pow(A[i], 2);
		ansT.push_back(t);
		if(i>1)
			BinaryIntSort(data, i,t);
		else if(i == 0)
		{
			data[i] = t;
		}
		else if (i == 1)
		{
			if (t < data[0])
			{
				int s = data[0];
				data[i] = data[0];
				data[0] = t;
			}
		}
	}
	ansT.sort();
	size = ansT.size();
	for (int i = 0;i < size;i++)
	{
		ans.push_back(data[i]);
	}

	PrintIntVector(ans);
	
}

void S1902()
{
	vector<string> s = { "#include<bits/stdc++.h>", "using namespace std;", "//Google test", "int main(){", "return 0;", "}" };
	string sub = "Google";
	string sub1 = "//";
	int size = s.size();
	bool find = false;
	for (int i = 0;i < size;i++)
	{
		string t = s[i];
		int pos1 = t.find(sub);
		int pos2 = t.find(sub1);
		if (pos1 != -1 && pos2 != -1 && pos2 < pos1)
		{
			find = true;
			break;
		}
	}

	cout << find;

}

void S1903()
{
	vector<string> employees = {
		"0, Andrew, Law","1, Antonio, Law","2, Andy, Business","3, Andre, Purchase","4, Angelo, Finance","5, Ansel, Purchase","6, Barret, Finance","7, Barlow, Finance","8, Barnett, Purchase","9, Antony, Engineer","10, Amos, Engineer","11, Baron, Finance","12, Augus, Engineer","13, Bard, Law","14, Antoine, Advertising"
	};

	vector<string> friendships = {
		"7, 2","4, 10","9, 8","6, 2","14, 6","1, 8","13, 2","14, 7","4, 8","6, 4"
	};

	PrintStringVector(departmentStatistics(employees, friendships));
}

void S1905()
{
	string str = "They are students";
	string sub = "aeiou";
	cout << CharacterDeletion(str, sub);

}

void S1906()
{
	vector<vector<int>> grid = { {1,2,3,4},{5,5,5,2},{1,1,1,1},{0,0,0,9} };

	vector<vector<int>> ans = highpoints(grid);

	for (int i = 0;i < ans.size();i++)
	{
		for (int j = 0;j < ans[i].size();j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

void Soluton1910()
{
	ifstream myF("testdatav2_1910_data_10.in");
	string strData;
	string strT;
	istringstream iss;
	vector<string> mf;
	vector<vector<int>> vvData;
	vector<int> Data;

	clock_t startTime, endTime;
	int MaxStrLen = -1;
	startTime = clock();

	if (myF)
	{
		while (getline(myF, strData))
		{
			//	cout << strData;
			iss.clear();
			iss.str(strData);
			while (iss >> strT)
			{
				int pos = strT.find('[');
				if (pos == -1)
					pos = strT.find(']');
				if (pos != -1)
					strT.erase(pos, 1);
				pos = strT.find(',');
				if (pos != -1)
				{
					strT.erase(pos, 1);
				}
				int T = atoi(strT.c_str());
				Data.push_back(atoi(strT.c_str()));

				// 				mf.push_back(strT);
				// 				//cout << strT<<"\n";
				// 
				// 				
				// 				int T = strT.length();
				// 				if (T > MaxStrLen)
				// 					MaxStrLen = T;
				// 
				// 				vector<int> vecdata;
				// 				for (int i = 0;i < strT.length();i++)
				// 				{
				// 					vecdata.push_back(strT[i]-'0');
				// 				}
				// 
				// 	
				// 				vvData.push_back(vecdata);

				/*if (vvData.size() > 10) break;*/

			}
		}
	}
	endTime = clock();

	cout << Data.size() << ":" << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
	/*cout << "maxStrLen:" << MaxStrLen << endl;*/


	CSolution cs;
	vector<int> array = { 1,1,2,3,3,3,4,5/*5,5,5,1,1,2,3,3,3,4*/ };
	vector<int> array1 = { 5,5,5,1,1,2,3,3,3,4 };
	vector<int> array2 = { 1,1,1,1,1,1,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,8 };
	double TotalTime = 0;

	startTime = clock();
	cout << "\n" << cs.FindNumberInVector(Data);
	endTime = clock();
	TotalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	cout << "\nTotalTime:" << TotalTime << "\nSearchTime:" << cs.SearchCounter << "  SortTime:" << cs.SortCounter << " LeftTime:" << TotalTime - cs.SearchCounter - cs.SortCounter;

	startTime = clock();
	cout << "\n" << cs.findNumberFinal(Data);
	endTime = clock();
	TotalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	cout << "\nTotalTime:" << TotalTime << "\nSearchTime:" << cs.SearchCounter << "  SortTime:" << cs.SortCounter << " LeftTime:" << TotalTime - cs.SearchCounter - cs.SortCounter;



	// 
	// 	startTime = clock();
	// 	for (int i = 0;i < vvData.size();i++)
	// 	{
	// 		cs.findNumber(vvData[i]);
	// // 		for (int j = 0;j < vvData[i].size();j++)
	// // 		{
	// // 			cout << vvData[i][j];
	// // 		}
	// // 		std::cout <<":"<<(cs.findNumber(vvData[i]))<<"\n\n";
	// 
	// 	}
	// 	endTime = clock();
	// 	cout<<"\n" << (double)(endTime - startTime) / CLOCKS_PER_SEC;
	// 
	// 
}

void S1916()
{
	vector<vector<int>> operation = { {0,2},{1,5},{0,9},{2,15} };
	cout << longestLightingTime(operation);
}


int main()
{
	clock_t start = clock();
	S1892();
	double TotalTime = (double)(clock() - start) / CLOCKS_PER_SEC;
	cout << endl;
	cout << TotalTime << endl;
    return 0;
}

