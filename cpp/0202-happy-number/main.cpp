#include <iostream>
#include <unordered_set>
#include <queue>

class Solution
{
public:
	int squareDigits(int n) {
		int res = 0;

		while (n) {
			int digit = n % 10;
			res += digit * digit;
			n /= 10;
		}

		return res;
	}

	bool isHappy(int n)
	{
		if (n == 1) return true;

		std::unordered_set<int> seen;

		seen.insert(n);

		int next = squareDigits(n);

		while (seen.count(next) == 0) {
			if (next == 1) return true;

			seen.insert(next);

			next = squareDigits(next);
		}

		return false;
	}
};

int main() {
	Solution s;

	std::cout << s.isHappy(19) << '\n';
	std::cout << s.isHappy(2) << '\n';
}