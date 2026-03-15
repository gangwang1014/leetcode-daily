#include <queue>
#include <utility>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> minHeap;
//         for (int num : nums) {
//             minHeap.push(num);
//             if (minHeap.size() > k) {
//                 minHeap.pop();
//             }
//         }
//         return minHeap.top();
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];

        int i { l };

        for (int j { l }; j < r; ++j) {
            if (nums[j] <= pivot) {
                swap(nums[j], nums[i]);
                ++i;
            }
        }

        swap(nums[i], nums[r]);
        return i;
    }

    // int quickSelect(vector<int>& nums, int l, int r, int k) {
    //     if (l == r) {
    //         return nums[l];
    //     }

    //     int pivotIndex = partition(nums, l, r);

    //     if (pivotIndex == k) {
    //         return nums[pivotIndex];
    //     } else if (pivotIndex > k) {
    //         return quickSelect(nums, l, pivotIndex - 1, k);
    //     } else {
    //         return quickSelect(nums, pivotIndex + 1, r, k);
    //     }
    // }

    int quick_select(vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            return nums[k];
        }

        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do
                i++;
            while (nums[i] < partition);
            do
                j--;
            while (nums[j] > partition);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        if (k <= j)
            return quick_select(nums, l, j, k);
        else
            return quick_select(nums, j + 1, r, k);
    }
};