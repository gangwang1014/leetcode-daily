#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;

        for (int x : nums) {
            left = max(left, x);
            right += x;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (can_split(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool can_split(vector<int>& nums, int k, int max_sum) {
        int count = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x > max_sum) {
                count++;
                sum = x;
            } else {
                sum += x;
            }
        }

        return count <= k;
    }
};

// class Solution {
// public:
//     int splitArray(vector<int>& nums, int m) {
//         int n = nums.size();
//         vector<long long> prefix(n + 1, 0);
//         for (int i = 0; i < n; i++)
//             prefix[i + 1] = prefix[i] + nums[i];

//         // dp[i][k] = 前 i 个元素分成 k 段时的最小最大子数组和
//         vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
//         dp[0][0] = 0;

//         // dp[i][1] = prefix[i]
//         for (int i = 1; i <= n; i++) {
//             dp[i][1] = prefix[i];
//         }

//         // 假设最后一段是 [j + 1 ... i]
//         // 那么
//         //      1. [0 ... j] 分成了 k - 1 段
//         //      2. [j + 1 ... i] 第 k 段
//         // dp[i][k] = min over j ( max(dp[j][k-1], prefix[i] - prefix[j]) )
//         for (int k = 2; k <= m; k++) {
//             for (int i = 1; i <= n; i++) {
//                 for (int j = 0; j < i; j++) {
//                     dp[i][k] = min(dp[i][k], max(dp[j][k - 1], prefix[i] - prefix[j]));
//                 }
//             }
//         }

//         return dp[n][m];
//     }
// };