#pragma once
#include <list>
using namespace std;
class CStack
{
public:
	CStack();
	~CStack();
	list<int> _lst;

	int* _ary;
	int _cnt = 0;

	void push(int x) 
	{
		// write your code here
		int* t;
		if (_cnt == 0)
		{
			_cnt++;
			delete[] _ary;
			_ary = new int[_cnt];
			_ary[0] = x;
		}
		else
		{
			_cnt++;
			t = new int[_cnt];
			memcpy(t, _ary, (_cnt - 1)*sizeof(int));
			t[_cnt - 1] = x;
			delete[] _ary;
			_ary = t;
		}
	}

	/*
	* @return: nothing
	*/
	void pop() 
	{
		// write your code here
		_cnt--;
		int* t = new int[_cnt];
		memcpy(t, _ary, _cnt*sizeof(int));
		delete[] _ary;
		_ary = t;
	}

	/*
	* @return: An integer
	*/
	int top() 
	{
		// write your code here
		return _ary[_cnt - 1];
	}

	/*
	* @return: True if the stack is empty
	*/
	bool isEmpty() 
	{
		// write your code here
		if (_cnt == 0) return true;
		else return false;
	}
	list<int> GetAll()
	{
		for (int i = 0;i < _cnt;i++)
		{
			_lst.push_front(_ary[i]);
		}
		return _lst;
	}

};

