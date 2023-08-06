#include <string>

class Solution
{
public:
	int romanToInt(std::string s)
	{
		int res = 0;
		int last = 0, temp = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'M')
				res += 1000 + last;
			else if (s[i] == 'D')
				res += 500 + last;
			else if (s[i] == 'C')
			{
				if (i < s.length() + 1 && (s[i + 1] == 'M' || s[i + 1] == 'D'))
				{
					temp = -100;
				}
				else
				{
					res += 100 + last;
				}
			}
			else if (s[i] == 'L')
				res += 50 + last;
			else if (s[i] == 'X')
			{
				if (i < s.length() + 1 && (s[i + 1] == 'C' || s[i + 1] == 'L'))
				{
					temp = -10;
				}
				else
				{
					res += 10 + last;
				}
			}
			else if (s[i] == 'V')
				res += 5 + last;
			else if (s[i] == 'I')
			{
				if (i < s.length() + 1 && (s[i + 1] == 'X' || s[i + 1] == 'V'))
				{
					temp = -1;
				}
				else
				{
					res += 1 + last;
				}
			}

			last = temp;
			temp = 0;
		}

		return res;
	}
};