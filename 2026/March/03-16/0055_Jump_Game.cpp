#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reachable = 0;

        for (int i {}; i < n; ++i) {
            if (i > max_reachable) {
                return false; 
            }
            max_reachable = max(max_reachable, i + nums[i]);
        }
        return true;
    }
};