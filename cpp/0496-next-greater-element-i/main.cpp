#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
	{
		std::unordered_map<int, int> map;
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

		for (int num : nums2)
		{
			while (!pq.empty() && pq.top() < num)
			{
				map[pq.top()] = num;

				pq.pop();
			}

			pq.push(num);
		}

		for (; !pq.empty(); pq.pop())
		{
			map[pq.top()] = -1;
		}

		std::vector<int> res;

		for (const auto num : nums1)
		{
			res.push_back(map[num]);
		}

		return res;
	}
};

void print(const std::vector<int> &arr)
{
	for (const auto e : arr)
	{
		std::cout << e << ' ';
	}

	std::cout << '\n';
}

int main()
{
	std::vector<int> list1 = {4, 1, 2};
	std::vector<int> list2 = {1, 3, 4, 2};

	Solution s;

	std::cout << "<\n";
	print(s.nextGreaterElement(list1, list2));
	std::cout << ">\n";
}