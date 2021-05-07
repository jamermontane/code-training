#include "stdafx.h"
#include "MyQueue.h"


CMyQueue::CMyQueue()
{
	_cnt = 0;
	_ary = new int[1];
}


CMyQueue::~CMyQueue()
{
	delete[] _ary;
}
