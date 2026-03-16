#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt {};

        int i{}, j{};

        while(i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            }else {
                j++;
            }
        }
        return cnt;
    }
};