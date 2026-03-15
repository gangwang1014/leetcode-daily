#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int num: nums) {
            map[num]++;
        }

        auto comp = [](const pair<int, int>& m, const pair<int, int>& n) {
            return m.second > n.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);

        for (auto& it : map) {
            q.push(it);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};