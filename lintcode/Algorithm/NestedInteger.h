#pragma once
#include <vector>
using namespace std;
class NestedInteger
{
	NestedInteger* _right;
public:
	NestedInteger();
	~NestedInteger();

public:
	// Return true if this NestedInteger holds a single integer,
		// rather than a nested list.
	bool isInteger() const
	{

	}

	// Return the single integer that this NestedInteger holds,
	// if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds,
	// if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;

	vector<int> flatten(vector<NestedInteger> &nestedList) 
	{
		// Write your code here
	}
};

