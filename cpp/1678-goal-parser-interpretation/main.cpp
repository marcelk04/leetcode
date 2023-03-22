#include <string>
#include <iostream>

class Solution
{
public:
	std::string interpret(std::string command)
	{
		std::string res;

		for (int i = 0; i < command.length(); ++i)
		{
			if (command[i] == 'G')
			{
				res += 'G';
			}
			else // command[i] == '('
			{
				if (command[i + 1] == ')')
				{
					res += 'o';
					++i;
				}
				else
				{
					res += "al";
					i += 3;
				}
			}
		}

		return res;
	}
};

int main()
{
	Solution s;

	std::cout << s.interpret("G()(al)") << '\n';
	std::cout << s.interpret("G()()()()(al)") << '\n';
	std::cout << s.interpret("(al)G(al)()()G") << '\n';
}