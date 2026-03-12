#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (dfs(board, used, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& used, int i,
             int j, string& word, int k) {
        if (k == word.size()) return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        if (used[i][j] || board[i][j] != word[k]) return false;

        used[i][j] = true;

        bool found = dfs(board, used, i + 1, j, word, k + 1) 
        || dfs(board, used, i - 1, j, word, k + 1) 
        || dfs(board, used, i, j + 1, word, k + 1) 
        || dfs(board, used, i, j - 1, word, k + 1);

        used[i][j] = false;

        return found;
    }
};