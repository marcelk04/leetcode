#include <iostream>
#include <vector>

class Solution {
public:
	int maxProfit(std::vector<int>& prices) {
		int max = INT_MIN, currentSum = 0;

		for (size_t i = 0; i < prices.size() - 1; ++i) {
			currentSum += prices[i + 1] - prices[i];

			max = std::max(max, currentSum);
			currentSum = std::max(0, currentSum);
		}

		return std::max(max, 0);
	}
};

int main() {
	std::vector<int> list1 = {7,1,5,3,6,4};
	std::vector<int> list2 = {7,6,4,3,1};

	Solution s;

	std::cout << s.maxProfit(list1) << '\n';
	std::cout << s.maxProfit(list2) << '\n';
}