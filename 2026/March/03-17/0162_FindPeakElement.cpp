// 162. Find Peak Element
// https://leetcode.cn/problems/find-peak-element/

#include <vector>

using namespace std;

/**
 * 1. -oo | nums[0] < nums[1] < ... < nums[n-1]   | -oo nums[n - 1] 是峰值
 * 2. -oo | nums[0] > nums[1] > ... > nums[n-1]   | -oo nums[0] 是峰值
 * 3. -oo | nums[0] < nums[1] < ... > nums[i] < ... < nums[n-1]   | -oo nums[i] 是峰值
 * 4. -oo | nums[0] > nums[1] > ... < nums[i] > ... > nums[n-1]   | -oo nums[i] 是峰值
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};