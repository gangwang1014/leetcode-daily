#include <vector>

using namespace std;

/**
 * 核心思路：DFS / BFS 搜索。
 * 遍历整个网格，每当遇到 '1'（陆地）时，启动一次搜索，将与之相连的所有 '1'
 * 全部标记为'0'（沉没岛屿），同时岛屿计数加 1。
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count {};
        for (int i {}; i < grid.size(); ++i) {
            for (int j {}; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()
            || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
};