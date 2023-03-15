#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::unordered_multiset<int> set;

		for (const auto num : nums1) {
			set.insert(num);
		}

		std::vector<int> res;

		for (const auto num : nums2) {
			auto e = set.find(num);

			if (e == set.end()) continue;

			res.push_back(*e);

			set.erase(e);
		}

		return res;
	}
};

void print(const std::vector<int>& arr) {
	for (const auto e : arr) {
		std::cout << e << ' ';
	}

	std::cout << '\n';
}

int main() {
	std::vector<int> nums1_1 = {1,2,2,1};
	std::vector<int> nums2_1 = {2,2};
	std::vector<int> nums1_2 = {4,9,5};
	std::vector<int> nums2_2 = {9,4,9,8,4};

	Solution s;

	print(s.intersect(nums1_1, nums2_1));
	print(s.intersect(nums1_2, nums2_2));
}