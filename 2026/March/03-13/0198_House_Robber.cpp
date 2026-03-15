#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> dp(n + 1, 0);

//         for (int i {}; i < n; ++i) {
//             if (i == 0) dp[i] = nums[i];
//             else if (i == 1) dp[i] = max(nums[i], nums[i - 1]);
//             else{
//                 dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//             }
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int two_houses_ago = 0;
        int one_house_ago = 0;

        for (int num : nums) {
            int current = max(one_house_ago, two_houses_ago + num);
            two_houses_ago = one_house_ago;
            one_house_ago = current;
        }

        return one_house_ago;
    }
};