#include <string>
#include <vector>

class Solution
{
public:
	bool isAlienSorted(std::vector<std::string> &words, std::string order)
	{
		std::vector<int> orderVec(26);

		for (int i = 0; i < order.length(); ++i)
		{
			orderVec[order[i] - 'a'] = i;
		}

		for (int i = 0; i < words.size() - 1; ++i)
		{
			if (!compStrings(words[i], words[i + 1], orderVec))
				return false;
		}

		return true;
	}

	bool compStrings(std::string &s1, std::string &s2, std::vector<int> &order)
	{
		for (int i = 0; i < s1.length() && i < s2.length(); ++i)
		{
			int i1 = s1[i] - 'a', i2 = s2[i] - 'a';

			if (order[i1] < order[i2])
			{
				return true;
			}
			else if (order[i1] > order[i2])
			{
				return false;
			}
		}

		return s1.length() <= s2.length();
	}
};