#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                         inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int preL, int preR,
                        vector<int>& inorder, int inL, int inR) {
        if (preL > preR)
            return nullptr;

        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);

        int k = inL;
        while (inorder[k] != rootVal)
            k++;

        int leftSize = k - inL;

        root->left =
            buildTree(preorder, preL + 1, preL + leftSize, inorder, inL, k - 1);

        root->right =
            buildTree(preorder, preL + leftSize + 1, preR, inorder, k + 1, inR);

        return root;
    }
};