#include <string>

class Solution
{
public:
	bool areAlmostEqual(std::string s1, std::string s2)
	{
		int diffCount = 0;
		int i1, i2;

		for (int i = 0; i < s1.length(); ++i)
		{
			if (s1[i] != s2[i])
			{
				if (diffCount == 0)
					i1 = i;
				else
					i2 = i;

				++diffCount;

				if (diffCount > 2)
					return false;
			}
		}

		if (diffCount == 0)
			return true;

		if (diffCount == 2)
		{
			return s1[i1] == s2[i2] && s1[i2] == s2[i1];
		}

		return false;
	}
};