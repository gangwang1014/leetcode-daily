#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        const auto comp = [&](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({ i, 0 });
        }

        while (k-- && !pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();
            res.push_back({ nums1[i], nums2[j] });

            if (j + 1 < nums2.size()) {
                pq.push({ i, j + 1 });
            }
        }
        return res;
    }
};