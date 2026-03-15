#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * dp[i] 表示凑出金额 i 所需最少硬币数
     *
     * dp[i] = min(dp[i], dp[i - coin] + 1)
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};