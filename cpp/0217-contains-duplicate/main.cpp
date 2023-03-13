#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		std::unordered_set<int> s;

		for (const auto num : nums) {
			if (s.find(num) != s.end()) return true;

			s.insert(num);
		}

		return false;
	}
};

int main() {
	std::vector<int> list1 = {1,2,3,1};
	std::vector<int> list2 = {1,2,3,4};
	std::vector<int> list3 = {1,1,1,3,3,4,3,2,4,2};

	Solution s;

	std::cout << s.containsDuplicate(list1) << '\n';
	std::cout << s.containsDuplicate(list2) << '\n';
	std::cout << s.containsDuplicate(list3) << '\n';
}