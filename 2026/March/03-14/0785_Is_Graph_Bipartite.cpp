#include <vector>

using namespace std;

/**
 *核心思路：
 * 染色法: 尝试用两种颜色（0和1）为所有节点染色，要求相邻节点的颜色必须不同。
 * 如果在染色过程中发现邻居已经被染成了和当前节点相同的颜色，则说明不是二分图。
 */

class Solution {
public:
    int RED = 0;
    int BLUE = 1;
    int UNCOLORED = -1;
    vector<int> color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, UNCOLORED);

        for (int i = 0; i < n; ++i) {
            if (color[i] == UNCOLORED) {
                if (!draw(graph, i, RED)) {
                    return false;
                }
            }
        }
        return true;
    
    }

    bool draw(vector<vector<int>>& graph, int node, int c) {
        color[node] = c;
        int col = (c == RED) ? BLUE : RED;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == UNCOLORED) {
                if (!draw(graph, neighbor, col)) {
                    return false;
                }
            } else if (color[neighbor] == c) {
                return false;
            }
        }
        return true;
    }
};