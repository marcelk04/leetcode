#include <string>
#include <vector>
#include <unordered_set>

class Solution
{
public:
	char findTheDifference(std::string s, std::string t)
	{
		std::vector<int> chars(26, 0);

		for (const char c : s)
		{
			chars[c - 'a']++;
		}

		for (const char c : t)
		{
			chars[c - 'a']--;

			if (chars[c - 'a'] < 0)
				return c;
		}

		return '\0';

		/*
		std::unordered_multiset<char> chars(t.begin(), t.end());

		for (const char c : s) {
			auto it = chars.find(c);
			chars.erase(it);
		}

		return *chars.begin();
		*/
	}
};