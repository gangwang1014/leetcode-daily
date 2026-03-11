#include <stack>
using namespace std;

class MyQueue {
public:
    void push(int x) {
        in_stk.push(x);
    }

    int pop() {
        move();
        int v = out_stk.top();
        out_stk.pop();
        return v;
    }

    int peek() {
        move();
        return out_stk.top();
    }

    bool empty() {
        return in_stk.empty() && out_stk.empty();
    }

private:
    stack<int> in_stk;
    stack<int> out_stk;

    /**
     * @brief
     * 它体现了一种非常有意思的算法哲学：延迟工作（lazy evaluation）。
     * 系统只有在“必须知道队首是谁”时才整理数据。很多高性能系统都用这个思想，
     * 比如缓存、数据库 buffer、甚至 CPU pipeline。先堆着，真的需要时再整理。
     *
     */
    void move() {
        if (!out_stk.empty()) return;

        while (!in_stk.empty()) {
            out_stk.push(in_stk.top());
            in_stk.pop();
        }
    }
};