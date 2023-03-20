#include <vector>

class Solution
{
public:
	void moveZeroes(std::vector<int> &nums)
	{
		int zeroPtr = 0, nonzeroPtr = 1;

		while (zeroPtr < nums.size() && nonzeroPtr < nums.size())
		{
			if (nums[zeroPtr] != 0)
			{
				++zeroPtr;
				nonzeroPtr = zeroPtr + 1;
			}
			else if (nums[nonzeroPtr] == 0)
			{
				++nonzeroPtr;
			}
			else
			{
				std::swap(nums[zeroPtr], nums[nonzeroPtr]);
			}
		}
	}
};