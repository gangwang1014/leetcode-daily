#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::unordered_map<int, int> map(n);

        for (int i {}; i < n; i++) {
            int need = target - nums[i];
            if (map.count(need)) {
                return { map[need], i };
            }
            map.emplace(nums[i], i);
        }
        return {};
    }
};
