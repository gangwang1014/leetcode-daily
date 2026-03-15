#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        vector<int> ingree(numCourses, 0);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            map[b].push_back(a);
            ingree[a]++;
        }
        queue<int> q;

        vector<int> ans;

        for (int i = 0; i < numCourses; ++i) {
            if (ingree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& node : map[u]) {
                if (--ingree[node] == 0) {
                    q.push(node);
                    ans.push_back(node);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int> {};
    }
};