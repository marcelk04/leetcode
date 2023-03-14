#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> map;

		for (size_t i = 0; i < nums.size(); ++i) {
			int t = target - nums[i];

			if (map.count(t) == 1) {
				return std::vector<int>({ map[t], static_cast<int>(i) });
			}

			map[nums[i]] = i;
		}

		return std::vector<int>();
	}
};

void print(const std::vector<int>& arr) {
	for (const auto e : arr) {
		std::cout << e << " ";
	}

	std::cout << '\n';
}

int main() {
	std::vector<int> list1 = {2,7,11,15};
	std::vector<int> list2 = {3,2,4};
	std::vector<int> list3 = {3,3};

	Solution s;

	print(s.twoSum(list1, 9));
	print(s.twoSum(list2, 6));
	print(s.twoSum(list3, 6));
}