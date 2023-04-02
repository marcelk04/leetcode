#include <vector>
#include <unordered_map>
#include <algorithm>

// WARNING: BAD CODE

class Solution
{
public:
	std::vector<int> successfulPairs(std::vector<int> &spells, std::vector<int> &potions, long long success)
	{
		std::sort(potions.begin(), potions.end());

		std::vector<int> res(spells.size(), 0);
		std::unordered_map<int, int> pairs;

		for (int i = 0; i < spells.size(); ++i)
		{
			if (pairs.count(spells[i]) == 0)
			{
				int begin = 0, end = potions.size(), idx;

				while (begin < end)
				{
					idx = (begin + end) / 2;

					long long strength = (long)spells[i] * (long)potions[idx];

					if (strength == success)
					{
						break;
					}
					else if (strength < success)
					{
						begin = idx + 1;
					}
					else
					{
						end = idx;
					}
				}

				while (idx > 0 && (long)spells[i] * (long)potions[idx - 1] >= success)
				{
					idx--;
				}

				if (idx < potions.size() && (long)spells[i] * (long)potions[idx] < success)
				{
					idx++;
				}

				pairs[spells[i]] = potions.size() - idx;
				res[i] = potions.size() - idx;
			}
			else
			{
				res[i] = pairs[spells[i]];
			}
		}

		return res;
	}
};