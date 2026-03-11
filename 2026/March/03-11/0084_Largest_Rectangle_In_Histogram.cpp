#include <algorithm>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int ans {};

        stack<int> stk;

        for (int i {}; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();

                int left = stk.empty() ? -1 : stk.top();

                int width = i - left - 1;

                ans = max(ans, h * width);
            }
            stk.push(i);
        }

        return ans;
    }
};