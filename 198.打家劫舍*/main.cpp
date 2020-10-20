#include <iostream>
#include <vector>
using namespace std;

// 动态规划
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        auto n = nums.size();
//
//        if (n == 0)
//            return 0;
//
//        if (n == 1)
//            return nums[0];
//
//        auto tempVec = vector<int>(n, 0);
//        tempVec[0] = nums[0];
//        tempVec[1] = max(nums[0], nums[1]);
//
//        for (int i = 2; i < n; ++i) {
//            tempVec[i] = max(tempVec[i - 1], tempVec[i - 2] + nums[i]);
//        }
//
//        return tempVec[n - 1];
//    }
//};

// 动态规划 + 滚动数组
class Solution {
public:
    int rob(vector<int>& nums) {
        auto n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        auto first = nums[0];
        auto second = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            auto temp = second;
            second = max(second, first + nums[i]);
            first = temp;
        }

        return second;
    }
};

int main() {
    auto v = vector<int>();
    v.push_back(2);
    v.push_back(7);
    v.push_back(9);
    v.push_back(3);
    v.push_back(1);

    Solution s;
    auto r = s.rob(v);
    cout << r << endl;

    return 0;
}
