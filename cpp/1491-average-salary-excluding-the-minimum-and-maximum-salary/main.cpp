#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
	double average(std::vector<int>& salary) {
		int min = INT_MAX, max = INT_MIN, total = 0;

		for (const auto num : salary) {
			total += num;

			min = std::min(num, min);
			max = std::max(num, max);
		}

		total = total - min - max;

		return static_cast<double>(total) / static_cast<double>(salary.size() - 2);
	}
};

int main() {
	std::vector<int> list1 = {4000,3000,1000,2000};
	std::vector<int> list2 = {1000,2000,3000};

	Solution s;

	std::cout << s.average(list1) << '\n';
	std::cout << s.average(list2) << '\n';
}