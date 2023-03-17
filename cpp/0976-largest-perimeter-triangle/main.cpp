#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	bool isNonzeroTriangle(int largest, int side1, int side2)
	{
		return side1 + side2 > largest;
	}

	int largestPerimeter(std::vector<int> &nums)
	{
		std::sort(nums.begin(), nums.end());

		int n = nums.size();

		int largest = nums[n - 1];
		int side1 = nums[n - 2];
		int side2 = nums[n - 3];

		int i = n - 4;
		while (i >= 0 && !isNonzeroTriangle(largest, side1, side2))
		{
			largest = side1;
			side1 = side2;
			side2 = nums[i--];
		}

		if (isNonzeroTriangle(largest, side1, side2))
			return largest + side1 + side2;

		return 0;
	}
};

int main()
{
	std::vector<int> list1 = {2, 1, 2};
	std::vector<int> list2 = {1, 2, 1, 10};

	Solution s;

	std::cout << s.largestPerimeter(list1) << '\n';
	std::cout << s.largestPerimeter(list2) << '\n';
}