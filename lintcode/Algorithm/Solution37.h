#pragma once
class CSolution37
{
public:
	CSolution37();
	~CSolution37();

	/**
	* @param number: A 3-digit number.
	* @return: Reversed number.
	*/
	int reverseInteger(int number) 
	{

		// write your code here
		int Pos3 = number / 100;
		int Pos2 = (number - Pos3 * 100) / 10;
		int Pos = (number - Pos3 * 100 - Pos2 * 10);

		return Pos * 100 + Pos2 * 10 + Pos3;
	}
};

