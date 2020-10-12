#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归方式
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;

        if (!root->left && !root->right)
            return sum == root->val;

        return hasPathSum(root->left, sum - root->val) ||
                hasPathSum(root->right, sum - root->val);
    }
};

// 非递归方式
//class Solution {
//public:
//    bool hasPathSum(TreeNode* root, int sum) {
//        auto qNode = queue<TreeNode*>();
//        auto qVal = queue<int>();
//
//        if (!root)
//            return false;
//
//        TreeNode *p = root;
//        qNode.push(p);
//        qVal.push(p->val);
//
//        TreeNode *tempPtr;
//        int tempVal;
//
//        while (!qNode.empty()){
//            tempPtr = qNode.front();
//            qNode.pop();
//
//            tempVal = qVal.front();
//            qVal.pop();
//
//            if (tempPtr->left){
//                qNode.push(tempPtr->left);
//                qVal.push(tempVal + tempPtr->left->val);
//            }
//
//            if (tempPtr->right){
//                qNode.push(tempPtr->right);
//                qVal.push(tempVal + tempPtr->right->val);
//            }
//
//            if (!tempPtr->left && !tempPtr->right){
//                if (tempVal == sum)
//                    return true;
//            }
//        }
//
//        return false;
//    }
//};

int main() {
    auto t = new TreeNode(5);
    auto t1 = new TreeNode(4);
    auto t2 = new TreeNode(8);
    auto t3 = new TreeNode(11);
    auto t4 = new TreeNode(13);
    auto t5 = new TreeNode(4);
    auto t6 = new TreeNode(7);
    auto t7 = new TreeNode(2);
    auto t8 = new TreeNode(1);

    t->left = t1;
    t->right = t2;
    t1->left = t3;
    t3->left = t6;
    t3->right = t7;
    t2->left = t4;
    t2->right = t5;
    t5->right = t8;

    Solution s;
    auto n = 100;
    auto r = s.hasPathSum(t, n);
    cout << r << endl;

    return 0;
}
