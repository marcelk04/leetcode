#include <string>
#include <iostream>
#include <cmath>

class Solution {
public:
	int myAtoi(std::string s) {
		size_t index = s.find_first_not_of(" ");

		if (index >= s.length()) return 0;

		int sign = 1;

		if (s[index] == '+') {
			++index;
		} else if (s[index] == '-') {
			++index;
			sign = -1;
		}

		if (index >= s.length()) return 0;
		if (s[index] < '0' || s[index] > '9') return 0;

		long long res = 0;

		for ( ; index < s.length(); ++index) {
			if (s[index] < '0' || s[index] > '9') break;

			res = res * 10 + s[index] - 48;

			if (sign == 1 && res > 0x7fffffffLL) {
				return 0x7fffffff;
			} else if (sign == -1 && res > 0x80000000LL) {
				return static_cast<int>(0x80000000 * -1);
			}
		}

		return static_cast<int>(sign * res);
	}
};

int main() {
	Solution s;
	std::cout << s.myAtoi("42") << '\n';
	std::cout << s.myAtoi("    -42") << '\n';
	std::cout << s.myAtoi("4193 with words") << '\n';
	std::cout << s.myAtoi("words and 987") << '\n';
	std::cout << s.myAtoi(".1") << '\n';
	std::cout << s.myAtoi("99999999999999") << '\n';
	std::cout << s.myAtoi("-99999999999999") << '\n';
}