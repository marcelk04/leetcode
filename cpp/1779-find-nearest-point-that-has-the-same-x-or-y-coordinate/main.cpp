#include <vector>

class Solution
{
public:
	int nearestValidPoint(int x, int y, std::vector<std::vector<int>> &points)
	{
		int res = -1;
		int minDist = INT_MAX;

		for (int i = 0; i < points.size(); ++i)
		{
			int dist;

			if (x == points[i][0])
			{ // same x coordinate
				dist = std::abs(y - points[i][1]);
			}
			else if (y == points[i][1])
			{ // same y coordinate
				dist = std::abs(x - points[i][0]);
			}
			else
			{
				continue;
			}

			if (dist < minDist)
			{
				minDist = dist;
				res = i;
			}
		}

		return res;
	}
};