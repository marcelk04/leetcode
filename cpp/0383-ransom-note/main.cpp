#include <string>
#include <iostream>
#include <unordered_set>

class Solution
{
public:
	bool canConstruct(std::string ransomNote, std::string magazine)
	{
		std::unordered_multiset<char> letters(magazine.begin(), magazine.end());

		for (const char c : ransomNote) {
			auto pos = letters.find(c);

			if (pos == letters.end()) return false;

			letters.erase(pos);
		}

		return true;
	}
};