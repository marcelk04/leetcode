#include <vector>
#include <algorithm>

class Solution
{
public:
	std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x)
	{
		std::sort(arr.begin(), arr.end(), [&](int left, int right)
				  {
            int a = std::abs(left - x);
            int b = std::abs(right - x);

            if (a == b) 
                return left < right;
            
            return a < b; });

		auto res = std::vector<int>(arr.begin(), arr.begin() + k);

		std::sort(res.begin(), res.end());

		return res;
	}
};