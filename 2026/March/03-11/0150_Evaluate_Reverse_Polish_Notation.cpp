#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> funcs_map {
            { "+", [](int a, int b) -> int { return a + b; } },
            { "-", [](int a, int b) -> int { return a - b; } },
            { "*", [](int a, int b) -> int { return a * b; } },
            { "/", [](int a, int b) -> int { return a / b; } },
        };

        stack<int> stk;

        for (auto& token : tokens) {
            // is options
            if (funcs_map.count(token)) {
                auto second = stk.top();
                stk.pop();
                auto first = stk.top();
                stk.pop();
                stk.push(funcs_map[token](first, second));
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};