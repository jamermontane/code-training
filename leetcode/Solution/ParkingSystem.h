#pragma once
class ParkingSystem
{
public:
	ParkingSystem(int big, int medium, int small)
	{
		_bigPositions = big;
		_mediumPositions = medium;
		_smallPositions = small;
	}
	~ParkingSystem();

	bool addCar(int carType)
	{
		switch (carType)
		{
		case 1:
			if (_bigPositions > 0)
			{
				_bigPositions--;
				return true;
			}
			else
			{
				return false;
			}
		case 2:
			if (_mediumPositions > 0)
			{
				_mediumPositions--;
				return true;
			}
			else
				return false;
		case 3:
			if (_smallPositions > 0)
			{
				_smallPositions--;
				return true;
			}
			else return false;
		default:
			return false;
		}
	}

private:
	int _bigPositions;
	int _mediumPositions;
	int _smallPositions;
};

