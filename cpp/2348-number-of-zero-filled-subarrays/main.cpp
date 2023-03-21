#include <vector>

class Solution
{
public:
	long long zeroFilledSubarray(std::vector<int> &nums)
	{
		long long res = 0;
		int currSubLen = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 0)
			{
				++currSubLen;
				res += currSubLen;
			}
			else
			{
				currSubLen = 0;
			}
		}

		return res;
	}
};