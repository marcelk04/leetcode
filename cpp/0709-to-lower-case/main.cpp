#include <string>

class Solution
{
public:
	std::string toLowerCase(std::string s)
	{
		for (char &c : s)
		{
			if (c >= 'A' && c <= 'Z')
			{
				c = static_cast<char>(c - 'A' + 'a');
			}
		}

		return s;
	}
};