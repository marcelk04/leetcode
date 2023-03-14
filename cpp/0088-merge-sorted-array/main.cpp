#include <iostream>
#include <vector>

class Solution {
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1;

		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				std::swap(nums1[i + j + 1], nums1[i]);
				--i;
			} else {
				std::swap(nums1[i + j + 1], nums2[j]);
				--j;
			}
		}

		while (j >= 0) {
			std::swap(nums1[i + j + 1], nums2[j]);
			--j;
		}

		while (i >= 0) {
			std::swap(nums1[i + j + 1], nums1[i]);
			--i;
		}
	}
};

void print(const std::vector<int>& arr) {
	for (const auto e : arr) {
		std::cout << e << ' ';
	}

	std::cout << '\n';
}

int main() {
	std::vector<int> nums1_1 = {1,2,3,0,0,0};
	std::vector<int> nums2_1 = {2,5,6};
	std::vector<int> nums1_2 = {1};
	std::vector<int> nums2_2 = {};
	std::vector<int> nums1_3 = {0};
	std::vector<int> nums2_3 = {1};

	Solution s;

	s.merge(nums1_1, 3, nums2_1, 3);
	s.merge(nums1_2, 1, nums2_2, 0);
	s.merge(nums1_3, 0, nums2_3, 1);

	print(nums1_1);
	print(nums1_2);
	print(nums1_3);

}