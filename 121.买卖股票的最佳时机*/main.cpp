#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto min_price = INT_MAX;
        auto max_profit = 0;

        for (auto price : prices) {
            max_profit = max(max_profit, price - min_price);
            min_price = min(price, min_price);
        }

        return max_profit;
    }
};

// 动态规划法
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        auto length = prices.size();
//
//        if (prices.empty())
//            return 0;
//
//        auto min_price = prices[0];
//        vector<int> dp (length, 0);
//
//        for (int i = 1; i < length; ++i) {
//            min_price = min(min_price, prices[i]);
//            dp[i] = max(dp[i - 1], prices[i] - min_price);
//        }
//
//        return dp[length - 1];
//    }
//};

int main() {
    auto v = vector<int>();
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);

    Solution s;
    auto r = s.maxProfit(v);
    cout << r << endl;
    return 0;
}
