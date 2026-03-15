#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (queMin_.empty() || num <= queMin_.top()) {
            queMin_.push(num);
            if (queMax_.size() + 1 < queMin_.size()) {
                queMax_.push(queMin_.top());
                queMin_.pop();
            }
        } else {
            queMax_.push(num);
            if (queMax_.size() > queMin_.size()) {
                queMin_.push(queMax_.top());
                queMax_.pop();
            }
        }
    }

    double findMedian() {
        if (queMin_.size() > queMax_.size()) {
            return queMin_.top();
        }
        return (queMin_.top() + queMax_.top()) / 2.0;
    }

private:
    priority_queue<int, vector<int>, less<int>> queMin_;
    priority_queue<int, vector<int>, greater<int>> queMax_;
};