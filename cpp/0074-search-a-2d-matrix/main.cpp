#include <vector>

class Solution
{
public:
	int elementAtIndex(const std::vector<std::vector<int>> &matrix, int index)
	{
		int row = index / matrix[0].size();
		int col = index % matrix[0].size();

		return matrix[row][col];
	}

	bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target, int begin, int end)
	{
		if (end <= begin)
			return false;

		int middle = begin + (end - begin) / 2;
		int middleElement = elementAtIndex(matrix, middle);

		if (target == middleElement)
			return true;

		if (target < middleElement)
		{
			return searchMatrix(matrix, target, begin, middle);
		}
		else
		{
			return searchMatrix(matrix, target, middle + 1, end);
		}
	}

	bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
	{
		return searchMatrix(matrix, target, 0, matrix.size() * matrix[0].size());
	}
};
