#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/**
 * 若 word1[i-1] == word2[j-1]， dp[i][j] = dp[i-1][j-1]。
 * 否则，取三种操作中的最小值 + 1
 *      插入：dp[i][j-1]
 *      删除：dp[i-1][j]
 *      替换：$dp[i-1][j-1]
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i { 1 }; i <= m; ++i) {
            for (int j { 1 }; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1])
                        + 1;
                }
            }
        }
        return dp[m][n];
    }
};