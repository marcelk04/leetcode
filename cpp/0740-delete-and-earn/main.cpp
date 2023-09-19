#include <vector>
#include <algorithm>
#include <cmath>

class Solution
{
public:
	int deleteAndEarn(std::vector<int> &nums)
	{
		std::sort(nums.begin(), nums.end());

		int n = nums.size();
		int i = 0;
		int x0 = 0, x1 = 0;
		int prevNum = -1;

		while (i < n)
		{
			int num = nums[i++];
			int sum = num;

			for (; i < n && nums[i] == num; i++)
			{
				sum += num;
			}

			int temp;
			if (num == prevNum + 1)
			{
				temp = std::max(x0 + sum, x1);
			}
			else
			{
				temp = std::max(x0 + sum, x1 + sum);
			}

			x0 = x1;
			x1 = temp;

			prevNum = num;
		}

		return x1;
	}
};