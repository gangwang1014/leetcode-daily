// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left { -1 };
        int right { -1 };

        left = find_left(nums, target);
        right = find_right(nums, target);

        if (left >= nums.size() || nums[left] != target)
            return { -1, -1 };

        return { left, right };
    }

private:
    int find_left(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int find_right(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};