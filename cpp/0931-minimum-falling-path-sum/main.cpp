#include <vector>
#include <algorithm>

class Solution
{
public:
	int minFallingPathSum(std::vector<std::vector<int>> &matrix)
	{
		int n = matrix.size();

		// return trivial solution incase of 1x1 matrix
		if (n == 1)
		{
			return matrix[0][0];
		}

		// iterate over every row in the matrix except for the first one
		for (int i = 1; i < n; i++)
		{
			// add path sums for sides
			matrix[i][0] += std::min(matrix[i - 1][0], matrix[i - 1][1]);
			matrix[i][n - 1] += std::min(matrix[i - 1][n - 2], matrix[i - 1][n - 1]);

			// find minimum path sums for the other elements in the row
			for (int j = 1; j < n - 1; j++)
			{
				matrix[i][j] += std::min(matrix[i - 1][j - 1], std::min(matrix[i - 1][j], matrix[i - 1][j + 1]));
			}
		}

		// return the minimum path sum
		return *std::min_element(matrix[n - 1].begin(), matrix[n - 1].end());
	}
};