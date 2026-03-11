#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0;
        int maxLen = 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i {}; i < n; ++i) {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxLen = 2;
                start = i;
            }
        }

        for (int l = { 3 }; l <= n; ++l) {
            for (int i {}; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    if (l > maxLen) {
                        maxLen = l;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};