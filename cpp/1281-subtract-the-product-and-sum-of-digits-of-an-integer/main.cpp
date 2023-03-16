#include <iostream>
#include <unordered_set>
#include <numeric>
#include <functional>

class Solution
{
public:
	int subtractProductAndSum(int n)
	{
		std::unordered_multiset<int> digits; // save digits in unordered multiset

		while (n)
		{
			digits.insert(n % 10); // insert last digit of number
			n /= 10;			   // shift to the right
		}

		int sum = std::accumulate(digits.begin(), digits.end(), 0);								// calculate sum
		int product = std::accumulate(digits.begin(), digits.end(), 1, std::multiplies<int>()); // calculate product

		return product - sum; // return result
	}
};

int main()
{
	Solution s;

	std::cout << s.subtractProductAndSum(234) << '\n';
	std::cout << s.subtractProductAndSum(4421) << '\n';
}