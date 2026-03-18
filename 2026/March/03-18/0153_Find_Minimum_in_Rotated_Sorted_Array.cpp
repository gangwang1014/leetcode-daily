#include <vector>

using namespace std;

/**
 * 旋转数组结构：
 * [nums[k], ..., nums[n-1], nums[0], ..., nums[k-1]]
 *
 * 性质：
 * 1. nums[k ... n-1] 递增（右段）
 * 2. nums[0 ... k-1] 递增（左段）
 * 3. 左段所有元素 > 右段所有元素
 *
 * 二分判断：
 * - 如果 nums[mid] > nums[right]
 *     说明 mid 在左段，最小值在右段 → left = mid + 1
 *
 * - 如果 nums[mid] <= nums[right]
 *     说明 mid 在右段，最小值在左侧（包含 mid）→ right = mid
 *
 * 本质：
 * 通过 nums[mid] 与 nums[right] 的比较，
 * 判断 mid 位于哪一段，从而缩小区间
 *
 * 旋转数组示例：
 *   / nums[n-1]
 *  /
 * / nums[k]
 * --------------------
 *      / nums[k-1]
 *     /
 *    / nums[0]
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
