#include <vector>

class Solution
{
public:
	bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
	{
		for (int i = 0; n > 0 && i < flowerbed.size(); ++i)
		{
			if (flowerbed[i] == 0)
			{
				bool canPlace = true;

				if (i > 0 && flowerbed[i - 1] == 1)
					canPlace = false;

				if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1)
					canPlace = false;

				if (canPlace)
				{
					flowerbed[i] = 1;
					--n;
				}
			}
		}

		return n == 0;
	}
};