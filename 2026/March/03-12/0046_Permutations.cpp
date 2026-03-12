#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        dfs(ans, path, used, nums);

        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<bool>& used, vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i {}; i < nums.size(); ++i) {
            if (used[i]) continue;

            path.push_back(nums[i]);
            used[i] = true;
            dfs(ans, path, used, nums);

            used[i] = false;
            path.pop_back();
        }
    }
};