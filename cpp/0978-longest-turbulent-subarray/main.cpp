#include <vector>
#include <iostream>

class Solution {
public:
	int maxTurbulenceSize(std::vector<int>& arr) {
		if (arr.size() == 0 || arr.size() == 1) return arr.size();

		int maxSize = 1, currentLength = 1;
		bool hasToBeGreater, hasToBeSmaller;

		for (size_t i = 0; i < arr.size() - 1; ++i) {
			if ((currentLength == 1 && arr[i] != arr[i + 1]) || 
				(arr[i] > arr[i + 1] && hasToBeGreater) || 
				(arr[i] < arr[i + 1] && hasToBeSmaller)) {
				currentLength++;
				
				hasToBeGreater = arr[i] < arr[i + 1];
				hasToBeSmaller = arr[i] > arr[i + 1];
			} else {
				maxSize = std::max(maxSize, currentLength);
				
				if (arr[i] == arr[i + 1]) {
					currentLength = 1;
				} else {
					currentLength = 2;

					hasToBeGreater = arr[i] < arr[i + 1];
					hasToBeSmaller = arr[i] > arr[i + 1];
				}
			}
		}

		return std::max(maxSize, currentLength);
	}
};

int main() {
	std::vector<int> list1 = {9,4,2,10,7,8,8,1,9};
	std::vector<int> list2 = {4,8,12,16};
	std::vector<int> list3 = {100};
	std::vector<int> list4 = {9,9};
	std::vector<int> list5 = {0,8,45,88,48,68,28,55,17,24};

	Solution s;

	std::cout << s.maxTurbulenceSize(list1) << '\n';
	std::cout << s.maxTurbulenceSize(list2) << '\n';
	std::cout << s.maxTurbulenceSize(list3) << '\n';
	std::cout << s.maxTurbulenceSize(list4) << '\n';
	std::cout << s.maxTurbulenceSize(list5) << '\n';
}