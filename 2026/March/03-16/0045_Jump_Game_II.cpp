#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest {};
        int end {};
        int jumps {};

        for (int i {}; i < nums.size(); ++i) {
            if (farthest >= i) {
                farthest = max(farthest, i + nums[i]);

                if (i == end) {
                    end = farthest;
                    ++jumps;
                }
            }
        }
        return jumps;
    }
};