#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
	int firstUniqChar(std::string s)
	{
		std::vector<bool> repeating(26, false);

		for (int i = 0; i < s.length(); ++i)
		{
			if (repeating[s[i] - 'a'])
				continue;

			for (int j = i + 1; j < s.length(); ++j)
			{
				if (s[j] == s[i]) {
					repeating[s[i] - 'a'] = true;
					break;
				}
			}

			if (!repeating[s[i] - 'a']) return i;
		}

		return -1;
	}
};

int main() {
	Solution s;

	std::cout << s.firstUniqChar("leetcode") << '\n';
	std::cout << s.firstUniqChar("loveleetcode") << '\n';
	std::cout << s.firstUniqChar("aabb") << '\n';
}