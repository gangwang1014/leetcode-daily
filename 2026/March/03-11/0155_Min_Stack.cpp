#include <stack>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

// class MinStack {
// public:
//     MinStack() {
//         }

//     void push(int val) {
//         stack_.push(val);
//         set_.insert(val);
//     }

//     void pop() {
//         auto v = stack_.top();
//         stack_.pop();
//         set_.erase(set_.find(v));
//     }

//     int top() {
//         return stack_.top();
//     }

//     int getMin() {
//         return *set_.begin();
//     }

// private:
//     stack<int> stack_;
//     multiset<int> set_;
// };

class MinStack {
public:
    void push(int val) {
        data.push(val);

        if (mins.empty())
            mins.push(val);
        else
            mins.push(min(val, mins.top()));
    }

    void pop() {
        data.pop();
        mins.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return mins.top();
    }

private:
    stack<int> data;
    stack<int> mins;
};