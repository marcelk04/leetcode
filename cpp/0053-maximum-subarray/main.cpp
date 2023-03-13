#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
	int maxSubArray(std::vector<int>& nums) {
		int maxSum = INT_MIN, currentSum = 0;

		for (size_t i = 0; i < nums.size(); ++i) {
			currentSum += nums[i];

			maxSum = std::max(currentSum, maxSum);
			currentSum = std::max(currentSum, 0);
		}

		return maxSum;
	}
};

int main() {
	std::vector<int> list1 = {-2,1-3,4,-1,2,1,-5,4};
	std::vector<int> list2 = {1};
	std::vector<int> list3 = {5,4,-1,7,8};

	Solution s;

	std::cout << s.maxSubArray(list1) << '\n';
	std::cout << s.maxSubArray(list2) << '\n';
	std::cout << s.maxSubArray(list3) << '\n';
}