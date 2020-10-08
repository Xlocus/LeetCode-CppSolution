#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSame(TreeNode *lt, TreeNode *rt){
        if (!lt && !rt)
            return true;

        if ((lt && !rt) || (!lt && rt))
            return false;

        if (lt->val != rt->val)
            return false;

        if (!isSame(lt->left, rt->right))
            return false;
        
        if (!isSame(lt->right, rt->left))
            return false;

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return this->isSame(root->left, root->right);
    }
};

int main() {
    TreeNode *t = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(4);
    TreeNode *t6 = new TreeNode(3);

    t->left = t1;
    t->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;

    Solution s;
    bool r = s.isSymmetric(t);
    cout << r << endl;

    return 0;
}
