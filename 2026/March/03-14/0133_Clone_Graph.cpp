#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited_;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        if (visited_.count(node)) {
            return visited_[node];
        }

        Node* cloneNode = new Node(node->val);
        visited_[node] = cloneNode;

        for (auto& neighbor : node->neighbors) {
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};