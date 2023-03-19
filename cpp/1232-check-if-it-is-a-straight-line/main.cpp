#include <vector>
#include <algorithm>

class Solution
{
public:
	bool checkStraightLine(std::vector<std::vector<int>> &coordinates)
	{
		int xDiff = coordinates[1][0] - coordinates[0][0];
		int yDiff = coordinates[1][1] - coordinates[0][1];

		for (int i = 1; i < coordinates.size() - 1; ++i)
		{
			if (xDiff != 0 && yDiff != 0)
			{
				double xFactor = static_cast<double>(coordinates[i + 1][0] - coordinates[i][0]) / static_cast<double>(xDiff);
				double yFactor = static_cast<double>(coordinates[i + 1][1] - coordinates[i][1]) / static_cast<double>(yDiff);

				if (xFactor != yFactor)
					return false;
			}
			else if (xDiff == 0)
			{
				if (coordinates[i + 1][0] - coordinates[i][0] != xDiff)
					return false;
			}
			else if (yDiff == 0)
			{
				if (coordinates[i + 1][1] - coordinates[i][1] != yDiff)
					return false;
			}
		}

		return true;
	}
};