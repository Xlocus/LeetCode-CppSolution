#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;

        if (!root->left && root->right)
            return maxDepth(root->right) + 1;

        if (root->left && !root->right)
            return maxDepth(root->left) + 1;

        int d1 = maxDepth(root->left);
        int d2 = maxDepth(root->right);

        return (d1 > d2 ? d1 + 1 : d2 + 1);
    }
};

int main() {
    TreeNode *t0 = new TreeNode(3);
    TreeNode *t1 = new TreeNode(9);
    TreeNode *t2 = new TreeNode(20);
    TreeNode *t3 = new TreeNode(15);
    TreeNode *t4 = new TreeNode(7);

    t0->left = t1;
    t0->right = t2;
    t2->left = t3;
    t2->right = t4;

    Solution s;
    int r = s.maxDepth(t0);
    cout << r << endl;

    return 0;
}
