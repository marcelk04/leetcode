#include <vector>

class Solution
{
public:
	int diagonalSum(std::vector<std::vector<int>> &mat)
	{
		int res = 0;

		for (int i = 0; i < mat.size(); ++i)
		{
			int secondary = mat.size() - i - 1;

			res += mat[i][i];

			if (i != secondary)
				res += mat[i][secondary];
		}

		return res;
	}
};