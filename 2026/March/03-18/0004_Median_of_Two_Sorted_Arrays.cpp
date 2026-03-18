#include <vector>

using namespace std;

/**
 * nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i]
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0;
        int right = m; // i 的范围是 [0, m] 不是 [0, m - 1], 因为 i 可以取 0 或 m 来表示 nums1 的全部元素都在左侧或右侧

        int len = m + n;

        while (left <= right) {
            int i = left + ((right - left) >> 1);
            int j = ((len + 1) >> 1) - i;

            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];

            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) {
                if (len & 1) {
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};


