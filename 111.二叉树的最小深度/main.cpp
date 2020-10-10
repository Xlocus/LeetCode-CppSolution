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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;

        if (root->left && !root->right)
            return minDepth(root->left) + 1;

        if (!root->left && root->right)
            return minDepth(root->right) + 1;

        auto d1 = minDepth(root->left);
        auto d2 = minDepth(root->right);

        return (d1 < d2 ? d1 + 1 : d2 + 1);
    }
};

int main() {
    auto *t0 = new TreeNode(3);
    auto *t1 = new TreeNode(9);
    auto *t2 = new TreeNode(20);
    auto *t3 = new TreeNode(15);
    auto *t4 = new TreeNode(7);

    t0->left = t1;
    t0->right = t2;
    t2->left = t3;
    t2->right = t4;

    Solution s;
    int r = s.minDepth(t0);
    cout << r << endl;
    return 0;
}
