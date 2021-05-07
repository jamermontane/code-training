#pragma once
#include <list>
using namespace std;
class CMyQueue
{
public:
	CMyQueue();
	~CMyQueue();
	list<int> _lst;

	int* _ary;
	int _cnt;
	
	/*
	* @param item: An integer
	* @return: nothing
	*/
	void enqueue(int item) 
	{
		// write your code here
		if (_cnt == 0)
		{
			_cnt++;
			delete[] _ary;
			_ary = new int[_cnt];
			_ary[0] = item;
		}
		else
		{
			_cnt++;
			int* t = new int[_cnt];
			memcpy(t, _ary, (_cnt - 1)*sizeof(int));
			t[_cnt - 1] = item;
			delete[] _ary;
			_ary = t;
		}
	}

	/*
	* @return: An integer
	*/
	int dequeue() {
		// write your code here
		int elem = _ary[0];
		_cnt--;
		int* t = new int[_cnt];
		memcpy(t, _ary+1, _cnt*sizeof(int));
		delete[] _ary;
		_ary = t;
		return elem;
	}

	list<int> GetAll()
	{
		for (int i = 0;i < _cnt;i++)
		{
			_lst.push_back(_ary[i]);
		}
		return _lst;
	}
};

