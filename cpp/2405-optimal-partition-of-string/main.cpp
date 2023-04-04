#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	int partitionString(std::string s)
	{
		int partitions = 1;
		std::vector<int> letters(26, 0);

		for (char c : s)
		{
			if (letters[c - 'a'] > 0) // letter is already within substring
			{
				partitions++;

				std::fill(letters.begin(), letters.end(), 0); // "create new substring"
			}

			++letters[c - 'a'];
		}

		return partitions;
	}
};

int main()
{
	Solution s;

	std::cout << s.partitionString("ababcbab") << '\n';
	std::cout << s.partitionString("ssssss") << '\n';
}