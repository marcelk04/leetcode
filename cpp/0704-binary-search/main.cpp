#include <vector>

class Solution
{
public:
	int search(std::vector<int> &nums, int target)
	{
		int min = 0, max = nums.size(), middle;

		while (min < max)
		{
			middle = (max - min) / 2 + min;

			if (nums[middle] == target)
			{
				return middle;
			}
			else if (nums[middle] < target)
			{
				min = middle + 1;
			}
			else
			{
				max = middle;
			}
		}

		return -1;
	}
};