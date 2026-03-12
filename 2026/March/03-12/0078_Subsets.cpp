#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<int> path;

        dfs(ans, path, nums, 0);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& nums,
             int start) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);

            dfs(ans, path, nums, i + 1);

            path.pop_back();
        }
    }
};