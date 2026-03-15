#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// class Solution {
// public:
//     bool has_cycle(int u, vector<vector<int>>& graph, vector<int>& state) {
//
//         if (state[u] == 1) return true;
//         if (state[u] == 2) return false;
//
//         state[u] = 1;
//
//         for (int v : graph[u]) {
//             if (has_cycle(v, graph, state))
//                 return true;
//         }
//
//         state[u] = 2;
//         return false;
//     }
//
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//
//         vector<vector<int>> graph(numCourses);
//
//         for (auto& p : prerequisites) {
//             int a = p[0];
//             int b = p[1];
//             graph[b].push_back(a);
//         }
//
//         vector<int> state(numCourses, 0);
//
//         for (int i = 0; i < numCourses; i++) {
//             if (has_cycle(i, graph, state))
//                 return false;
//         }
//
//         return true;
//     }
// };
//

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        vector<int> ingree(numCourses, 0);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];
            map[a].push_back(b);
            ingree[b]++;
        }
        queue<int> q;
        int cnt {};
        for (int i = 0; i < numCourses; ++i) {
            if (ingree[i] == 0) {
                q.push(i);
                ++cnt;
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vector<int> nodes = map[u];

            for (auto& node : nodes) {
                if (--ingree[node] == 0) {
                    q.push(node);
                    ++cnt;
                }
            }
        }
        return cnt == numCourses;
    }
};
