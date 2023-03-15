#include <iostream>

class Solution {
public:
	int countOdds(int low, int high) {
		int odds = (high - low) / 2;

		if (low % 2 || high % 2) odds++;

		return odds;
	}
};

int main() {
	Solution s;

	std::cout << s.countOdds(3, 7) << '\n';
	std::cout << s.countOdds(8, 10) << '\n';
}