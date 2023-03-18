#include <string>
#include <vector>

class Solution
{
public:
	bool isAnagram(std::string s, std::string t)
	{
		std::vector<int> counts(26, 0);

		for (const char c : s) {
			++counts[c - 'a'];
		}

		for (const char c : t) {
			--counts[c - 'a'];
		}

		for (const int count : counts) {
			if (count != 0) return false;
		}

		return true;
	}
};