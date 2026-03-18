#include <vector>

using namespace std;

/**
 * 从右上到左下查找, 相邻元素左侧较小, 下方较大, 如果当前元素大于目标, 则向左移动; 否则向下移动
 * 时间复杂度: O(m + n)
 *
 * 不能从左上到右下查找, 因为相邻元素右侧较大, 下方较大, 无法确定移动方向
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};
