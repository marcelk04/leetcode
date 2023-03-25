#include <vector>
#include <algorithm>

class Solution
{
public:
	int oneBits(int num)
	{
		int res = 0;

		while (num)
		{
			res += num & 1;
			num >>= 1;
		}

		return res;
	}

	std::vector<int> sortByBits(std::vector<int> &arr)
	{
		std::sort(arr.begin(), arr.end(), [&](int num1, int num2)
				  {
            int leftBits = oneBits(num1), rightBits = oneBits(num2);
            
            if (leftBits == rightBits)
                return num1 < num2;

            return leftBits < rightBits; });

		return arr;
	}
};