// 875. Koko Eating Bananas
// https://leetcode.cn/problems/koko-eating-bananas/

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (canFinish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canFinish(vector<int>& piles, int k, int h) {
        int hours = 0;
        for (int pile : piles) {
            hours += ceil(1.0 * pile / k);
        }
        return hours <= h;
    }
};