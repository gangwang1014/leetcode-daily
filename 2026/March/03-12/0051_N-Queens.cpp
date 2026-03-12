#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));
        dfs(n, 0);
        return ans;
    }

    void dfs(int n, int cur) {
        if (cur == n) {
            ans.push_back(board);
        }

        for (int i {}; i < n; ++i) {
            if (is_valid(n, cur, i)) {
                board[cur][i] = 'Q';
                dfs(n, cur + 1);
                board[cur][i] = '.';
            }
        }
    }

    bool is_valid(int n, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j <= n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};