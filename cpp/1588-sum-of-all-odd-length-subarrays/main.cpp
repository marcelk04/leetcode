#include <vector>

class Solution
{
public:
	int sumOddLengthSubarrays(std::vector<int> &arr)
	{
		int res = 0;

		for (int n = 1; n <= arr.size(); n += 2)
		{
			for (int i = 0; i <= arr.size() - n; ++i)
			{
				for (int j = i; j < i + n; ++j)
				{
					res += arr[j];
				}
			}
		}

		return res;
	}
};