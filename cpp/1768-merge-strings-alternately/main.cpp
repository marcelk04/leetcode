#include <string>

class Solution
{
public:
	std::string mergeAlternately(std::string word1, std::string word2)
	{
		int i1 = 0, i2 = 0;
		std::string res(word1.length() + word2.length(), 'a');

		while (i1 < word1.length() && i2 < word2.length())
		{
			if (i1 == i2)
			{
				res[i1 + i2] = word1[i1];
				++i1;
			}
			else
			{
				res[i1 + i2] = word2[i2];
				++i2;
			}
		}

		for (; i1 < word1.length(); ++i1)
		{
			res[i1 + i2] = word1[i1];
		}

		for (; i2 < word2.length(); ++i2)
		{
			res[i1 + i2] = word2[i2];
		}

		return res;
	}
};