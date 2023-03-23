#include <string>

class Solution
{
public:
	std::string freqAlphabets(std::string s)
	{
		std::string res;

		for (int i = 0; i < s.length(); ++i)
		{
			if (i < s.length() - 2 && s[i + 2] == '#')
			{
				int num = std::stoi(s.substr(i, 2)) - 1;
				res += static_cast<char>('a' + num);
				i += 2;
			}
			else
			{
				res += static_cast<char>(s[i] + 48);
			}
		}

		return res;
	}
};