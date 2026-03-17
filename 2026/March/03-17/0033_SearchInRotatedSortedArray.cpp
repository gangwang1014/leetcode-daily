// 33. Search in Rotated Sorted Array
// https://leetcode.cn/problems/search-in-rotated-sorted-array/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // left <= mid, 则 [left, mid] 是有序的
            if (nums[left] <= nums[mid]) {
                // target 在 [left, mid] 中
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // mid < right, 则 [mid, right] 是有序的
                if (nums[mid] < target && target <= nums[right]) {
                    // target 在 [mid, right] 中
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};