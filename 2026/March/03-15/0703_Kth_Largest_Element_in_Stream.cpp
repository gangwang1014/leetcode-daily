#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        pq_.push(val);
        if (pq_.size() > k_) {
            pq_.pop();
        }
        return pq_.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> pq_;
    int k_;
};