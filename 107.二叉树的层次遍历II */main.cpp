#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto result = vector<vector<int>>();

        if (!root)
            return result;

        queue<TreeNode*> q;
        int levelNum = 0;
        int tempNum;
        TreeNode *tempPtr;
        vector<int> tempList;

        q.push(root);
        levelNum += 1;

        while (!q.empty()){
            tempList.clear();
            tempNum = levelNum;
            levelNum = 0;

            for (int i = 0; i < tempNum; ++i) {
                tempPtr = q.front();
                q.pop();
                tempList.push_back(tempPtr->val);

                if (tempPtr->left){
                    q.push(tempPtr->left);
                    levelNum += 1;
                }

                if (tempPtr->right){
                    q.push(tempPtr->right);
                    levelNum += 1;
                }
            }

            result.push_back(tempList);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    auto *t = new TreeNode(3);
    auto *t1 = new TreeNode(9);
    auto *t2 = new TreeNode(20);
    auto *t3 = new TreeNode(15);
    auto *t4 = new TreeNode(7);

    t->left = t1;
    t->right = t2;
    t2->left = t3;
    t2->right = t4;

    Solution s;
    vector<vector<int>> r = s.levelOrderBottom(t);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
            cout << r[i][j] << endl;
        }
    }

    return 0;
}
