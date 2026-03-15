#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 若 s1[i-1] == s2[j-1]：说明字符匹配，dp[i][j] = dp[i-1][j-1] + 1
     * 若不匹配：取左方或上方的最大值，dp[i][j] = max(dp[i-1][j],dp[i][j-1])
     */
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i { 1 }; i <= m; ++i) {
            for (int j { 1 }; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};