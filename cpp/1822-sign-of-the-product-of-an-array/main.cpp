#include <vector>

class Solution
{
public:
	int arraySign(std::vector<int> &nums)
	{
		int sign = 1;

		for (const auto num : nums)
		{
			if (num == 0) // if a number is zero, the whole product will be zero
				return 0;

			if (num < 0) // if a number is less than zero, the sign will be flipped
				sign *= -1;
		}

		return sign;
	}
};