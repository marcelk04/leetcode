#include <vector>
#include <numeric>

class Solution
{
public:
	int maximumWealth(std::vector<std::vector<int>> &accounts)
	{
		int max = INT_MIN;

		for (const auto &banks : accounts)
		{
			int sum = std::accumulate(banks.begin(), banks.end(), 0);

			max = std::max(max, sum);
		}

		return max;
	}
};
