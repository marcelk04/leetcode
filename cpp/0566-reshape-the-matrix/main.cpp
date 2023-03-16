#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c) return mat;

        std::vector<std::vector<int>> res(r, std::vector<int>(c, 0));

        int oldRow = 0, oldColumn = 0;

        for (int row = 0; row < r; ++row) {
            for (int column = 0; column < c; ++column) {
                res[row][column] = mat[oldRow][oldColumn];

                ++oldColumn;

                if (oldColumn >= mat[0].size()) {
                    oldColumn = 0;
                    ++oldRow;
                }
            }
        }

        return res;
    }
};