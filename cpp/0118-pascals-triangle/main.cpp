#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> generate(int numRows) {
		std::vector<std::vector<int>> res(numRows);

		res[0] = std::vector<int>({1}); // element at the top always 1

		for (int i = 1; i < numRows; ++i) {
			std::vector<int> v(i + 1); // ith row has i + 1 elements (starts from 0)

			for (int j = 0; j <= i; ++j) {
				if (j == 0 || j == i) { // first and last element in a row is always 1
					v[j] = 1;
				} else { // element is the sum of both elements above it
					v[j] = res[i - 1][j - 1] + res[i - 1][j];
				}
			}

			res[i] = v; // store row in vector
		}

		return res;
	}
};

void print(const std::vector<std::vector<int>>& arr) {
	for (const auto& a : arr) {
		for (const auto e : a) {
			std::cout << e << ' ';
		}

		std::cout << ',';
	}

	std::cout << '\n';
}

int main() {
	Solution s;

	print(s.generate(5));
	print(s.generate(1));
}