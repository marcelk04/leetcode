#include <vector>
#include <unordered_set>

class Solution
{
public:
	bool checkSubbox(const std::vector<std::vector<char>> &board, int rowStart, int columnStart)
	{
		std::unordered_set<char> digits;

		for (int row = rowStart; row < rowStart + 3; ++row)
		{
			for (int column = columnStart; column < columnStart + 3; ++column)
			{
				if (board[row][column] == '.')
					continue;

				if (digits.count(board[row][column]) > 0)
					return false;

				digits.insert(board[row][column]);
			}
		}

		return true;
	}

	bool isValidSudoku(std::vector<std::vector<char>> &board)
	{
		for (int r = 0; r < 9; ++r)
		{
			std::unordered_set<char> digitsRow;
			std::unordered_set<char> digitsColumn;

			for (int c = 0; c < 9; ++c)
			{
				if (board[r][c] != '.')
				{
					if (digitsRow.count(board[r][c]) > 0)
						return false;

					digitsRow.insert(board[r][c]);
				}

				if (board[c][r] != '.')
				{
					if (digitsColumn.count(board[c][r]) > 0)
						return false;

					digitsColumn.insert(board[c][r]);
				}
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (!checkSubbox(board, i * 3, j * 3))
					return false;
			}
		}

		return true;
	}
};
