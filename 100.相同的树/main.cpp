#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void InOrder(TreeNode* p, vector<int> &nums) {
        if (p->left == nullptr && p->right == nullptr)
        {
            nums.push_back(p->val);
            return;
        }

        nums.push_back(p->val);

        if (p->left != nullptr)
            InOrder(p->left, nums);
        else
            nums.push_back(INT_MIN);

        if (p->right != nullptr)
            InOrder(p->right, nums);
        else
            nums.push_back(INT_MIN);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;

        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;

        vector<int> n1;
        vector<int> n2;

        this->InOrder(p, n1);
        this->InOrder(q, n2);

        if (n1.size() != n2.size())
            return false;

        for (int i = 0; i < n1.size(); ++i) {
            if (n1[i] != n2[i])
                return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    TreeNode *tree = new TreeNode(5);
    TreeNode *tree2 = new TreeNode(4);
    TreeNode *tree3 = new TreeNode(1);
    TreeNode *tree4 = new TreeNode(1);
    TreeNode *tree5 = new TreeNode(4);
    TreeNode *tree6 = new TreeNode(2);
    TreeNode *tree7 = new TreeNode(2);
    tree->left = tree2;
    tree->right = tree3;
    tree2->right = tree4;
    tree3->right = tree5;
    tree4->left = tree6;
    tree5->left = tree7;

    TreeNode *t = new TreeNode(5);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(2);
    TreeNode *t7 = new TreeNode(2);
    t->left = t2;
    t->right = t3;
    t2->left = t4;
    t3->left = t5;
    t4->right = t6;
    t5->right = t7;

    bool r = s.isSameTree(t, tree);
    cout << r << endl;
    return 0;
}
